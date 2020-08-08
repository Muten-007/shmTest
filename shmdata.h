#ifndef _SHMDATA_H_HEADER
#define _SHMDATA_H_HEADER
 
struct shared_use_st
{
	int written;//初始为0，shmWrite进程写值之后为1。
	unsigned long tmp;//写入内存的数
};
 
#endif
