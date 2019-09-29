/*问题描述
 *使用数字模拟星星
 *模拟一次的点击消除
 * 规则：
 * 1.点击的星星周围（上下左右）有颜色相同的就删掉。递归删掉周围相连接所有的相同的节点。
 * 2.删掉的上面的会落下 一列如果最后的一个删掉了，就是没有了的话，它左边的会右移过来。
 * 3.显示点击以后的面板  
 *
 *
 *
 */
#include<stdio.h>
#define M 10
#define N 10
#define click1 3
#define click2 4
int pos[4][2]={{0,1},
	       {0,-1},
	       {1,0},
	       {-1,0}};
enum color{green,yellow,red,blue,purple};
       //  0     1      2   3    4
int board[M][N]={
	        {0,0,0,1,2,4,3,0,2,1},
		{2,2,0,3,2,0,3,4,1,3},
		{2,2,4,4,0,2,2,4,1,2},
		{2,1,1,1,2,1,3,3,4,2},
		{2,3,4,3,4,2,1,2,0,0},
		{3,4,2,1,1,2,0,3,4,2},
		{1,3,2,1,4,3,2,1,0,3},
		{2,3,1,0,2,1,0,0,3,2},
		{2,0,0,2,3,1,1,4,2,1},
		{2,3,4,2,1,1,2,3,4,0}};
void print()
{
	printf("-------------------------\n");
	int i,j;
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%d ",board[i][j]);
		}
		printf("\n");
	}
}

void delete(int i,int j)
//1.先找一个的上下左右是不是相同的，如果相同的值就改为-1再递归上下左右其他的
//2.记住最上面的坐标，然后找最小的
//3.
{
     int value=board[i][j];
     if(i<0||i>=M||j<0||j>=N||value==-1)
	     return ;
     else
     {
	     int m;
	     for(m=0;m<4;m++)
	     {
		     
			     int t=i+pos[m][0];
			     int t1=j+pos[m][1];
			     if(t>=0&&t<M&&t1>=0&&t1<N&&board[t][t1]==value&&value!=-1)
				     board[t][t1]=-1;
	     }
	     for(m=0;m<4;m++)
	     {
		     
			     int t=i+pos[m][0];
                             int t1=j+pos[m][1];	   
                             delete(t,t1);
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
	     for(i=0;i<M;i++)
         {
	     for(j=0;j<N;j++)
	     {
		     if(i==click1&&j==click2)
		     {
			     delete(i,j);
		     }
	     }
         }
	 print();
     }
}
