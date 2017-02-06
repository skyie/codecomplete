/**
 * linux操作目录
 */


/*

#include<sys/types.h>
#include<dirent.h>

DIR* opendir (const char * path ); （获取path子目录下的所由文件和目录的列表，
如果path是个文件则返回值为NULL

typedef struct __dirstream DIR;
*/
#include "common.h"



int read_dir(const char* path)
{
	DIR*  p_dir = NULL;
	struct dirent* entry = NULL;

	p_dir = opendir(path);
	if (p_dir == NULL) {
		printf("opendir fail\n");
		return -1;
	}
	while (entry = readdir(p_dir)) {
		printf("%s\n", entry->d_name);


	}
	closedir(p_dir);
	return 0;
}

int main()
{

	read_dir("/root");

	return 0;
}
