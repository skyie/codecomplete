#/usr/bin/env python
#coding = utf-8

import eventlet
from eventlet.green import urllib2

urls = ["http://www.baidu.com",
        "http://www.sogo.com"]

class EventletTest(object):
    
    def __init__(self):
        self.start_loop()
    
    def loop_fun(self):
        print("loop fun")
    
    def inter_loop(self):
        print("inter loop start\n")
        pools = eventlet.GreenPool(size=8)
        while True:
            pools.spawn_n(self.loop_fun)
    
    def start_loop(self):
        print("start loop\n")
        while True:
            eventlet.spawn_n(self.inter_loop)
            



def fetch(url):
    return urllib2.urlopen(url).read()

def start_fetch():
    pool = eventlet.GreenPool()
    for body in pool.imap(fetch, urls):
        print("got body %u\n content %s\n", len(body), body)
if __name__ == '__main__':
    #test = EventletTest()
    start_fetch()