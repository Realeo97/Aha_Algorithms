/*0表示海洋，1~9表示陆地，数字大小代表海拔高度
小哼的飞机降落在(6,8)处，现要计算出小哼将落地所在岛屿的面积(即有多少个格子)
注意此处我们把与小哼降落点上下左右相连接的陆地均视为同一岛屿
*/
#include "stdio.h"
int a[51][51],book[51][51];
int n,m,sum;
void dfs(int x,int y)
{

	//定义一个表示走的方向的数组
	int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};//分别表示向右，向下，向左，向上走
	int k,tx,ty;

	//枚举四个方向
	for(k = 0;k <= 3;k++)
	{
		tx = x + next[k][0];
		ty = y + next[k][1];
		//判断是否是边界
		if(tx < 1 || tx > n || ty < 1 || ty > m)
		{
			continue;
		}
		//判断是否为陆地或已经走过
		if(a[tx][ty] > 0 && book[tx][ty] == 0)
		{
			sum++;
			book[tx][ty] = 1;//标记这个点已经走过
			dfs(tx,ty);//开始尝试下一个点
		}
	}
	return;
}

int main()
{
	int i,j,startx,starty;
	scanf("%d %d %d %d",&n,&m,&startx,&starty);
	//读入地图
	for(i = 1;i <= n;i++)
	{
		for(j = 1;j <= m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	book[startx][starty] = 1;
	sum = 1;
	//从降落位置开始
	dfs(startx,starty);
	//最后输出岛屿的大小
	printf("%d\n",sum );
	getchar();getchar();
	return 0 ;
}
/*
示例输入：
10 10 6 8
1 2 1 0 0 0 0 0 2 3
3 0 2 0 1 2 1 0 1 2
4 0 1 0 1 2 3 2 0 1
3 2 0 0 0 1 2 4 0 0 
0 0 0 0 0 0 1 5 3 0
0 1 2 1 0 1 5 4 3 0
0 1 2 3 1 3 6 2 1 0
0 0 3 4 8 9 7 5 0 0
0 0 0 3 7 8 6 0 1 2
0 0 0 0 0 0 0 0 1 0
示例输出：
38
*/