#include"Try.h"
void Init(Con *p)
{
	p->Tes = (try*)malloc(begin_capacity* sizeof(try));
	if (p->Tes == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	p->size = 0;
	p->capacity = begin_capacity;
	
	//把文件中已经存放的通讯录中的信息加载到通讯录中
	LoadCon(p);
}

void Add(Con* p)
{
	if (p->size == 100)
		printf("已满。\n");
	else
	{
		printf("请输入职工号:\n");
		scanf_s("%d", &(p->Tes[p->size].Count));
		printf("请输入姓名:\n");
		scanf_s("%s", p->Tes[p->size].Name,5);
		printf("请输入政治面貌:\n");
		scanf_s("%s", p->Tes[p->size].Identity,10);
		printf("请输入性别:\n");
		scanf_s("%s", p->Tes[p->size].Gender,3);
		printf("请输入部门:\n");
		scanf_s("%s", p->Tes[p->size].Address,10);
		printf("请输入党龄:\n");
		scanf_s("%d", &(p->Tes[p->size].Tl));
		printf("请输入工龄:\n");
		scanf_s("%d", &(p->Tes[p->size].Gl));
		printf("请输入电话:\n");
		scanf_s("%s", p->Tes[p->size].Tel,11);
		p->size++;
	}
}
int Find(Con* p, char name[5])
{
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		if (0 == strcmp(p->Tes[i].Name, name))
			return i;
	}
	return -1;
}

void Delete(Con* p)
{
	char name[5] = { 0 };
	printf("请输入要删除信息的名字：\n");
	scanf_s("%s", name, 10);
	int i = Find(p,name);
	if (i == -1)
	{
		printf("输入的名字不存在！\n");
	}
	else
	{
		int j = 0;
		for (j = i; j <= p->size -1; j++)
			p->Tes[j] = p->Tes[j + 1];
		p->size--;
		printf("删除成功。\n");
	}
	

}

void Find1(Con* p)
{
	printf("请输入所要查找的职工号：\n");
	int i = 0;
	scanf_s("%d", &i);
	int j = 0;
	for (j = 0; j < p->size; j++)
	{
		if (p->Tes[j].Count == i)
		{
			i = -1;
			break;
		} 	
	}
	if (i != -1)
	{
		printf("输入错误，请重新输入。\n");
		return;
	}
	printf("%-4s\t%-4s\t%-3s\t%-10s\t%-12s\t \n", "职工号", "姓名","性别","部门","电话");
		printf("%-4d\t%-4s\t%-3s\t%-10s\t%-12s\t \n\n"
			, p->Tes[j].Count,
			p->Tes[j].Name,
			p->Tes[j].Gender,
			p->Tes[j].Address,
			p->Tes[j].Tel);

	return;
}
void Find2(Con* p)
{
	printf("请输入要查找的姓名。\n");
	char name[10];
	scanf_s("%s", name,10);
	int j = Find(p, name);
	if (j == -1)
	{
		printf("要查找的名字不存在。\n");
	}
	else
	{
		printf("%-4s\t%-4s\t%-3s\t%-10s\t%-12s\t\n", "职工号", "姓名", "性别", "部门", "电话");
		printf("%-4d\t%-4s\t%-3s\t%-10s\t%-12s\t \n\n"
			, p->Tes[j].Count,
			p->Tes[j].Name,
			p->Tes[j].Gender,
			p->Tes[j].Address,
			p->Tes[j].Tel);
	}
}
void Find3(Con* p)
{
	char A[10] = { 0 };
	printf("请输入要查找的部门。\n");
	
	scanf_s("%s", A, 10);
	int B[100] = { 0 };
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		if (0 == strcmp(p->Tes[i].Address, A));
		else
		{
			printf("查找的部门不存在。\n");
			break;
		}
	}
	for (i = 0; i < p->size; i++)
	{
		if (0 == strcmp(p->Tes[i].Address, A))
		{
			printf("%-4s\t%-4s\t%-3s\t%-10s\t%-12s\t\n", "职工号", "姓名", "性别", "部门", "电话");
			printf("%-4d\t%-4s\t%-3s\t%-10s\t%-12s\t \n"
				, p->Tes[i].Count,
				p->Tes[i].Name,
				p->Tes[i].Gender,
				p->Tes[i].Address,
				p->Tes[i].Tel);
		}

	}
}
void Show1(Con* p)
{
	
	int i = 0;
	
	do 
	{
		printf("请输入查询的方式：\n");
		printf("1.通过职工号 2. 通过姓名 3.查找某部门所有信息 0.退出查找\n");
         scanf_s("%d", &i);
		switch (i)
		{
		case 1:Find1(p);
			break;
		case 2:Find2(p);
			break;
		case 3:Find3(p);
			break;
		case 0:printf("退出查找。\n"); i = 0;
			break;
		default:printf("输入错误，请重新选择查询的方式。\n");
			
		}
	}
	while (i);
}
void Show2(Con* p)
{
	int i = 0;
	printf("请输入要查询的职工号。\n");
	scanf_s("%d", &i);
	int j = 0;
	for (j = 0; j < p->size; j++)
	{
		if (p->Tes[j].Count == i)
		{
			i = -1;
			break;
		}
	}
	if (i != -1)
	{
		printf("输入错误，请重新输入。\n");
		return;
	}
	printf("职工号：%d\t姓名： %s\t性别： %s\n政治面貌：%s\t党龄：%d\t工龄：%d\n部门：%s\t电话：%s\n\n",
		p->Tes[j].Count,
		p->Tes[j].Name,
		p->Tes[j].Gender,
		p->Tes[j].Identity,
		p->Tes[j].Tl,
		p->Tes[j].Gl,
		p->Tes[j].Address,
		p->Tes[j].Tel);
	
}
void Finds(Con* p)
{
	
	int i = 0;
	do
	{
		printf("\n请选择查找的方式：\n");
	    printf("1.基本信息查询 2.党籍查询 0.退出查询\n");
	    printf("输入->\n");

		scanf_s("%d", &i);
		switch (i)
		{
        case 1:Show1(p);
		  break;
		case 2:Show2(p);
			break;
		case 0:printf("退出查找。\n");
			break;
		default:printf("输入错误，请重新选择。\n");
		}
	} while (i);
}

void Change(Con *p)
{
	char i[5] = { 0 };
	printf("请输入要改变的信息的姓名。\n");
	scanf_s("%s", i,10);
	
	int j = Find(p, i);
	if (j == -1)
	{
		printf("输入错误，请重新输入。\n");
		return;
	}
	else
	{
		printf("请根据提示输入需要修改的信息。\n");
		printf("请输入职工号:\n");
		scanf_s("%d", &(p->Tes[j].Count));
		printf("请输入姓名:\n");
		scanf_s("%s", p->Tes[j].Name, 5);
		printf("请输入政治面貌:\n");
		scanf_s("%s", p->Tes[j].Identity, 10);
		printf("请输入性别:\n");
		scanf_s("%s", p->Tes[j].Gender, 3);
		printf("请输入部门:\n");
		scanf_s("%s", p->Tes[j].Address, 10);
		printf("请输入党龄:\n");
		scanf_s("%d", &(p->Tes[j].Tl));
		printf("请输入工龄:\n");
		scanf_s("%d", &(p->Tes[j].Gl));
		printf("请输入电话:\n");
		scanf_s("%s", p->Tes[j].Tel,11);
	
	}
	
}

void Show(Con* p)
{
	if (p->size == 0)
	{
		printf("请先输入数据再进行打印。\n");
	}
	else
	{
		printf("所有信息为：\n");
		int j = 0;
		for (j = 0; j < p->size; j++)
		{

			printf("职工号：%d\t姓名： %s\t性别： %s\n政治面貌：%s\t党龄：%d\t工龄：%d\n部门：%s\t电话：%s\n\n",
				p->Tes[j].Count,
				p->Tes[j].Name,
				p->Tes[j].Gender,
				p->Tes[j].Identity,
				p->Tes[j].Tl,
				p->Tes[j].Gl,
				p->Tes[j].Address,
				p->Tes[j].Tel);

		}
		
	}
}

void sort1(Con* p)
{
	printf("1.从大到小 2.从小到大\n");
	int m = 0;
	scanf_s("%d", &m);
	int i = 0;
	switch (m)
	{
	case 1:
	for (i = p->size-1; i >= 0; i--)
	{
		int j = 0;
		int flog = 1;
		for (j = 0; j < i; j++)
		{
               if (p->Tes[j].Tl < p->Tes[j + 1].Tl)
			{
				try s;
				s = p->Tes[j];
				p->Tes[j] = p->Tes[j + 1];
				p->Tes[j + 1] = s;
				flog = 0;
		    }
			   
		}
		if (flog)
		{
			printf("排序成功。\n"); return;
			}
				  
			
	}
	break;
	case 2:for (i = p->size - 1; i >= 0; i--)
	{
		int j = 0;
		int flog = 1;
		for (j = 0; j < i; j++)
		{
            if (p->Tes[j].Tl > p->Tes[j + 1].Tl)
			{
				try s;
				s = p->Tes[j];
				p->Tes[j] = p->Tes[j + 1];
				p->Tes[j + 1] = s;
				flog = 0;
			}
			
		}
		if (flog)
		{
			printf("排序成功。\n");
			return;
		}
				
			
	}
		  break;
	default:printf("输入错误，请重新选择。\n");
		return;
	}
	
	printf("排序成功。\n");
}
void sort2(Con* p)
{
	printf("1.从大到小 2.从小到大\n");
	int m = 0;
	scanf_s("%d", &m);
	int i = 0;
	switch (m)
	{
	case 1:
		for (i = p->size - 1; i >= 0; i--)
		{
			int j = 0;
			int flog = 1;
			for (j = 0; j < i; j++)
			{
                 if (p->Tes[j].Gl < p->Tes[j + 1].Gl)
				{
					try s;
					s = p->Tes[j];
					p->Tes[j] = p->Tes[j + 1];
					p->Tes[j + 1] = s;
					flog = 0;
				}
			}
			if (flog)
			{
				printf("排序成功。\n");return;
			}
				
				
		}
		break;
	case 2:
		for (i = p->size - 1; i >= 0; i--)
		{
			int j = 0;
			int flog = 1;
			for (j = 0; j < i; j++)
			{
                   if (p->Tes[j].Gl > p->Tes[j + 1].Gl)
				{
					try s;
					s = p->Tes[j];
					p->Tes[j] = p->Tes[j + 1];
					p->Tes[j + 1] = s;
					flog = 0;
				}
				   
			}
			if (flog)
			{
				printf("排序成功。\n"); return;
			}
			
				
		}
		  break;
	default:printf("输入错误，请重新选择。\n");
		return;
	}

	printf("排序成功。\n");
}
void sort3(Con* p)
{
	printf("1.从大到小 2.从小到大\n");
	int m = 0;
	scanf_s("%d", &m);
	int i = 0;
	switch (m)
	{
	case 1:
		for (i = p->size - 1; i >= 0; i--)
		{
			int j = 0;
			int flog = 1;
			for (j = 0; j < i; j++)
			{
                   if (strcmp(p->Tes[j].Name,p->Tes[j+1].Name))
				{
					try s;
					s = p->Tes[j];
					p->Tes[j] = p->Tes[j + 1];
					p->Tes[j + 1] = s;
					flog = 0;
				}
			}
			if (flog)
			{
				printf("排序成功。\n");return;
			}
				

				
		}
		break;
	case 2:
		for (i = p->size - 1; i >= 0; i--)
		{
			int j = 0;
			int flog = 1;
			for (j = 0; j < i; j++)
				if (strcmp(p->Tes[j].Name, p->Tes[j + 1].Name))
				{
					try s;
					s = p->Tes[j];
					p->Tes[j] = p->Tes[j + 1];
					p->Tes[j + 1] = s;
					flog = 0;
				}
			if (flog)
			{
				printf("排序成功。\n");return;
			}
				
		}
		break;
	default:printf("输入错误，请重新选择。\n");
		return;
	}

	printf("排序成功。\n");
}
void Sort(Con* p)
{
	int i = 0;
	printf("请输入要排序的方法。\n");
		printf("1.党龄 2.工龄 3.名字\n");
		scanf_s("%d",&i);
		switch (i)
		{
		case 1:sort1(p);
			break;
		case 2:sort2(p);
			break;
		case 3:sort3(p);
			break;
		default:printf("输入错误，请重新选择。\n");
		}
}void Checkcapacity(Con* p)
{
	if (p->size == p->capacity)
	{
		//增容
		try* p1 = (try*)realloc(p->Tes,(p->capacity + 2) * sizeof(try));
		if (p1 != NULL)
		{
			p->Tes = p1;
			p->capacity += 2;
			printf("增容成功。\n");
		}else
			printf("增容失败。\n");
	}
}
void FreeTes(Con* p)
{
	free(p->Tes);
	p->Tes = NULL;
}

void LoadCon(Con* p)
{
	try tmp = { 0 };
	FILE* Read = fopen("test.txt", "rb");
	if (Read == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	while (fread(&tmp, sizeof(try), 1, Read))
	{
		Checkcapacity(p);
		p->Tes[p->size] = tmp;
		p->size++;
	}
}
void Save(Con* p)
{
	FILE* write = fopen("test.txt", "wb");
		if (write == NULL)
		{
			printf("%s\n", strerror(errno));
			return;
		}
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		fwrite(&(p->Tes[i]), sizeof(try), 1, write);
	}
	fclose(write);
	write = NULL;
	printf("保存成功.\n");
}