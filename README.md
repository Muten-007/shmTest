# shmTest
This peoject simply verify the Shared memory mechanism of Linux. refer to the blog:http://ilinuxkernel.com/?p=1276
The following is a brief introduction to each file.
dram.c--This module implements a Linux character-mode device-driver for the processor's installed physical memory.
fileview--view physical memory.
mem_map.h--get the address and value of variable.
sys_reg.c--get the value of the associated register.
shmdata.h--a data structure on Shared memory address. 
shmRead.c--Write variables.
shmWrite.c--Read variables.
