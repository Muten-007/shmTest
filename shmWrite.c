#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include "shmdata.h"
#include "mem_map.h"
 
int main()
{
	int running = 1;
	void *shm = NULL;
	struct shared_use_st *shared = NULL;
	int shmid;
	//创建共享内存
	shmid = shmget((key_t)5678, sizeof(struct shared_use_st), 0666|IPC_CREAT);
	if(shmid == -1)
	{
		fprintf(stderr, "shmget failed\n");
		exit(EXIT_FAILURE);
	}
	//将共享内存连接到当前进程的地址空间
	shm = shmat(shmid, (void*)0, 0);
	if(shm == (void*)-1)
	{
		fprintf(stderr, "shmat failed\n");
		exit(EXIT_FAILURE);
	}
	printf("Memory attached at %X\n", (int)shm);
	//设置共享内存
	shared = (struct shared_use_st*)shm;
	shared->tmp =0x12345678;//往共享内存中写入tmp
	printf("tmp value in Write:0x%08lX\n", shared->tmp);//输出tmp的值
	printf("tmp address in Write:0x%08lX\n", &shared->tmp);//输出tmp的地址信息
	shared->written = 1;//设置written位
	outputMem();//打印相关寄存器信息
	return 1;

}
