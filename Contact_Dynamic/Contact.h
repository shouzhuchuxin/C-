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
	struct PeoInfo *data;//���һ����Ϣ
	int size;//��¼��ŵĸ���
	int capacity;//��ǰͨѶ¼���������
}con,p;

//����������
//��ʼ��
void InitContact(struct Contact* p);

//����һ����Ϣ
void AddContact(struct Contact* p1);

//��ӡ��ȫ����Ϣ
void ShowContact(const struct Contact* p2);

//ɾ��һ����Ϣ
void DelContact(struct Contact* p3);

//����һ����Ϣ
void SearchContact(const struct Contact* p4);

//�ı�һ����Ϣ
void ModifyContact(const struct Contact* p5);

//����
void SortContact(struct Contact* p6, struct Contact* p7);

//�ж��ڴ��Ƿ�����
void Checkcapacity(struct Contact* p);

//�ͷ� �ڴ�
void Freedata(struct Contact* p);