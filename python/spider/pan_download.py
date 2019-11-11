# -*- coding: utf-8 -*-
"""
Created on Thu Nov  7 11:01:35 2019
    百度云自动保存
@author: leal
"""
import json
import re
#import smtplib
import time
import requests

from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.keys import Keys


class BaiduDownload():

    def __init__(self, bduss, stoken, bdstoken, password):
        # 这里的bdstoken是url的参数，在百度云随便操作看一下就可以了,貌似对身份验证没有影响
        # bduss和stoken都是百度下的cookie
        self.bdstoken = bdstoken
        self.bduss = bduss
        self.stoken = stoken
        # 网盘的密码
        self.password = password
        chrome_options = Options()
        chrome_options.add_argument('--headless')
        chrome_options.add_argument('--disable-gpu')
        # 这里的--no-sandbox针对的是Linux的云主机，如果不加可能无法启动，至少博主启动不了
        # 如果是使用windows，就安装谷歌浏览器，并找到安装路径下的启动程序
        # 如果是Linux就有点麻烦，必须经过一些配置
        # 两者都需要下载谷歌驱动
        chrome_options.add_argument("--no-sandbox")
        # chrome_options.binary_location = 'C:\Program Files (x86)\Google\Chrome\Application\chrome.exe'
        # self.driver = webdriver.Chrome(chrome_options=chrome_options)
        chrome_options.binary_location = '/opt/google/chrome/chrome'
        self.driver = webdriver.Chrome(
            executable_path='/opt/google/chrome/chromedriver', chrome_options=chrome_options)

    def init_head(self, bdclnd):
        self.headers = {
            'Accept': '*/*',
            'Accept-Encoding': 'gzip, deflate, br',
            'Accept-Language': 'zh-CN,zh;q=0.8',
            'Connection': 'keep-alive',
            'Content-Length': '161',
            'Content-Type': 'application/x-www-form-urlencoded; charset=UTF-8',
            # 这里如果是链接需要密码，则需要多加一个叫BDCLND的cookie，不需要密码则不用
            # STOKEN，BDUSS都可以直接用浏览器里面的cookie
            'Cookie': 'BDCLND=%s;BDUSS=%s;STOKEN=%s' % (bdclnd, self.bduss, self.stoken),
            'Host': 'pan.baidu.com',
            'Origin': 'https://pan.baidu.com',
            'Referer': 'https://pan.baidu.com/s/1mjI3AEs',
            # 可以直接在浏览器的开发者模式下找自己User-Agent
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36'
                          ' (KHTML, like Gecko) Chrome/64.0.3282.140 '
                          'Safari/537.36 Edge/17.17134',
            'X-Requested-With': 'XMLHttpRequest',
        }

    def get_file_info(self, url):
        # 使用sleep是因为ajax是异步加载，防止页面没有完全加载
        self.driver.get(url)
        time.sleep(1)
        self.driver.get(url)
        # 输入网盘密码框,这里直接取input框的第一个
        elem = self.driver.find_elements_by_tag_name('input')[0]
        # 模拟输入
        elem.send_keys(self.password)
        # 模拟回车
        elem.send_keys(Keys.ENTER)
        time.sleep(3)
        # 初始化header，并得到'BDCLND'这个cookie
        self.init_head(self.driver.get_cookie('BDCLND')['value'])

        # 元素解析，代码全部来自于他人
        script_list = self.driver.find_elements_by_xpath("//body/script")
        inner_html = script_list[-1].get_attribute("innerHTML")

        pattern = 'yunData.SHARE_ID = "(.*?)"[\s\S]*yunData.SHARE_UK = "(.*?)"[\s\S]*yunData.FILEINFO = (.*?);[\s\S]*'
        # [\s\S]*可以匹配包括换行的所有字符,\s表示空格，\S表示非空格字符
        srch_ob = re.search(pattern, inner_html)

        share_id = srch_ob.group(1)
        share_uk = srch_ob.group(2)

        file_info_jsls = json.loads(srch_ob.group(3))
        path_list_str = u'['
        for file_info in file_info_jsls:
            path_list_str += u'"' + file_info['path'] + u'",'

        path_list_str = path_list_str[:-1]
        path_list_str += u']'

        return share_id, share_uk, path_list_str

    def transfer(self, share_id, uk, filelist_str, path_t_save):
            #share_id和uk都要通过解析得到, filelist_str为自己一开始设置的保存位置
            # 注意，这里由于可以自动创建文件夹，所以保证了文件夹一定存在
            # 如果文件夹不存在，直接保存汇报errno:2的错误
        # 通用参数
        ondup = "newcopy"
        _async = "1"
        channel = "chunlei"
        clienttype = "0"
        web = "1"
        app_id = "250528"
        # 博主使用自己浏览器上的好像没什么影响
        logid = "MTUyODI4ODUxNjk0NjAuODAxMTA1MDc2ODE4Njg0Mw=="
        # 保存文件的链接
        url_trans = "https://pan.baidu.com/share/transfer?shareid=%s" \
                    "&from=%s" \
                    "&ondup=%s" \
                    "&async=%s" \
                    "&bdstoken=%s" \
                    "&channel=%s" \
                    "&clienttype=%s" \
                    "&web=%s" \
                    "&app_id=%s" \
                    "&logid=%s&clienttype=0" % (
                        share_id, uk, ondup, _async, self.bdstoken, channel, clienttype, web, app_id, logid)

        # 创建文件夹得请求正文
        # 注意在浏览器看到得是url编码格式
        create_floder = {
            # 不知道是什么，大部分情况为空
            'block_list': '[]',
            'isdir': '1',
            # 保存的位置，创建文件夹
            'path': path_t_save
        }
        # 创建文件夹的链接
        url_create = 'https://pan.baidu.com/api/create?a=commit' \
                     '&channel=chunlei' \
                     '&web=1' \
                     '&app_id=250528' \
                     '&bdstoken=%s' \
                     '&logid=%s' \
                     '&clienttype=0' % (self.bdstoken, logid)
        response = requests.post(
            url_create, data=create_floder, headers=self.headers)
        print(response.content)

        # 保存文件的请求正文
        form_data = {
            'filelist': filelist_str,
            'path': path_t_save,
        }
        response = requests.post(
            url_trans, data=form_data, headers=self.headers)
        print(response.content)

        jsob = json.loads(response.content)

        if "errno" in jsob:
            return jsob["errno"]
        else:
            return None


if __name__ == "__main__":
    BAIDUID="1BC79D2744093978613C6079C9A41D66:FG=1"
    BDCLND="lKLU9KSNbpwPrQlbsCeJvnK8dzAh9oAW"
    BDUSS="1hKMnVVYkJITkpjZE5DejlKbVlZNS1NTGlNZlZFdG41TWRJV01sdlJ1TVpQdXRkRUFBQUFBJCQAAAAAAAAAAAEAAAAnkJ3OwO62q9TAtcTAz7OyAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABmxw10ZscNdR"
    
    pass
