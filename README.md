# shmTest
This peoject simply verify the Shared memory mechanism of Linux. refer to the blog:http://ilinuxkernel.com/?p=1276. 
The following is a brief introduction to each file.
①dram.c--This module implements a Linux character-mode device-driver for the processor's installed physical memory.
②fileview--view physical memory.
③mem_map.h--get the address and value of variable.
④sys_reg.c--get the value of the associated register.
⑤shmdata.h--a data structure on Shared memory address. 
⑥shmRead.c--Write variables.
⑦shmWrite.c--Read variables.
