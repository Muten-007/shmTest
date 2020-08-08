#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/shm.h>
#include "shmdata.h"
#include "mem_map.h"
 
int main()
{
	void *shm = NULL;//����Ĺ����ڴ��ԭʼ�׵�ַ
	struct shared_use_st *shared;//ָ��shm
	int shmid;//�����ڴ��ʶ��
	//���������ڴ�
	shmid = shmget((key_t)5678, sizeof(struct shared_use_st), 0666|IPC_CREAT);
	if(shmid == -1)
	{
		fprintf(stderr, "shmget failed\n");
		exit(EXIT_FAILURE);
	}
	//�������ڴ����ӵ���ǰ���̵ĵ�ַ�ռ�
	shm = shmat(shmid, 0, 0);
	if(shm == (void*)-1)
	{
		fprintf(stderr, "shmat failed\n");
		exit(EXIT_FAILURE);
	}
	printf("\nMemory attached at %X\n", (int)shm);
	//���ù����ڴ�
	shared = (struct shared_use_st*)shm;
	while(1){
		if(shared->written ==1){	//shmWrite�����Ѿ�д��ֵ
		printf("tmp value in read:0x%08lX\n", shared->tmp);//���tmp��ֵ
		printf("tmp address in read:0x%08lX\n", &shared->tmp);//�����ַ
		outputMem();//�����ؼĴ�����Ϣ
	}else{
		sleep(1);
	}
	}
	return 1;
}
