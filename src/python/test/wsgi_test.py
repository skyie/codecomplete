#!/usr/bin/env python
#coding utf-8
import eventlet
from eventlet import wsgi

def print_dict(dict):
    for key in dict.keys():
        print("%s: %s\n" % (key, dict[key]))
def hello_world(env, start_response):
    print_dict(env)
    if env['PATH_INFO'] != '/':
        start_response('404 not found', [('Content-type', 'text/plain')])
        return ['Not found!\r\n']
    start_response('200 OK', [('Content-type', 'text/plain')])
    return ['Hello world']
    
    
def wsgi_server():
    wsgi.server(eventlet.listen(('', 8080)), hello_world)
    
if __name__ == '__main__':
    wsgi_server()
    
