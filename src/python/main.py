#!/usr/bin/python
#from twisted.internet import reactor
import traceback

def hello():
    print "hello!"
    traceback.print_stack()


def test():
    from twisted.internet import reactor
    reactor.callWhenRunning(hello)
    reactor.run()



if __name__ == '__main__':
    test()



