#include <stdio.h>
#include <stdlib.h>

int g_var1 = 10;
int g_var2;
int my_malloc()
{
	int* p = malloc(sizeof(int));
	*p = 10;
}
void show_hello()
{
	printf("hello world\n");
}

int sum(int a, int b)
{
	int c = 0;
	printf("a=%u,b=%u\n", a, b);
	c = a + b;
	printf("sum=%u\n", c);
	return c;
}
int do_something()
{
	printf("XXX");
}
int test_child_mem_leak()
{
	pid_t child;
	int child_status;

	int ret = fork();
	if (ret < 0) {
		perror("fork fail\n");
		return -1;
	}
	if (ret == 0) {
		printf("father pid(%u)\n", getpid());
		int* father_lear_var = malloc(sizeof(int));
		*father_lear_var = 1;
	} else {
		int* child_leak_var = malloc(sizeof(int));
		*child_leak_var = 4;
	}
	child = wait(-1, NULL, NULL);
	return 0;

}
int main(int argc, char** argv)
{
	//my_malloc();
	//do_something();
	//test_child_mem_leak();
	int local_a = 1;
	char local_b = 3;
	static s_var1 = 2;
	static s_var2;
	int* heap_var = malloc(sizeof(int));
	*heap_var = 3;
	printf("-------------\n");


	free(heap_var);
	return 0;
}















