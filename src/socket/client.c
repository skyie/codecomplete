#include "common.h"

#if 0
client_t* g_client = NULL;

unix_client_init()
{
    g_client = (server_t*)malloc(sizeof(client_t));
    if (g_client == NULL) {
        DEBUG("allocate memory for client fail!\n");
        return -1;
    }
    memset(g_client, 0, sizeof(client_t));

    int32_t* fd = &g_client->fd;
    
    *fd = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (*fd < 0) {
        LOG_ERROR("init unix socket fail,%s!\n", strerrno(errno));
        return -1;
    }
    struct sockaddr_un addr;
    memset(&addr, 0, sizeof(struct sockaddr_in));
    addr.sun_family = AF_UNIX;
    strncpy(addr.path, SERVER_UNIX_PREFIX"client", sizeof(addr.path) - 1);
    
}

unix_client_start()
{


}
#endif
static int tcpsocket_create()
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

    if (connect(fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) {
        perror("connect fail\n");
        return -1;
    }
    printf("connect server success!\n");
    return fd;
}
/**
 * sendmsg 
 *
 */
static int sendmsg2server(int fd, /*struct sockaddr_in* serv_addr, */
    void* buf, int len)
{
    assert(buf);
    
    struct msghdr hdr;
    int send_len = 0;
    
    memset(&hdr, 0, sizeof(struct msghdr));

    struct iovec send_vec[1];
    memset(&send_vec, 0, sizeof(struct iovec));
    send_vec[0].iov_base = buf;
    send_vec[0].iov_len = len;
    
    //hdr.msg_name = serv_addr;
    //hdr.msg_len = sizeof(struct sockaddr_in);
    hdr.msg_iov = send_vec;
    hdr.msg_iovlen = len;

    if ((send_len = sendmsg(fd, &hdr, 0)) < 0) {
        perror("sendmsg fail\n");
    }
    printf("send len(%u) buf(%s)\n", len, buf);

    

}
int main()
{
	int fd;
    char buf[1024] = {0};
    
    fd = tcpsocket_create();
    if (fd < 0) {
        exit(1);
    }
    strncpy(buf, "hello world!", sizeof(buf) - 1);
    if (sendmsg2server(fd, buf, strlen(buf))) {
        exit(1);
    }
	return 0;
}
