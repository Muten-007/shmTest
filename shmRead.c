#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/shm.h>
#include "shmdata.h"
#include "mem_map.h"
 
int main()
{
	void *shm = NULL;//分配的共享内存的原始首地址
	struct shared_use_st *shared;//指向shm
	int shmid;//共享内存标识符
	//创建共享内存
	shmid = shmget((key_t)5678, sizeof(struct shared_use_st), 0666|IPC_CREAT);
	if(shmid == -1)
	{
		fprintf(stderr, "shmget failed\n");
		exit(EXIT_FAILURE);
	}
	//将共享内存连接到当前进程的地址空间
	shm = shmat(shmid, 0, 0);
	if(shm == (void*)-1)
	{
		fprintf(stderr, "shmat failed\n");
		exit(EXIT_FAILURE);
	}
	printf("\nMemory attached at %X\n", (int)shm);
	//设置共享内存
	shared = (struct shared_use_st*)shm;
	while(1){
		if(shared->written ==1){	//shmWrite进程已经写了值
		printf("tmp value in read:0x%08lX\n", shared->tmp);//输出tmp的值
		printf("tmp address in read:0x%08lX\n", &shared->tmp);//输出地址
		outputMem();//输出相关寄存器信息
	}else{
		sleep(1);
	}
	}
	return 1;
}
