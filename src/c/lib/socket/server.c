#include "common.h"

#if 0
server_t* g_server = NULL;

#define SERVER_UNIX_PREFIX  "/tmp/server_unix_"

int32_t server_unix_init(int32_t* fd)
{
    assert(fd);
    *fd = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (*fd < 0) {
        LOG_ERROR("init unix socket fail,%s!\n", strerrno(errno));
        return -1;
    }
    struct sockaddr_un addr;
    memset(&addr, 0, sizeof(struct sockaddr_in));
    addr.sun_family = AF_UNIX;
    strncpy(addr.path, SERVER_UNIX_PREFIX"test", sizeof(addr.path) - 1);
    
    if (bind(*fd, (struct sockaddr*)&addr, sizeof(struct sockadr_in))) {
        LOG_ERROR("bind fd %u error,%s\n", *fd, strerror(errno));
        return -1;
    }
    listen(*fd, 10);
}

int32_t server_init(server_type_t type)
{
    g_server = (server_t*)malloc(sizeof(server_t));
    if (g_server == NULL) {
        DEBUG("allocate memory for server fail!\n");
        return -1;
    }
    memset(g_server, 0, sizeof(server_t));

    int32_t ret = 0;
    switch(type) {
    case SERVER_UDP:

        break;
    case SERVER_TCP:

        break;
    case SERVER_UNIX:
        ret = server_unix_init(&(g_server->fd));
        break;
    default:
        assert(0);   
    }
    return ret;
}
#endif

static int tcp_socket_create()
{
    int fd;
    struct sockaddr_in serv_addr;

    memset(&serv_addr, 0, sizeof(serv_addr));

    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        perror("create tcp socket fail\n");
        return -1;
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8888);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr); // value is 0

    if (bind(fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) {
        perror("bind fail\n");
        return -1;
    }
    listen(fd, 5);
    printf("server listen on (%s:8888)\n", inet_ntoa(serv_addr.sin_addr));
    return fd;
}
void tcp_server_start(int32_t listenfd)
{
    int i, maxi, connfd, sockfd, epfd, nfds, portnumber;
    ssize_t n = 0;
#define MAXLINE 200    
    char line[MAXLINE] = {0};
    socklen_t clilen;

    struct epoll_event ev,events[20];

    epfd = epoll_create(256);
    struct sockaddr_in client_addr;
    struct sockaddr_in server_addr;
    //��socket����Ϊ��������ʽ
    //setnonblocking(listenfd);

    //������Ҫ������¼���ص��ļ�������
    ev.data.fd = listenfd;
    //����Ҫ������¼�����
    ev.events = EPOLLIN|EPOLLET;

    //ע��epoll�¼�
    epoll_ctl(epfd, EPOLL_CTL_ADD, listenfd, &ev);
    for (;;) {
        //�ȴ�epoll�¼��ķ���
        nfds = epoll_wait(epfd, events, 20, 500);
        //�����������������¼�

        for(i = 0; i < nfds; ++i) {
            //����¼�⵽һ��SOCKET�û����ӵ��˰󶨵�SOCKET�˿ڣ������µ����ӡ�
            if(events[i].data.fd == listenfd)
            {
                connfd = accept(listenfd, (struct sockaddr*)&client_addr, &clilen);
                if(connfd < 0) {
                    perror("accept client fail!\n");
                    exit(1);
                }
                //setnonblocking(connfd);
                printf("accept a client from %s\n", inet_ntoa(client_addr.sin_addr));
                //�������ڶ��������ļ�������
                ev.data.fd = connfd;
                //��������ע��Ķ������¼�
                ev.events = EPOLLIN|EPOLLET;
                epoll_ctl(epfd, EPOLL_CTL_ADD, connfd, &ev);
            } else if(events[i].events & EPOLLIN) {
                //������Ѿ����ӵ��û��������յ����ݣ���ô���ж���
                //printf("epoll in event\n");
                if ((sockfd = events[i].data.fd) < 0) {
                    printf("fd < 0 \n");
                    continue;
                }
                if ( (n = read(sockfd, line, MAXLINE)) < 0) {
                    if (errno == ECONNRESET) {
                        close(sockfd);
                        events[i].data.fd = -1;
                    } else {
                        printf("readline error!\n");
                    }
                } else if (n == 0) {
                    printf("read 0 bytes\n");
                    close(sockfd);
                    events[i].data.fd = -1;
                } else {
                    line[n] = '\0';
                    printf("read bytes(%u) content:(%s)\n", n, line);
                    //��������д�������ļ�������
                    ev.data.fd = sockfd;
                    //��������ע���д�����¼�
                    ev.events = EPOLLOUT|EPOLLET;
                    //�޸�sockfd��Ҫ������¼�ΪEPOLLOUT

                    epoll_ctl(epfd,EPOLL_CTL_MOD,sockfd,&ev);
                }
            } else if(events[i].events & EPOLLOUT) {
                // ��������ݷ���
                sockfd = events[i].data.fd;
                write(sockfd, line, n);
                //�������ڶ��������ļ�������

                ev.data.fd=sockfd;
                //��������ע��Ķ������¼�

                ev.events=EPOLLIN|EPOLLET;
                //�޸�sockfd��Ҫ������¼�ΪEPOLIN

                epoll_ctl(epfd,EPOLL_CTL_MOD,sockfd,&ev);
            }
        }
    }
}


int main()
{
    int fd;

    fd = tcp_socket_create();
    if (fd < 0) {
        exit(1);
    }
    tcp_server_start(fd);
    

    return 0;
}


