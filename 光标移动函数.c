 #include<stdio.h>
#include<Windows.h>
void doto_xy(int x, int y) //�ù���ƶ���ָ����λ�ã� x���У� , y���У� 
{
	HANDLE hout; // HANDLE ������������ݣ� 
	hout = GetStdHandle(STD_OUTPUT_HANDLE);//GEt...�Ǵ�һ���ض��ı�׼�豸��ȡ��һ�������
	                                  //������ľ��Ҳ�������Ϊָ���ͣ��λ�õ���Ϣ 
	                                  // ���ֲ����� STD_OUTPUT_HANDLE ����׼�����
									  //STD_INPUT_HANDLE   ����׼���룩
									  //STD_ERROR_HANDLE    ����׼���� 
	COORD pos = { x,y };  //CCOORD��Windows API�ж����һ�ֽṹ��
	                  //��ʾһ���ַ��ڿ���̨��Ļ������ 
	SetConsoleCursorPosition(hout, pos);  // һ��ʵ�ֹ���λ�ÿ��Ƶļ��������
	                                  //��������Ϊ�����������COORD�Ľṹ�壩 
}
int main()
{printf("Hello World\n");
	doto_xy(3, 4);
	printf("haha");
	doto_xy(3, 5);
	printf("->");
	return 0;
}
