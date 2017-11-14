/**
 * include common linux head files
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <errno.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
/**for sem include**/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/stat.h> //for S_IRUSR
/*****/
