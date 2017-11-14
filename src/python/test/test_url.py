#!/usr/bin/python

import re
import urllib2

def test(url):
    request = urllib2.Request(url)
    response = urllib2.urlopen(request)
    
    data = response.read()
    pattern = '<span class="a">.*<b>sitecn</b>'
    #pattern = re.compile(pattern)
    url_list = []
    result = re.findall(pattern, data)
    if result:
        for url in result:
            url = url[16:-14]
            url_list.append(url)
    url_set = set(url_list)
    url_list = list(url_set)
    for url in url_list:

        print url + '\n'
    #for i in result.group():
     #   print i
    #data = pattern.match(response.read())
def getUrl():
    url = "http://www.gufen138.com/?q=inurl%3A%2Fsitecn%2F&p="
    for i in range(1,4):
        test(url+str(i)) 


if __name__ == "__main__":
    getUrl()
    #test()