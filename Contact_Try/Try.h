#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

#pragma warning(disable:4996)
#define begin_capacity 2
typedef struct Try
{
	int Count;
	char Name[5];
	char Gender[5];
	char Identity[10];
	char Address[10];
	int Tl;
	int Gl;
	char Tel[12];

}try;
typedef struct Contact
{
	struct Try *Tes;
	int size;  // 总长度
	int capacity; //当前的大小 
}Con;
//初始化
void Init(Con *p);

//添加
void Add(Con* p);

//删除
void Delete(Con* p);

//查找
void Finds(Con* p);

//改变
void Change(Con* p);

//打印
void Show(Con* p);

//排序
void Sort(Con* p);

//判断是否需要增容增容
void Checkcapacity(Con* p);

//释放空间
void FreeTes(Con* p);

//加载信息
void LoadCon(Con* p);

//保存信息到文件中
void Save(Con* p);
