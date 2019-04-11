/*迷宫最短路径问题，0表示可通过，1表示障碍物不能通过*/
#include "stdio.h"
int n,m,p,q,min = 99999999;
int a[51][51],book[51][51];
void dfs(int x,int y,int step)
{
	int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};//next为方向数组，分别代表向右，向下，向左，向上走
	int tx,ty,k;
	//判断是否到达终点
	if(x == p && y == q)
	{
		//更新最小值
		if(step < min)
		{
			min = step;
		}
		return;//请注意这的返回很重要
	}

	//枚举四种走法
	for(k = 0;k <= 3;k++)
	{
		//计算下一个点的坐标
		tx = x + next[k][0];
		ty = y + next[k][1];
		//判断是否越界
		if(tx < 1 || tx > n || ty < 1 || ty > m)
		{
			continue;//跳过本次循环
		}
		//判断改点是否为障碍物或已在路径中
		if(a[tx][ty] == 0 && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;//标记这个点已经走过
			dfs(tx,ty,step + 1);//开始尝试下一个点
			book[tx][ty] = 0;//尝试结束，取消这个点的标记
		}
	}
	return;
}

int main()
{
	int i,j,startx,starty;
	//读入n和m,n为行，m为列
	scanf("%d%d",&n,&m);
	//读入迷宫
	for(i = 1;i <= n;i++)
	{
		for(j = 1; j <= m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	//读入起点和终点坐标
	scanf("%d %d %d %d",&startx,&starty,&p,&q);

	//从起点开始搜索
	book[startx][starty] = 1;//标记起点已经在路径中，防止后面重复走
	dfs(startx,starty,0);//第一个参数是起点x的坐标，第二个参数是起点y的坐标，第三个参数是初始步数为0

	//输出最短步数
	printf("%d\n",min);
	getchar();getchar();
	return 0 ;	
}
/*********
示例输入：
5 4
0 0 1 0
0 0 0 0 
0 0 1 0
0 1 0 0 
0 0 0 1
1 1 4 3
示例输出：
7
************/