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
	//创建通讯录
	//struct Contast con;//con就是通讯录，里面有1000 个元素的数和size
	//初始化通讯录
	InitContact(&con);
	InitContact(&p);
	//添加值
	   //AddContact(&con); 
	//打印通讯录
	   //ShowContact(&con);
	do 
	{
		menu();
		printf("请选择>\n");
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
			printf("输入错误，请重新输入：\n");
		}
		

	}
      
	while (input);


	
}