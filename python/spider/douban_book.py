import requests
from bs4 import BeautifulSoup

if __name__ == "__main__":
    
    url="https://book.douban.com/subject/26609422/"
    user_agent="Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/51.0.2704.103 Safari/537.36"
    headers={"User-Agent":user_agent}
    html=requests.get(url,headers=headers)
    soup=BeautifulSoup(html)
    body=soup.find(id="wapper")
    book_name=body.find("h1").text
    img_url=body.find(id="mainpic").find('a').img.get('src')
    book_name=body.find(id="mainpic").find('a').img.get('alt')
    #info
  