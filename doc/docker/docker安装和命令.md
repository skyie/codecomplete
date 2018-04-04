# docker 

## docker安装
ubuntu安装
    apt install docker.io


## docker命令
参考：
http://www.runoob.com/docker # 简单入门教程

docker命令教程：
http://www.runoob.com/docker/docker-run-command.html






查找镜像
```
docker seach <name>
```
拉取镜像
```
docker pull <name>  # search查找到的镜像
```

创建镜像


端口映射
```
docker run -d -P training/webapp python app.py
    -P 端口映射到本机的随机端口
docker run -d -p 5000:5000 training/webapp python app.py
    -p 指定端口映射到本机的5000
docker run -d -p 127.0.0.1:5000:5000/udp training/webapp python app.py
    映射到127.0.0.1的5000 使用udp协议
查看端口绑定情况：
    docker port <name/容器ID>  # name是docker ps中name一项中显示的

```
启动容器
```

查看容器
docker ps
root@aStor-9047:~# docker ps 
CONTAINER ID        IMAGE               COMMAND             CREATED             STATUS              PORTS                     NAMES
b1673a624b21        training/webapp     "python app.py"     5 seconds ago       Up 4 seconds        0.0.0.0:32768->5000/tcp   silly_boyd


```

使用镜像ubuntu以交互模式启动一个容器,在容器内执行/bin/bash命令
```
语法
    docker run -it <image name>
eg
    docker run -it ubuntu
```



显示容器内的输出
```
语法
    docker logs [OPTIONS] CONTAINER
    -f 相当于tail -f 
eg：
    docker logs -f mynginx
```




### 遇到的错误
1. 拉取镜像失败：
```
root@aStor-9047:~# docker pull ceph/deamon
Using default tag: latest
Error response from daemon: repository ceph/deamon not found: does not exist or no pull access


```

配置daocloud镜像加速，这个是对docker hub的一个镜像缓存，提供国内访问的
在DaoCloud注册并登录。
在登录后的页面(https://dashboard.daocloud.io/),点击“加速器”标签，根据新弹出的页面中“配置 Docker 加速器”信息，更改自己的 Docker 配置文件，然后重启Docker，使之生效。
注意：此时，从“配置 Docker 加速器”信息中，我们其实已经得到一个免费的docker镜像地址，类似于“http://abcd1234.m.daocloud.io”
执行
curl -sSL https://get.daocloud.io/daotools/set_mirror.sh | sh -s http://54a727d3.m.daocloud.io
自动生成了/etc/docker/daemon.json docker启动文件，然后systemctl restart docker
注意：上面这个链接是我注册后生成的链接



