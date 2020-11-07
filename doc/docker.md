[TOC]
# docker

## 使用国内的源
创建或修改 /etc/docker/daemon.json 文件，修改为如下形式

`
vi /etc/docker/daemon.json
{
    "registry-mirrors": ["http://hub-mirror.c.163.com"]
}
`

systemctl restart docker.service
国内加速地址有：

Docker中国区官方镜像
https://registry.docker-cn.com

网易
http://hub-mirror.c.163.com
ustc 
https://docker.mirrors.ustc.edu.cn
中国科技大学
https://docker.mirrors.ustc.edu.cn
阿里云容器  服务
https://cr.console.aliyun.com/
首页点击“创建我的容器镜像”  得到一个专属的镜像加速地址，类似于“https://1234abcd.mirror.aliyuncs.com”



## 学习材料

