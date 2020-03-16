/*************************************************************************
    > File Name: pv.c
    > Author: CC
    > Mail: 6828620@163.com 
    > Created Time: 2018年09月11日 星期二 22时28分27秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<sys/sem.h>
#include<string.h>
#include<assert.h>
#include<malloc.h>
#include"pv.h"
 
union semun{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
};
 
//初始化semnums个信号灯的直
int I(int semnums,int value)
{
	//创建信号量集
	int semid = semget(IPC_PRIVATE,semnums,IPC_CREAT|IPC_EXCL | 0777);
	if(semid < 0){
		perror("semget error!\n");
		exit(1);
	}
	union semun un;
	unsigned short *array = (unsigned short)calloc(semnums,sizeof(unsigned short));
	int i;
	//数组初始化
	for(i = 0; i < semnums; i++){
		array[i] = value;
	}
	un.array = array;
	//初始化信号量集中所以信号灯的初值。0表示初始化所有信号灯，SETALL表示
	if(semctl(semid,0,SETALL,un) < 0){
		perror("semctl error");
		return -1;
	}
	free(array);
	return semid;
}
//对信号量集(semid)中的信号灯(semun)作P(value)操作
void P(int semid,int semnum,int value)
{
	assert(value >= 0);
	//定义sembuf的结构体数组，放置若干结构体变量，对应要操作的信号量/作P或V操作。
	struct sembuf ops[] = {{semnum,-value,SEM_UNDO}};
 
 
	if(semop(semid,ops,sizeof(ops)/sizeof(struct sembuf)) < 0){
		perror("semop error");
	}
}
//对信号量集(semid)中的信号灯(semun)作V(value)操作
void V(int semid,int semnum,int value)
{
 
	assert(value >= 0);
	//定义sembuf的结构体数组，放置若干结构体变量，对应要操作的信号量/作P或V操作。
	struct sembuf ops[] = {{semnum,value,SEM_UNDO}};
 
 
	if(semop(semid,ops,sizeof(ops)/sizeof(struct sembuf)) < 0){
		perror("semop error");
	}
}
//销毁信号量集(semid)
void D(int semid)
{
	if(semctl(semid,0,IPC_RMID,NULL) < 0){
		perror("semctl error!\n");
		exit(1);
	}
}
