#include"Contact.h"
//��ʼ��ͨѶ¼
void InitContact(struct Contact* p)
{
	memset(p->data, 0, sizeof(p->data));
	p->size = 0;//����ͨѶ¼���ֻ��0��Ԫ��
}

//����ͨѶ¼
void AddContact(struct Contact* p1)
{
	//���ȿ����Ƿ�����		

	if (p1->size == MAX)
		printf("ͨѶ¼������\n");
	else
	{
		printf("����������>\n");
		scanf_s("%s",p1->data[p1->size].name,10);
		printf("�������Ա�>\n");
		scanf_s("%s",p1->data[p1->size].sex,10);
		printf("����������>\n");
		scanf_s("%d",&(p1->data[p1->size].age));
		printf("������绰>\n");
		scanf_s("%s",p1->data[p1->size].tele,10);
		printf("�������ַ>\n");
		scanf_s("%s",p1->data[p1->size].addr,10);
	
		p1->size++;
		printf("����ɹ���\n");
	}
}

//��ӡͨѶ¼
void ShowContact(const struct Contact *p2)
{
	int i = 0;
	if (p2->size == 0)
		printf("��δ���룬�������롣\n");
	else
		printf("%-10s\t%-4s\t%-4s\t%-12s\t%-10s\t\n", "����", "�Ա�", "����", "�绰","סַ");
	for (i = 0; i < p2->size; i++)
	{
		printf("%-10s\t%-4s\t%-4d\t%-12s\t%-10s\t\n",
			p2->data[i].name,
			p2->data[i].sex,
			p2->data[i].age,
			p2->data[i].tele,
			p2->data[i].addr);
	}
}

//Ѱ����������λ�õ��±�
static int Find(const struct Contact* p, char name[MAX_name])
{
    int i = 0;
	for (i = 0; i < p->size; i++)
	{
		if (0 == strcmp(p->data[i].name, name))
			return i;
	}
	return -1;
}

//ɾ��һ����Ϣ
void DelContact(struct Contact* p3)
{
	char name[MAX_name];
	printf("������Ҫɾ�������֡�\n");
	scanf_s("%s", name,10);
	//����ɾ��������λ��
	int i = Find(p3, name);
	if (i == -1)
	{
		printf("��������ֲ����ڡ�\n");
	}
	else
	{
		int j = 0;
		for (j = i; j < p3->size - 1; j++)
		{
			p3->data[j] = p3->data[j + 1];
		}
		p3->size--;
	}
}

//����һ����Ϣ
void SearchContact(const struct Contact* p4)
{
	char name[MAX_name];
	printf("������Ҫ�����˵����֡�\n");
	scanf_s("%s", name, 10);
	int ret = Find(p4, name);
	if (ret == -1)
	{
		printf("Ҫ�����˵����ֲ����ڡ�\n");
	}
	else 
		printf("%-10s\t%-4s\t%-4s\t%-12s\t%-10s\t\n", "����", "�Ա�", "����", "�绰", "סַ");
	
		printf("%-10s\t%-4s\t%-4d\t%-12s\t%-10s\t\n",
			p4->data[ret].name,
			p4->data[ret].sex,
			p4->data[ret].age,
			p4->data[ret].tele,
			p4->data[ret].addr);
	
}

//�ı�һ����Ϣ
void ModifyContact(const struct Contact* p5)
{
	char name[MAX_name];
	printf("������Ҫ�ı���Ϣ���˵����֡�\n");
	scanf_s("%s", name, 10);
	int ret = 0;
	ret = Find(p5, name);
	if (-1 == ret)
	{
		printf("��������ֲ����ڡ�\n");
	}
	else 
		printf("����������>\n");
	scanf_s("%s", p5->data[ret].name, 10);
	printf("�������Ա�>\n");
	scanf_s("%s", p5->data[ret].sex, 10);
	printf("����������>\n");
	scanf_s("%d", &(p5->data[ret].age));
	printf("������绰>\n");
	scanf_s("%s", p5->data[ret].tele, 10);
	printf("�������ַ>\n");
	scanf_s("%s", p5->data[ret].addr, 10);

	
	printf("����ɹ���\n");
}

//����Ϣ��������
void SortContact(struct Contact* p6,struct Contact* p7)
{
	int i = 0;
	
	if (p6->size == 0 || p6->size == 1)
		printf("����������Ϣ����Ϣ��С��2.");
	else
	{
		printf("��ѡ������ķ�����1.name 2.age\n");
		scanf_s("%d", &i);
	}
	if (i == 1)
	{
		int x = 0;
		int y = 0;	
		
		for (x = p6->size; x >1 ; x--)
		{
			for (y = 0; y < p6->size - 1; y++)
			{
				
				if (1 == strcmp(p6->data[y].name, p6->data[y + 1].name))

				{
					p7->data[0] = p6->data[y];
					p6->data[y] = p6->data[y + 1];
					p6->data[y + 1] = p7->data[0];
				}
			}
		}
	}
	else if(i == 2)
	{
		int x = 0;
		int y = 0;
	
		for (x = p6->size; x > 1; x--)
		{
			for (y = 0; y < p6->size - 1; y++)
			{

				if (p6->data[y].age > p6->data[y + 1].age)

				{
					p7->data[0] = p6->data[y];
					p6->data[y] = p6->data[y + 1];
					p6->data[y + 1] = p7->data[0];
				}
					   
			}
		}
	}
}