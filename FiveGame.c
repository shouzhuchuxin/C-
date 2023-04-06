#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h> 
int v=0,startchoice,winner,player,Q[200][200]={0};//Q记录棋子 
char button;
struct Point
{
	int x,y; 
}point,game_xy;

struct Piece
{
   struct Point corrd;
   struct Piece *fore;
};


char Str[5] = {"->"};
struct Piece *head,*p,*ptr,*ptr1;

//光标移动函数 
void goto_xy(int x, int y) 
{
	HANDLE hout; 
	hout = GetStdHandle(STD_OUTPUT_HANDLE); 
	COORD pos = { x,y };  
	SetConsoleCursorPosition(hout, pos);   
}

//选择游戏还是退出
 void menu_choose(char press)
 {
 	if(press == 87||press == 119)
 	{
 		if(point.y == 3)
 		point.y=4;
 		else point.y = 3;
 		goto_xy(10,point.y);
 	
	 }
	 if(press == 115 || press == 83)
	 {
	 	if(point.y == 4)
	 	point.y = 3;
	 	else point.y = 4;
	 	goto_xy(10,point.y);
	 
	  } 
	  if(press == 13)
	  {
	  	startchoice = point.y-2;   //以此来确定选择的是哪一项 
	  }
	
  } 


//光标闪烁函数 
void bput(const char *s) 
 {
 	int char_len =strlen(s);
 	int i=0;
 	for(i=0;;i++)
 	{
 		goto_xy(10,point.y);
 		printf("%s",s);
 		Sleep(500); //显示字符串的时间 
 		goto_xy(10,point.y);
 		printf("%*s",char_len,"");
 		Sleep(500);//显示空字符串的时间
		 if(kbhit()!=0)
 		{
 			char choice = getch();
 			menu_choose(choice);
 			break;
		 } 
	 }
 }
//欢迎界面 
void Welcome()
{
	system("color 2F");
	goto_xy(17,1);
	printf("主菜单");
	goto_xy(13,3);
	printf("   ***人人对战***");
	goto_xy(13,4);
	printf("    ***退出***  "); 
	point.x=12;
	point.y=3;
	goto_xy(0,0); 
}

void Draw()
{
	int i,j,k1,k2;
	const int m=8;
	const int n=19;
	const int k=3;
	game_xy.x = 10;
	game_xy.y = 3;
	system("cls");
	system("color 3F");
	goto_xy(15,1);
	printf("欢迎来到   五子峡谷！！！");
	goto_xy(17,2);
	printf("(规则如下： )"); 
	goto_xy(29,22);
	printf("重新开始         r");
	goto_xy(1,22);
	printf("悔棋             b");
	goto_xy(1,23);
	printf("退出             ESC");
	
	
	goto_xy(game_xy.x- m ,game_xy.y +k);
	printf("甲方：   #");
	
	goto_xy(game_xy.x- m ,game_xy.y +k+2);
	printf("移动：    上   w");
	
	goto_xy(game_xy.x- m ,game_xy.y +k+4);
	printf("          下   s");
	
	goto_xy(game_xy.x- m ,game_xy.y +k+6);
	printf("          左   a");
	
	goto_xy(game_xy.x- m ,game_xy.y +k+8);
	printf("          右   d");
	
	goto_xy(game_xy.x- m ,game_xy.y +k+10);
	printf("落子：  Enter");
	
	goto_xy(game_xy.x+n ,game_xy.y +k); 
	printf("乙方：   *");
	
	goto_xy(game_xy.x+n ,game_xy.y +k+2);
	printf("移动：    上   w");
	
	goto_xy(game_xy.x+n ,game_xy.y +k+4);
	printf("          下   s");
	
	goto_xy(game_xy.x+n,game_xy.y +k+6);
	printf("          左   a");
	
	goto_xy(game_xy.x+n ,game_xy.y +k+8);
	printf("          右   d");
	
	goto_xy(game_xy.x+n ,game_xy.y +k+10);
	printf("落子：  Enter");
	
	Sleep(5000);
	system("cls");
	for(k1=0;k1<200;k1++)   //初始化棋子记录 
	{
		for(k2=0;k2<200;k2++)
		  
		   Q[k1][k2] =0; 
	}
	
	for(i=0; i <20;i++)
	{
		if(i==0)
		{
			goto_xy(10,i+2);
			for(j=0;j<17;j++)
			{
				printf("--");
			 } 
		}
		if(i!=0&&i!=19)
		{
			goto_xy(10,i+2);
			{
				for(j=0;j<17;j++)
				{
					printf("| ");
					if(j==16)
					{
						printf("|");
					}
				}
			}
		}
		if(i==19)
		{
			goto_xy(10,i+2);
			{
				for(j=0;j<17;j++)
			{
				printf("--");
			 } 
			 
			}
		}
		
	 } 
	 
	 point.x = 19;
	 point.y = 12;
	 goto_xy(19,12);
	 
 } 
//初始化
void Init()
{
	int i=0,j=0;
		for(i=0;i<200;i++)   //初始化棋子记录 
	{
		for(j=0;j<200;j++)
		  
		   Q[i][j] =0; 
	}
	
	startchoice = 0;
	player =1;
	p =(struct Piece*)malloc(sizeof(struct Piece));
	head =p;
 } 
 
 void go_back(int x1,int y1)
 {
 	goto_xy(x1,y1);
 	printf(" ");
 	Q[point.x][point.y] = 0;
 	goto_xy(x1,y1);
 }
 
 void ShowWho()
  {
  	goto_xy(17,22);
  	if(player == 0)
  	   printf("轮到甲方落子。");
	else 
	   printf("轮到乙方落子。");
	                              /*测试：   goto_xy(18,25);
	                                printf("S%d",player);*/
	goto_xy(point.x,point.y); 
  }

 
 //记录棋子情况
 void Record()
 {
 	p->corrd.x=point.x;
 	p->corrd.y=point.y;
 	ptr=p;
 	 p = (struct Piece*)malloc(sizeof(struct Piece));
 	 p->fore=ptr;
 	 
 	 ShowWho();
 	 
 	 /*      测试   ：goto_xy(18,23);
 	                  printf("R%d",player);*/
 	 Q[point.x][point.y] = player+1;   //  甲为2  乙为1 
 	 
 	
 	 if(player)
 	 {
 	 	player=0;
 	 	return;
	  }
	  player =1;
	  goto_xy(point.x,point.y);
  } 
  
  
 
 //落子函数
 void PutDown()
 {
 	if(Q[point.x][point.y] == 0)
 	{
 		/*goto_xy(18,24);
 		printf("P%d",player);*/
 		if(player)
 		{
 			printf("*");
 			printf("\a");
 			Record();
		 }
		 else 
		 {
		 	printf("#");
			 printf("\a");
			 Record(); 
		 }
		 
		 goto_xy(point.x,point.y);
	 }
  } 
  
 
 //下棋
 void Play(char ch)
 {
 	if(ch == 'w'|| ch == 'W')
 	{
 		if(point.y<=3)
 		point.y=20;
 		else 
 		    point.y--;
 		goto_xy(point.x,point.y);
	 }
	 
	 if(ch == 97|| ch == 65)
 	{
 		if(point.x<=10||point.x==11)
 		point.x=45;
 		else 
 		    point.x-=2;
 		goto_xy(point.x,point.y);
	 }
	 
	 if(ch == 68|| ch == 100)
 	{
 		if(point.x>=44)
 		point.x=11;
 		else 
 		    point.x+=2;
 		goto_xy(point.x,point.y);
	 }
	 
	 if(ch == 83|| ch == 115)
 	{
 		if(point.y>=20)
 		point.y=3;
 		else 
 		    point.y++;
 		goto_xy(point.x,point.y);
	 }
	 
	 if(ch == 13)
	 {
	 	PutDown();
	 }
	 
	 
	 if(button == 'b'|| button == 'B')
	 {
	 	ptr1=p;
	 	if(p!=head)
	 	{
	 		p=p->fore;
	 		free(ptr1);
	 		point.x = p->corrd.x;
	 		point.y = p->corrd.y;
	 		go_back(point.x,point.y);
		 }
	 }
	 
 }
 int Judge()
 {
 	int  count=0,c,r,cc,rr;
 	int pp=player==0?2:1;
 	
 	for(c=0;c<200;c++)
 	{   
 	    
 		for(r=0;r<200;r++)
 		{
 			if(Q[r][c] != pp )
 		
 			continue;

 			//检查列
			 rr=r;
			 cc=c;
			 while((--cc>=3)&&Q[rr][cc] == pp) 
			
				 count++;
			
			  cc=c;
			  while((++cc<23) && Q[rr][cc] == pp)
			  count++;
			  cc = c;
			  
			  if(count>=4)
			    return pp;
			//检查行
			 count=0;
			  while((rr-=2)>=10 && Q[rr][cc] == pp)
			    count++;
			   rr=r;
			  while((rr+=2)<44 && Q[rr][cc] == pp)
			   count++;
			   rr=r;
			  
			  if(count>=4)
			   return pp; 
			   count=0;
			   //检查反斜边
			    
			    rr-=2;
			    cc--;
			    while((cc>=3||rr>=10) && Q[rr][cc] == pp)
			    {
			    	count++;
			    	rr-=2;
			    	cc--;
				}
			    rr=r;
			    cc=c;
			    rr+=2;
			    cc++;
			    while((cc<23||rr<44) && Q[rr][cc] == pp)
			    {
			    	count++;
			    	rr+=2;
			    	c++;
				}
				rr=r;
				cc=c;
				if(count >= 4)
				  return pp;
				  count=0;
				  
				  //检查正斜边
				  
				  rr-=2;
				  cc++;
				  while((cc<23||rr>=10) && Q[rr][cc] == pp)
				  {
				  	count++;
				  	rr-=2;
				  	cc++;
				  }
				   rr=r;
				   cc=c;
				   rr+=2;
				   cc--;
				   while((cc>=3||rr<44) && Q[rr][cc] == pp)
				   {
				   	count++;
				   	rr+=2;
				   	cc--;
				   }
				   rr=r;
				   cc=c;
				   if(count>=4)
				    return pp;
				    count=0;
			    
		 }
	 }
 }
 
 //重新开始
 void Begin()
 {
    system("cls");
    goto_xy(40,15);
    printf("你已选择重新开始！！"); 
    Sleep(1000);
 	Draw();
  } 
 

int main()
{

	system("color 4E");
	printf("\n               欢迎来到五子峡谷！");
	goto_xy(15,3);
	printf("作者：你博哥~");
	goto_xy(17,5);
	printf("Welcome!");
	Sleep(3000);
	system("cls");

	
	while(1)
	{
		//startchoice =0; 
		Init(); 
		winner=0;
		Welcome();
		
		while(1)
		{
			
			bput(Str);
			if(startchoice!=0)
			{
				printf("\a"); 
				break;
			}
		 } 
		 
		 if(startchoice == 1)
		 {
		 	Draw(); // 布置棋盘 
		 	
		 	goto_xy(17,22);
		 	printf("轮到甲方落子。");
			 goto_xy(point.x,point.y);
			 
			 while(1)
			 {
			 	/*测试： 
			 	      goto_xy(18,25);
			 	      printf("M%d",player);*/
			 	button = getch();
			 	Play(button);
			 	if(button == 27)
			 	{
			 			if(MessageBox(NULL,TEXT("  确定退出？"),TEXT(""),MB_ICONQUESTION|MB_OKCANCEL)==IDOK) 
		 	        {
		 	        	goto_xy(30,25);
		 		           printf("\n\n          谢谢使用！\n");
		 		            return 0;
			        }
				 }
				 
				 if(button == 114 || button == 82)
				 {
				 	Begin();
				 }
				 
				 if(button == 13)
				 {
				 	winner=Judge();
				 }
				 
				 if(winner!=0)
				 {
				 	goto_xy(15,24);
				 	if(winner == 2)
				 	{
				 		printf("恭喜！甲方赢！\n");
					 }
					 if(winner == 1)
					 {
					 	printf("恭喜！乙方赢！\n");
					 }
				 }
				 
				 if(winner!=1&&winner!=2)
				 {
				 	continue;
				 }
				 
				 goto_xy(13,22);
	                printf("   继续游戏？(Y/N):   ");
	                while(1)
	                {
	                	button = getch();
	                	if(button == 'n'||button == 'N'|| button == 'y' || button == 'Y')
	                	  break;
					}
					
					if(button == 'n'||button == 'N')
					{

					if(MessageBox(NULL,TEXT("  确定退出？"),TEXT(""),MB_ICONQUESTION|MB_OKCANCEL)==IDOK) 
		              	{
		              		system("cls");
		 	              	printf("\n\n          谢谢使用！\n");
		 		             return 0;
			            }
			    	}
			    	
			    	if(button == 'y'||button == 'Y')
			    	{
			    		winner=0;
			    		system("cls");
			    		break;
					}
			    	
			  } 
		 
		 }
		 
		 
		 if(startchoice == 2)
		 {
		 	if(MessageBox(NULL,TEXT("  确定退出？"),TEXT(""),MB_ICONQUESTION|MB_OKCANCEL)==IDOK) 
		 	{
		 		printf("\n\n          谢谢使用！\n");
		 		return 0;
			 }
		 }
		
	
	}
	
		return 0;
}
