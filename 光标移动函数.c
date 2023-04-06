 #include<stdio.h>
#include<Windows.h>
void doto_xy(int x, int y) //让光标移动到指定的位置： x（列） , y（行） 
{
	HANDLE hout; // HANDLE （句柄类型数据） 
	hout = GetStdHandle(STD_OUTPUT_HANDLE);//GEt...是从一个特定的标准设备中取得一个句柄。
	                                  //在这里的句柄也可以理解为指光标停留位置的信息 
	                                  // 几种参数： STD_OUTPUT_HANDLE （标准输出）
									  //STD_INPUT_HANDLE   （标准输入）
									  //STD_ERROR_HANDLE    （标准错误） 
	COORD pos = { x,y };  //CCOORD是Windows API中定义的一种结构，
	                  //表示一个字符在控制台屏幕的坐标 
	SetConsoleCursorPosition(hout, pos);  // 一个实现光标的位置控制的计算机函数
	                                  //两个参数为：（光标句柄，COORD的结构体） 
}
int main()
{printf("Hello World\n");
	doto_xy(3, 4);
	printf("haha");
	doto_xy(3, 5);
	printf("->");
	return 0;
}
