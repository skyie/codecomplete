#!/usr/bin/env python
# coding=utf-8

from flask import Flask, redirect, url_for, render_template

# flask实例程序

app = Flask(__name__)

# ------ route 路由规则，默认路由的都是GET方法 ----------
@app.route('/')
def index():
    return 'This is index!'


@app.route('/version')
def version():
    return 'v1.0'

# ------变量规则----------
# http:// localhost:5000/hello/boys, boys将被当做参数传给name
@app.route('/hello/<name>')
def hello(name):
    return 'Hello {}'.format(name)


@app.route('/get_port/<int:port>')
def get_port(port):
    return "Get port {}".format(port)


@app.route('/get_float/<float:number>')
def get_float(number):
    return "Get float {}".format(number)

# ------ redirect和 url用法-------------------
@app.route('/admin')
def hello_admin():
    return 'Hello Admin'


@app.route('/guest/<guest>')
def hello_guest(guest):
    return 'Hello %s as Guest' % guest


@app.route('/user/<name>')
def hello_user(name):
    if name == 'admin':
        return redirect(url_for('hello_admin'))
    else:
        return redirect(url_for('hello_guest', guest=name))

# ------- 模板用法--------------
@app.route('/template')
def template():
    # 往模板中传入的数据
    my_str = 'Hello Word'
    my_int = 10
    my_array = [3, 4, 2, 1, 7, 9]
    my_dict = {
        'name': 'xiaoming',
        'age': 18
    }
    # render_template会从目录templates下找对应的模板文件，因此需要创建一个templates文件夹，将模板文件放到templates下
    return render_template('hello.html',
                           my_str=my_str,
                           my_int=my_int,
                           my_array=my_array,
                           my_dict=my_dict
                           )


if __name__ == '__main__':
    app.run(host='0.0.0.0')
