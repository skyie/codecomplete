from wsgiref.simple_server import make_server

def application(environ, start_reponse):
    for item in environ:
        print(environ[item])
    start_reponse('200 OK', [('Content_type', 'text/html')])
    return '<h1>Hello world!</h1>'

def server_run():
    httpd = make_server('127.0.0.1', 9000, application)
    print('http start on 9000...')
    httpd.serve_forever()
if __name__ == '__main__':
    server_run()