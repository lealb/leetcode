# -*- coding: utf-8 -*-
"""
Created on Tue Nov  5 18:47:22 2019

@author: leal
"""

import requests
from bs4 import BeautifulSoup
import time


def download(url, encoding="gbk"):
    """
     download page
     return soup
    """
    res = requests.get(url)
    res.encoding = "gbk"
    # 防止线程池 SSL错误
    time.sleep(0.01)
    return BeautifulSoup(res.text, features="lxml") if res.status_code == 200 else None\



def get_download_url(url, book_name=None, encoding="gbk"):
    soup = download(url)
    try:
        if soup.find("li", attrs={'class': 'baidu'}):
            book_url = soup.find(
                "li", attrs={'class': 'baidu'}).find('a').get('href')
        elif soup.find("ul", attrs={"class": "ul_Address"}).find('li'):
            book_url = soup.find("ul", attrs={"class": "ul_Address"}).find(
                'li').find('a').get('href')
        else:
            book_url = ""
        book_url = book_url if len(book_url) < 255 else "S"+book_url[:250]
        content = soup.find('div', id='soft-intro')
        p_content = content.find_all('p')
        if not p_content:
            summary = content.text
            catalog = None
        else:
            if len(p_content) > 1:
                summary, catalog = p_content[0].text, p_content[1].text
            else:
                summary, catalog = p_content[0].text, None
        img_src = content.find('img').get(
            'src') if content.find('img') else None
        return url, book_url, book_name, img_src, summary, catalog
    except Exception as e:
        print("[ERROR]get_download_url: ", url, e)


def parse_content(soup, book_type):
    jb51 = "https://www.jb51.net"
    # url=base_url+str(i)+".html"

    result = []
    download_info = []
    try:
        if soup.select("ul#list_ul_more") == []:
            book_lists = soup.find(
                "div", attrs={"class": "sbox"}).find_all("dl")
            for d in book_lists:
                book_name = d.find("dt").text
                book_url = d.find("a").get("href")
                book_size = None
                update_date = d.find("dd", attrs={"class": "info"}).contents[1]
                book_desc = d.find("dd", attrs={"class": "preview"}).text
                download_info.append(get_download_url(
                    jb51+book_url, book_name=book_name))
                result.append((book_name, book_url, book_type,
                               book_size, update_date, book_desc))
        else:
            book_lists = soup.select("ul#list_ul_more")[0].find_all('li')
            for li in book_lists:
                p = li.find_all('p')
                book_name = p[0].text
                book_url = p[0].find('a').get('href')
                book_size = p[1].find_all('span')[1].contents[1]
                update_date = p[1].find_all('span')[2].contents[1]
                book_desc = p[-1].text
                # 爬取书本相关下载地址
                download_info.append(get_download_url(
                    jb51+book_url, book_name=book_name))
                result.append((book_name, book_url, book_type,
                               book_size, update_date, book_desc))

        yield result, download_info
    except Exception as e:
        print(soup, e)


def get_content(index_url, book_type, page=100):
    jb51 = "https://www.jb51.net"
    base_url = jb51+index_url
    for i in range(1, page):
        url = base_url+str(i)+".html"
        soup = download(url)
        if not soup:

            break
        result = []
        download_info = []
        try:
            if soup.select("ul#list_ul_more") == []:
                book_lists = soup.find(
                    "div", attrs={"class": "sbox"}).find_all("dl")
                for d in book_lists:
                    book_name = d.find("dt").text
                    book_url = d.find("a").get("href")
                    book_size = None
                    update_date = d.find(
                        "dd", attrs={"class": "info"}).contents[1]
                    book_desc = d.find("dd", attrs={"class": "preview"}).text
                    download_info.append(get_download_url(
                        jb51+book_url, book_name=book_name))
                    result.append((book_name, book_url, book_type,
                                   book_size, update_date, book_desc))
            else:
                book_lists = soup.select("ul#list_ul_more")[0].find_all('li')
                for li in book_lists:
                    p = li.find_all('p')
                    book_name = p[0].text
                    book_url = p[0].find('a').get('href')
                    book_size = p[1].find_all('span')[1].contents[1]
                    update_date = p[1].find_all('span')[2].contents[1]
                    book_desc = p[-1].text
                    # 爬取书本相关下载地址
                    download_info.append(get_download_url(
                        jb51+book_url, book_name=book_name))
                    result.append((book_name, book_url, book_type,
                                   book_size, update_date, book_desc))

            yield result, download_info
        except Exception as e:
            print(url, e)


def save_mysql(data, insert_sql):
    import pymysql
    config = {
        'host': '127.0.0.1',
        'user': 'root',
        'password': 'mysql520',
        'database': 'leal'
    }
    db = pymysql.connect(**config)
    cursor = db.cursor()
    #insert_sql="INSERT INTO book_info(book_name,base_url,book_type,book_size,update_date,book_desc) VALUES(%s,%s,%s,%s,%s,%s)"
    cursor.executemany(insert_sql, data)
    db.commit()
    cursor.close()
    db.close()


def main():
    sql = [
        "INSERT INTO book_info(book_name,base_url,book_type,book_size,update_date,book_desc) VALUES(%s,%s,%s,%s,%s,%s)",
        "INSERT INTO book_download_info(book_url,download_url,book_name,img_src,book_summary,book_catalog) VALUES(%s,%s,%s,%s,%s,%s)"
    ]
    books = {
        "indexs": [
            '/books/list477_',
            '/books/list478_',
            '/books/list479_',
            '/books/list480_',
            '/books/list575_',
            '/books/list976_',
            '/books/list977_',
            '/books/list152_',
            '/books/list211_',
            '/books/list572_',
            '/books/list749_',
            '/books/list577_',
            '/books/list567_',
            '/books/list476_',
            '/books/list640_',
            '/books/list630_',
            '/books/list509_'],
        "types": ['程序基础',
                  'VB 书籍',
                  'Delphi',
                  'PowerBuilder',
                  'Flash/ActionScript',
                  'powershell',
                  'shell电子书',
                  'java电子书',
                  'C/C++/C# ',
                  'Android',
                  'IOS',
                  'Ruby电子书',
                  'perl',
                  'Python电子书',
                  'matlab',
                  '汇编语言',
                  '编程其它']
    }
    for i in range(len(books["indexs"])):
        print(books["indexs"][i], books["types"][i])
        for data in get_content(books["indexs"][i], books["types"][i]):
            try:
                save_mysql(data[1], sql[1])
                # save_mysql(data)
            except Exception as e:
                print(e, data)


if __name__ == "__main__":
    # print(save_mysql)
    # main()
    data = parse_content(
        download("https://www.jb51.net/books/list509_36.html"), "编程其它")
    for d in data:
        print(d[1])
        #save_mysql(d[1], "INSERT INTO book_download_info(book_url,download_url,book_name,img_src,book_summary,book_catalog) VALUES(%s,%s,%s,%s,%s,%s)")
