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
	int size;  // �ܳ���
	int capacity; //��ǰ�Ĵ�С 
}Con;
//��ʼ��
void Init(Con *p);

//���
void Add(Con* p);

//ɾ��
void Delete(Con* p);

//����
void Finds(Con* p);

//�ı�
void Change(Con* p);

//��ӡ
void Show(Con* p);

//����
void Sort(Con* p);

//�ж��Ƿ���Ҫ��������
void Checkcapacity(Con* p);

//�ͷſռ�
void FreeTes(Con* p);

//������Ϣ
void LoadCon(Con* p);

//������Ϣ���ļ���
void Save(Con* p);
