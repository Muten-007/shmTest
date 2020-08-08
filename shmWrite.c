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
	//���������ڴ�
	shmid = shmget((key_t)5678, sizeof(struct shared_use_st), 0666|IPC_CREAT);
	if(shmid == -1)
	{
		fprintf(stderr, "shmget failed\n");
		exit(EXIT_FAILURE);
	}
	//�������ڴ����ӵ���ǰ���̵ĵ�ַ�ռ�
	shm = shmat(shmid, (void*)0, 0);
	if(shm == (void*)-1)
	{
		fprintf(stderr, "shmat failed\n");
		exit(EXIT_FAILURE);
	}
	printf("Memory attached at %X\n", (int)shm);
	//���ù����ڴ�
	shared = (struct shared_use_st*)shm;
	shared->tmp =0x12345678;//�������ڴ���д��tmp
	printf("tmp value in Write:0x%08lX\n", shared->tmp);//���tmp��ֵ
	printf("tmp address in Write:0x%08lX\n", &shared->tmp);//���tmp�ĵ�ַ��Ϣ
	shared->written = 1;//����writtenλ
	outputMem();//��ӡ��ؼĴ�����Ϣ
	return 1;

}
