#include "common.h"

/* 要点：
 * 1.实现单消费者-单生产者，单-多，多-单，多-多的无锁队列模型
 * 2.多线程
 * 3.多线程与core的CPU亲和性
 * @date 2016-03-03
 *
 */

typedef struct queue
{
	int type;
	int
};
