import requests
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import re
import json

if __name__ == "__main__":
    # 005911 - 广发双擎升级  2018-11-02
    # 002974 - 广发信息技术  2016-07-06
    # 004851 - 广发医疗
    # 320007 - 诺安混合
    # 001071 - 华安媒体
    # 001104 - 华安新丝路
    # 005176 - 富国精准医疗
    # 161033 - 富国中证智能汽车
    # 001508 - 富国新动力
    # 519005 - 海富通
    # 501058 - 汇添富新能源
    # 519674 - 银河创新
    # 007301 - 国联安半导体
    # 001938 - 中欧时代先锋
    # 004616 - 中欧电子信息
    # 007491 - 南方信息创新
    # 003956 - 南方现代教育
    # 005919 - 天弘中证
    # 161725 - 招商中证白
    # 160222 - 国泰食品
    fundCode = '161033'
    pageIndex = 1
    url = 'http://api.fund.eastmoney.com/f10/lsjz'

    # 参数化访问链接，以dict方式存储
    params = {
        'callback': 'jQuery18307633215694564663_1548321266367',
        'fundCode': fundCode,
        'pageIndex': pageIndex,
        'pageSize': 10,
    }
    # 存储cookie内容
    cookie = 'EMFUND1=null; EMFUND2=null; EMFUND3=null; EMFUND4=null; EMFUND5=null; EMFUND6=null; EMFUND7=null; EMFUND8=null; EMFUND0=null; EMFUND9=01-24 17:11:50@#$%u957F%u4FE1%u5229%u5E7F%u6DF7%u5408A@%23%24519961; st_pvi=27838598767214; st_si=11887649835514'
    # 装饰头文件
    headers = {
        # 'Cookie': cookie,
        'Host': 'api.fund.eastmoney.com',
        'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_2) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36',
        'Referer': 'http://fundf10.eastmoney.com/jjjz_%s.html' % fundCode,
    }
    res = requests.get(url=url, headers=headers, params=params)  # 发送请求

    print(res.text)
    
    text = re.findall('\((.*?)\)', res.text)[0]  # 提取dict
    info = json.loads(text)
    #print(info)
    LSJZList = info['Data']['LSJZList']  # 获取历史净值数据
    # TotalCount = json.loads(text)['TotalCount']  # 转化为dict
    LSJZ = pd.DataFrame(LSJZList)  # 转化为DataFrame格式
    # LSJZ['fundCode'] = fundCode  # 新增一列fundCode
    # print(LSJZ.columns)
    """
    Index(['FSRQ', 'DWJZ', 'LJJZ', 'SDATE', 'ACTUALSYI', 'NAVTYPE', 'JZZZL',
       'SGZT', 'SHZT', 'FHFCZ', 'FHFCBZ', 'DTYPE', 'FHSP', 'fundCode'],
      dtype='object')
    """
    #
    # pd.set_option('display.max_columns', None)
    # print(LSJZ[["FSRQ","DWJZ","LJJZ","JZZZL"]])
    data = LSJZ[["FSRQ", "DWJZ", "LJJZ", "JZZZL"]
                ].sort_values(by='FSRQ', axis=0)

    # plt.xlabel('Numbers',fontsize=14)
    # plot.xaxis.set_major_formatter(mdates.DateFormatter("%Y-%m-%d"))

    data[['FSRQ']] = data[['FSRQ']].apply(pd.to_datetime)
    print(data['FSRQ'][0])
    data[["DWJZ", "LJJZ", "JZZZL"]] = data[[
        "DWJZ", "LJJZ", "JZZZL"]].apply(pd.to_numeric)
    fig = plt.figure()
    ax = fig.add_subplot(1, 1, 1)
    # def on_press(event):
    #    print("my position:" ,event.button,event.xdata, event.ydata)
    sns.set_style("whitegrid")
    ax.plot(data["FSRQ"], data["DWJZ"])
    # fig.canvas.mpl_connect('button_press_event', on_press)
    for label in ax.xaxis.get_ticklabels():
        label.set_rotation(45)
    # plt.show()
