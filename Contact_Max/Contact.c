#include"Contact.h"
//初始化通讯录
void InitContact(struct Contact* p)
{
	p->data=(Peo*)malloc(Begin_capacity * sizeof(Peo));
	if (p->data == NULL)
	{
		return;
	}
	p->size = 0;
	p->capacity = Begin_capacity;
	//把文件中已经存放的通讯录中的信息加载到通讯录中
	LoadContact(p);
}

//加载文件中的内容
void LoadContact(struct Contact* p)
{
	
	Peo tmp = { 0 };
	FILE* Read = fopen("contact.txt", "rb");
	if(Read == NULL)
		{
			printf("LoadContact:%s\n",strerror(errno));
			return ;
		}

	//将文件中内容先放到tmp中，每次放一组，直到放完
	while (fread(&tmp, sizeof(Peo), 1, Read))
	{
		Checkcapacity(p);
		p->data[p->size] = tmp;
		p->size++;
	}
	fclose(Read);
	Read = NULL;
		  
}


//添加通讯录
void AddContact(struct Contact* p1)
{
	//检测当前通讯录的容量		
	Checkcapacity(p1);
	
		printf("请输入名字>\n");
		scanf_s("%s",p1->data[p1->size].name,10);
		printf("请输入性别>\n");
		scanf_s("%s",p1->data[p1->size].sex,10);
		printf("请输入年龄>\n");
		scanf_s("%d",&(p1->data[p1->size].age));
		printf("请输入电话>\n");
		scanf_s("%s",p1->data[p1->size].tele,10);
		printf("请输入地址>\n");
		scanf_s("%s",p1->data[p1->size].addr,10);
	
		p1->size++;
		printf("输入成功！\n");
	
}

//打印通讯录
void ShowContact(const struct Contact *p2)
{
	int i = 0;
	if (p2->size == 0)
		printf("还未输入，请先输入。\n");
	else
		printf("%-10s\t%-4s\t%-4s\t%-12s\t%-10s\t\n", "姓名", "性别", "年龄", "电话","住址");
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

//寻找名字所在位置的下标
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

//删除一个信息
void DelContact(struct Contact* p3)
{
	char name[MAX_name];
	printf("请输入要删除的名字。\n");
	scanf_s("%s", name,10);
	//查找删除人所在位置
	int i = Find(p3, name);
	if (i == -1)
	{
		printf("输入的名字不存在。\n");
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

//查找一个信息
void SearchContact(const struct Contact* p4)
{
	char name[MAX_name];
	printf("请输入要查找人的名字。\n");
	scanf_s("%s", name, 10);
	int ret = Find(p4, name);
	if (ret == -1)
	{
		printf("要查找人的名字不存在。\n");
	}
	else
		printf("\n所查找人的信息为：\n");
		printf("\n%-10s\t%-4s\t%-4s\t%-12s\t%-10s\t\n", "姓名", "性别", "年龄", "电话", "住址");
	
		printf("%-10s\t%-4s\t%-4d\t%-12s\t%-10s\t\n",
			p4->data[ret].name,
			p4->data[ret].sex,
			p4->data[ret].age,
			p4->data[ret].tele,
			p4->data[ret].addr);
	
}

//改变一个信息
void ModifyContact(const struct Contact* p5)
{
	char name[MAX_name];
	printf("请输入要改变信息的人的名字。\n");
	scanf_s("%s", name, 10);
	int ret = 0;
	ret = Find(p5, name);
	if (-1 == ret)
	{
		printf("输入的名字不存在。\n");
	}
	else
		printf("\n请根据提示重新输入信息：\n");
		printf("\n请输入名字>\n");
	scanf_s("%s", p5->data[ret].name, 10);
	printf("请输入性别>\n");
	scanf_s("%s", p5->data[ret].sex, 10);
	printf("请输入年龄>\n");
	scanf_s("%d", &(p5->data[ret].age));
	printf("请输入电话>\n");
	scanf_s("%s", p5->data[ret].tele, 10);
	printf("请输入地址>\n");
	scanf_s("%s", p5->data[ret].addr, 10);

	
	printf("输入成功！\n");
}

//对信息进行排序
void SortContact(struct Contact* p6,struct Contact* p7)
{
	int i = 0;
	
	if (p6->size == 0 || p6->size == 1)
		printf("请先输入信息或信息量小于2.");
	else
	{
		printf("请选择排序的方法：1.name 2.age\n");
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

void Checkcapacity(struct Contact* p)
{
	if (p->size == p->capacity)
	{
		//增容
		
		struct PeoInfo*p1=(struct PeoInfo*)realloc(p->data, (p->capacity + 2) * sizeof(Peo));
		if (p1 != NULL)
		{
			p->data = p1;
			p->capacity += 2;
			printf("增容成功！\n");
		}
		else
			printf("增容失败！\n");
		
	}
}

void Freedata(struct Contact* p)
{
	free(p->data);
	p->data = NULL;
}

void SaveContact(struct Contact* p)
{
	FILE* Write = fopen("Contact.txt", "wb");
	if (Write == NULL)
	{
		printf("%s\n", strerror(errno));
		return ;
	}

	//写通讯录信息到文件中

	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		fwrite(&(p->data[i]), sizeof(struct PeoInfo),1,Write);
	}

		fclose(Write);
	Write = NULL;
	printf("保存成功！\n");
}