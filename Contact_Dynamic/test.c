#include"Contact.h"
void menu()
{
	printf("******************************************************\n");
	printf("************     1.add        2.del        ***********\n");
	printf("************     3.search     4.modify     ***********\n");
	printf("************     5.show       6.sort       ***********\n");
	printf("************     0.exit                    ***********\n");
	printf("******************************************************\n");
}


void  main()
{
	
	int input = 0;
	//����ͨѶ¼
	//struct Contast con;//con����ͨѶ¼��������1000 ��Ԫ�ص�����size
	//��ʼ��ͨѶ¼
	InitContact(&con);
	InitContact(&p);
	//���ֵ
	   //AddContact(&con); 
	//��ӡͨѶ¼
	   //ShowContact(&con);
	do 
	{
		menu();
		printf("��ѡ��>\n");
		scanf_s("%d", &input);
		switch (input)

		{
		case 1:AddContact(&con);
			break;
		case 2:DelContact(&con);
			break;
		case 3:SearchContact(&con);
			break;
		case 4:ModifyContact(&con);
			break;
		case 5:ShowContact(&con);
			break;
		case 6:SortContact(&con,&p);
			break;
		case 0:
			Freedata(&con);
			break;
		default:
			printf("����������������룺\n");
		}
		

	}
      
	while (input);


	
}