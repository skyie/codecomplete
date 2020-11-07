#!/usr/bin/python
import thread
import time
import sys
import gevent
def print_time(name, delay):
    count = 0
    while count < 5:
        sleep(delay)
        count += 1
        print("%s : %s", name, time.ctime(time.time()))
    
def thread_run():

    try:
        thread.start_new_thread(print_time, ('thread1', 2,))
        thread.start_new_thread(print_time, ('thread2', 5,))
    except:
        print("routine fail")
        sys.exit(1)

def gevent_fun(count):
    for i in range(count):
        print("%s %d" % (gevent.getcurrent()), i)
if __name__ == "__main__":
    thread_run()