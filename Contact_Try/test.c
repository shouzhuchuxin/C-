
#include"Try.h"
void menu()
{
	printf("********* 1.Add           2.Delete   **********\n");
	printf("********* 3.Find          4.Change   **********\n");
	printf("********* 5.Show          6.Sort     **********\n");
	printf("********* 7.Save          0.exit     **********\n");
}
void test()
{
	int i = 0;
	Con Coon;
	
	//�Խṹ����г�ʼ��
	Init(&Coon);
	do
	{   menu();
		printf("��ѡ��\n");
		scanf_s("%d", &i);
		 Checkcapacity(&Coon);
       switch (i)
	{
	case 1:Add(&Coon);
		break;
	case 2:Delete(&Coon);
		break;
	case 3:Finds(&Coon);
		break;
	case 4:Change(&Coon);
		break;
	case 5:Show(&Coon);
		break;
	case 6:Sort(&Coon);
		break;
	case 7:Save(&Coon);
		break;
	case 0:printf("�˳���\n");
		   Save(&Coon);
		FreeTes(&Coon);
		break;
	default:printf("����������������롣\n");

	}
	} while (i);
}
int main()
{
	
	test();
	return 0;
}