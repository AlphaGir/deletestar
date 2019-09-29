/*问题描述
 *使用数字模拟星星
 *模拟一次的点击消除
 * 规则：
 * 1.点击的星星周围（上下左右）有颜色相同的就删掉。递归删掉周围相连接所有的相同的节点。
 * 2.删掉的上面的会落下 一列如果最后的一个删掉了，就是没有了的话，它左边的会右移过来。找到所有相关点以后，记录在数组里，然后如果是同一列的点 就从最小的开始找直到找到最上面的点，然后把最最上面的点和最小的交换位置。如果是同一列最后一个点直接让上面的依次下面覆盖。消失的值为-1 ，把存起来的值 相同列的进行处理 下移。找到这行里最小的还有删掉个数然后依次下移这么多个， 其余直接赋值-1。
 * 3.显示点击以后的面板  
 *
 *
 *
 */
#include<stdio.h>
#define M 10
#define N 10
#define click1 9
#define click2 4
typedef struct point
{
	int v;
	int flag;
}point;
typedef struct location
{
	int a;
	int b;
}location;
typedef struct pe
{
	int per;//同一列的个数 频率
	int index;//同一列横坐标
	location low;//同一列最小的
	location high;//同一列最大的
	location loca[100];//同一列总存储
}pe;
pe pp[10];
int count=0;
location l[100];
void printloc(int len);
int pos[4][2]={{0,1},
	       {0,-1},
	       {1,0},
	       {-1,0}};
enum color{green,yellow,red,blue,purple};
       //  0     1      2   3    4
int board[M][N]={
	        {0,0,0,1,2,4,3,5,2,1},
		{2,2,0,3,2,0,3,5,1,3},
		{2,2,4,4,0,2,2,5,1,2},
		{2,1,1,1,2,1,3,5,4,2},
		{2,3,4,3,4,2,1,5,0,0},
		{3,4,2,1,1,2,0,5,4,2},
		{1,3,2,1,4,3,2,5,0,3},
		{2,3,1,0,2,1,0,5,3,2},
		{2,0,0,2,3,1,1,5,2,1},
		{2,3,4,2,1,1,2,5,4,0}};
point p[M][N];
void setvalue()
{
	int i,j;
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			p[i][j].v=board[i][j];
			p[i][j].flag=0;
		}
	}
}
void print()
{
	printf("-------------------------\n");
	int i,j;
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%d ",p[i][j].v);
		}
		printf("\n");
	}
}

void delete(int i,int j)
//1.先找一个的上下左右是不是相同的，如果相同的值就改为-1再递归上下左右其他的
//2.记住最上面的坐标，然后找最小的
//3.
{
     int value=p[i][j].v;
     int f=0;
     if(i<0||i>=M||j<0||j>=N)
	     return ;
     else
     {
	     int m;
	     for(m=0;m<4;m++)
	     {
		     
			     int t=i+pos[m][0];
			     int t1=j+pos[m][1];
			     if(t>=0&&t<M&&t1>=0&&t1<N&&p[t][t1].v==value&&p[t][t1].flag!=1)
			     {   
				  p[t][t1].flag=1;
				  l[count].a=t;
				  l[count].b=t1;
				  count++;
				  delete(t,t1);
				  f=1;
			     }
	     }
	     
	     
	     
     }


}
/*
 *
typedef struct pe
{
        int per;//同一列的个数 频率
        int index;//同一列横坐标
        location low;//同一列最小的
        location high;//同一列最大的
}pe;
typedef struct location
{
        int a;
        int b;
}location;

 *
 *
 *
 *
 */

void move()//下移
{
     //1.首先找到同一列的，放在一起，然后计算个数。然后下移这么多个，然后上面的赋值-1.
     //
     int c,i,j;
     int t[100]={0};
     int x[10];
     c=0;
     for(i=0;i<count;i++)
     {
         t[l[i].b]++;
     }
     for(j=0;j<100;j++)
     {
	     if(t[j]>0)
	     {
	             pp[c].per=t[j];
	             pp[c].index=j;	  
		     pp[c].low.a=-1;
		     pp[c].low.b=-1;   
		     c++;
	     }
     }
    int tem=0;
    int yy;
    for(j=0;j<c;j++)
    {
	     for(i=0;i<count;i++)
	     {
		     if(pp[j].index==l[i].b)
		     {
			     pp[j].loca[tem].a=l[i].a;
			     pp[j].loca[tem].b=l[i].b;
			     tem++;
		            // printf("--%d %d --\n",l[i].a,l[i].b);
		     }
	     }
	     tem=0;
	     
    }
    tem=0;
    for(i=0;i<c;i++)
    {
	    pp[i].low=pp[i].loca[0];
	    for(j=0;j<pp[i].per;j++)
	    {

		   // printf("%d %d\n",pp[i].loca[j].a,pp[i].loca[j].b);
		    if(pp[i].per==1)
		    {
			    pp[i].low=pp[i].loca[0];
			 // printf("low:%d %d",pp[i].low.a,pp[i].low.b);
		    }
		    else
		    {
		    if(pp[i].loca[j].a>pp[i].low.a)
		    {
			    pp[i].low=pp[i].loca[j];
	                    		    
		    }
		    }
	    }
	    printf("\n");
    }
    printf("\n");
   // printloc(c);
    for(i=0;i<c;i++)
    {
	    
		    for(tem=pp[i].low.a;tem>0;tem--)
		    {

			 int right=pp[i].low.b;
			 int des=pp[i].per;
                         p[tem][right].v=p[tem-des][right].v;
			// printf(" left:%d right:%d value:%d\n",tem,right,p[tem][right].v);

		    }
		    for(j=0;j<pp[i].per;j++)
		    {
			    int temp=pp[i].low.a;
			    int right=pp[i].low.b;
			    p[j][right].v=5;
		    }
		    printf("\n");
    }
}
void printloc(int len)
{
	int i,j;
	for(i=0;i<len;i++)
	{
	//	printf("per:%d index:%d lowleft:%d right:%d\n",pp[i].per,pp[i].index,pp[i].low.a,pp[i].low.b);
	}
}
void left()//左移
{
     //如果一列全为-1 则最右边的值给全为-1这一项 其余列也得移动
     int c=0;
     int i,j;
     int ret,r1;
     for(i=0;i<M;i++)
     {       for(j=0;j<N;j++)
	     {
		     if(p[j][i].v==5)//这一列全部为-1
		     {
		       
                       c++;
		     }
	     }
	     ret=i;
	    
	     if(c==N)
	     {
		     for(int m=ret;m<N-1;m++)
		     for(i=0;i<N;i++)
		     {
			     p[i][m].v=p[i][m+1].v;
		     }
		     for(int n=0;n<N;n++)
			     p[n][N-1].v=5;
		     return;
	     }
     }
}
int main()
{
     int i,j;
     if(click1>=M||click2>=N)
	     printf("click again\n");
     else
     {
	     setvalue();
	     print();
	     printf("\n");
	/*     for(i=0;i<M;i++)
         {
	     for(j=0;j<N;j++)
	     {
		     if(i==click1&&j==click2)
		     {
			     
			     delete(i,j);
			     //print();
			     
		     }
	     }
         }*/
	 left();
	 print();
         //move();	 
	 //print();
     }
}
