#include "common.h"
#include "server.h"

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
int main()
{
	printf("this is client\n");
	return 0;
}
