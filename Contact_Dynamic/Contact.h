#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>



#define  MAX_name 20
#define  MAX_sex  5
#define  MAX_tele 12
#define  MAX_addr 20
#define  Begin_capacity    3


typedef struct PeoInfo
{
	char name[MAX_name];
	char sex[MAX_sex];
	int age;
	char tele[MAX_tele];
	char addr[MAX_addr];

}Peo;

struct Contact 
{
	struct PeoInfo *data;//存放一个信息
	int size;//记录存放的个数
	int capacity;//当前通讯录的最大容量
}con,p;

//函数的声明
//初始化
void InitContact(struct Contact* p);

//增加一个信息
void AddContact(struct Contact* p1);

//打印出全部信息
void ShowContact(const struct Contact* p2);

//删除一个信息
void DelContact(struct Contact* p3);

//查找一个信息
void SearchContact(const struct Contact* p4);

//改变一个信息
void ModifyContact(const struct Contact* p5);

//排序
void SortContact(struct Contact* p6, struct Contact* p7);

//判断内存是否满了
void Checkcapacity(struct Contact* p);

//释放 内存
void Freedata(struct Contact* p);