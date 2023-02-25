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
	
	//���ļ����Ѿ���ŵ�ͨѶ¼�е���Ϣ���ص�ͨѶ¼��
	LoadCon(p);
}

void Add(Con* p)
{
	if (p->size == 100)
		printf("������\n");
	else
	{
		printf("������ְ����:\n");
		scanf_s("%d", &(p->Tes[p->size].Count));
		printf("����������:\n");
		scanf_s("%s", p->Tes[p->size].Name,5);
		printf("������������ò:\n");
		scanf_s("%s", p->Tes[p->size].Identity,10);
		printf("�������Ա�:\n");
		scanf_s("%s", p->Tes[p->size].Gender,3);
		printf("�����벿��:\n");
		scanf_s("%s", p->Tes[p->size].Address,10);
		printf("�����뵳��:\n");
		scanf_s("%d", &(p->Tes[p->size].Tl));
		printf("�����빤��:\n");
		scanf_s("%d", &(p->Tes[p->size].Gl));
		printf("������绰:\n");
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
	printf("������Ҫɾ����Ϣ�����֣�\n");
	scanf_s("%s", name, 10);
	int i = Find(p,name);
	if (i == -1)
	{
		printf("��������ֲ����ڣ�\n");
	}
	else
	{
		int j = 0;
		for (j = i; j <= p->size -1; j++)
			p->Tes[j] = p->Tes[j + 1];
		p->size--;
		printf("ɾ���ɹ���\n");
	}
	

}

void Find1(Con* p)
{
	printf("��������Ҫ���ҵ�ְ���ţ�\n");
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
		printf("����������������롣\n");
		return;
	}
	printf("%-4s\t%-4s\t%-3s\t%-10s\t%-12s\t \n", "ְ����", "����","�Ա�","����","�绰");
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
	printf("������Ҫ���ҵ�������\n");
	char name[10];
	scanf_s("%s", name,10);
	int j = Find(p, name);
	if (j == -1)
	{
		printf("Ҫ���ҵ����ֲ����ڡ�\n");
	}
	else
	{
		printf("%-4s\t%-4s\t%-3s\t%-10s\t%-12s\t\n", "ְ����", "����", "�Ա�", "����", "�绰");
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
	printf("������Ҫ���ҵĲ��š�\n");
	
	scanf_s("%s", A, 10);
	int B[100] = { 0 };
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		if (0 == strcmp(p->Tes[i].Address, A));
		else
		{
			printf("���ҵĲ��Ų����ڡ�\n");
			break;
		}
	}
	for (i = 0; i < p->size; i++)
	{
		if (0 == strcmp(p->Tes[i].Address, A))
		{
			printf("%-4s\t%-4s\t%-3s\t%-10s\t%-12s\t\n", "ְ����", "����", "�Ա�", "����", "�绰");
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
		printf("�������ѯ�ķ�ʽ��\n");
		printf("1.ͨ��ְ���� 2. ͨ������ 3.����ĳ����������Ϣ 0.�˳�����\n");
         scanf_s("%d", &i);
		switch (i)
		{
		case 1:Find1(p);
			break;
		case 2:Find2(p);
			break;
		case 3:Find3(p);
			break;
		case 0:printf("�˳����ҡ�\n"); i = 0;
			break;
		default:printf("�������������ѡ���ѯ�ķ�ʽ��\n");
			
		}
	}
	while (i);
}
void Show2(Con* p)
{
	int i = 0;
	printf("������Ҫ��ѯ��ְ���š�\n");
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
		printf("����������������롣\n");
		return;
	}
	printf("ְ���ţ�%d\t������ %s\t�Ա� %s\n������ò��%s\t���䣺%d\t���䣺%d\n���ţ�%s\t�绰��%s\n\n",
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
		printf("\n��ѡ����ҵķ�ʽ��\n");
	    printf("1.������Ϣ��ѯ 2.������ѯ 0.�˳���ѯ\n");
	    printf("����->\n");

		scanf_s("%d", &i);
		switch (i)
		{
        case 1:Show1(p);
		  break;
		case 2:Show2(p);
			break;
		case 0:printf("�˳����ҡ�\n");
			break;
		default:printf("�������������ѡ��\n");
		}
	} while (i);
}

void Change(Con *p)
{
	char i[5] = { 0 };
	printf("������Ҫ�ı����Ϣ��������\n");
	scanf_s("%s", i,10);
	
	int j = Find(p, i);
	if (j == -1)
	{
		printf("����������������롣\n");
		return;
	}
	else
	{
		printf("�������ʾ������Ҫ�޸ĵ���Ϣ��\n");
		printf("������ְ����:\n");
		scanf_s("%d", &(p->Tes[j].Count));
		printf("����������:\n");
		scanf_s("%s", p->Tes[j].Name, 5);
		printf("������������ò:\n");
		scanf_s("%s", p->Tes[j].Identity, 10);
		printf("�������Ա�:\n");
		scanf_s("%s", p->Tes[j].Gender, 3);
		printf("�����벿��:\n");
		scanf_s("%s", p->Tes[j].Address, 10);
		printf("�����뵳��:\n");
		scanf_s("%d", &(p->Tes[j].Tl));
		printf("�����빤��:\n");
		scanf_s("%d", &(p->Tes[j].Gl));
		printf("������绰:\n");
		scanf_s("%s", p->Tes[j].Tel,11);
	
	}
	
}

void Show(Con* p)
{
	if (p->size == 0)
	{
		printf("�������������ٽ��д�ӡ��\n");
	}
	else
	{
		printf("������ϢΪ��\n");
		int j = 0;
		for (j = 0; j < p->size; j++)
		{

			printf("ְ���ţ�%d\t������ %s\t�Ա� %s\n������ò��%s\t���䣺%d\t���䣺%d\n���ţ�%s\t�绰��%s\n\n",
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
	printf("1.�Ӵ�С 2.��С����\n");
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
			printf("����ɹ���\n"); return;
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
			printf("����ɹ���\n");
			return;
		}
				
			
	}
		  break;
	default:printf("�������������ѡ��\n");
		return;
	}
	
	printf("����ɹ���\n");
}
void sort2(Con* p)
{
	printf("1.�Ӵ�С 2.��С����\n");
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
				printf("����ɹ���\n");return;
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
				printf("����ɹ���\n"); return;
			}
			
				
		}
		  break;
	default:printf("�������������ѡ��\n");
		return;
	}

	printf("����ɹ���\n");
}
void sort3(Con* p)
{
	printf("1.�Ӵ�С 2.��С����\n");
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
				printf("����ɹ���\n");return;
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
				printf("����ɹ���\n");return;
			}
				
		}
		break;
	default:printf("�������������ѡ��\n");
		return;
	}

	printf("����ɹ���\n");
}
void Sort(Con* p)
{
	int i = 0;
	printf("������Ҫ����ķ�����\n");
		printf("1.���� 2.���� 3.����\n");
		scanf_s("%d",&i);
		switch (i)
		{
		case 1:sort1(p);
			break;
		case 2:sort2(p);
			break;
		case 3:sort3(p);
			break;
		default:printf("�������������ѡ��\n");
		}
}void Checkcapacity(Con* p)
{
	if (p->size == p->capacity)
	{
		//����
		try* p1 = (try*)realloc(p->Tes,(p->capacity + 2) * sizeof(try));
		if (p1 != NULL)
		{
			p->Tes = p1;
			p->capacity += 2;
			printf("���ݳɹ���\n");
		}else
			printf("����ʧ�ܡ�\n");
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
	printf("����ɹ�.\n");
}