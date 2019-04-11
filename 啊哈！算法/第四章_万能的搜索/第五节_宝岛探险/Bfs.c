/*0表示海洋，1~9表示陆地，数字大小代表海拔高度
小哼的飞机降落在(6,8)处，现要计算出小哼将落地所在岛屿的面积(即有多少个格子)
注意此处我们把与小哼降落点上下左右相连接的陆地均视为同一岛屿
*/
#include "stdio.h"
struct note 
{
	int x;//横坐标
	int y;//纵坐标
};

int main()
{
	struct note que[2501];
	int head,tail;
	int a[51][51];
	int book[51][51] = {0};
	int i,j,k,sum,max = 0,mx,my,n,m,startx,starty,tx,ty;

	//定义一个表示走的方向的数组
	int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};//分别表示向右，向下，向左，向上走
	//读入n行m列以及小哼降落的坐标
	scanf("%d %d %d %d",&n,&m,&startx,&starty);

	//读入地图
	for(i = 1;i <= n;i++)
	{
		for(j = 1;j <= m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

	//队列初始化
	head = 1;
	tail = 1;
	//往队列插入降落的起始坐标
	que[tail].x = startx;
	que[tail].y = starty;
	tail++;
	book[startx][starty] = 1;
	sum = 1;

	//当队列不为空时循环
	while(head < tail)
	{
		//枚举四个方向
		for(k = 0;k <= 3;k++)
		{
			//计算下一步的坐标
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];

			//判断是否越界
			if(tx < 1 || tx > n || ty < 1 || ty > m)
			{
				continue;
			}

			//判断是否是陆地或之前是否走过
			if(a[tx][ty] > 0 && book[tx][ty] == 0)
			{
				sum++;
				//每个点只入队列一次，所以要标记这个点已经走过
				book[tx][ty] = 1;
				//将扩展的点加入到队列
				que[tail].x = tx;
				que[tail].y = ty;
				tail++;
			}
		}
		head++;//注意这个地方千万不能忘记，当一个点扩展结束后，head++才能继续往下扩展
	}
	//最后输出岛屿的大小
	printf("%d\n",sum );

	getchar();getchar();
	return 0;
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