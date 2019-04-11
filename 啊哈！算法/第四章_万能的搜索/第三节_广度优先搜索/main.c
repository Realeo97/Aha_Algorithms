/*层层递进-广度优先搜索*/

#include "stdio.h"
struct note
{
	int x;//横坐标
	int y;//纵坐标
	int f;//父亲在队列中的编号，本题不要求输出路径，可以不需要f
	int s;//步数
}; 

int main()
{
	struct note que[2501];//因为地图大小不超过50*50，因此队列扩展不会超过2500个

	int a[51][51] = {0},book[51][51] = {0};
	//定义一个用于表示走的方向的数组
	int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};//分别表示向右，向下，向左，向上
	int head,tail;
	int i,j,k,n,m,startx,starty,p,q,tx,ty,flag;

	scanf("%d %d",&n,&m);
	for(i = 1;i <= n;i++)
	{
		for(j = 1;j <= m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d %d %d %d",&startx,&starty,&p,&q);

	//队列初始化
	head = 1;
	tail = 1;
	//往队列插入迷宫坐标
	que[tail].x = startx;
	que[tail].y = starty;
	que[tail].f = 0;
	que[tail].s = 0;
	tail++;
	book[startx][starty] = 1;

	flag = 0;//用来标记是否到达目标点，0表示暂时没有到达，1表示到达
	//当队列不为空时循环
	while(head < tail)
	{
		//枚举4个方向
		for(k = 0;k <= 3;k++)
		{
			//计算下一个点的坐标
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];
			//判断是否越界
			if(tx < 1 || tx > n || ty < 1 || ty > m)
			{
				continue;//跳出此次循环
			}
			//判断是否是障碍物或者已经在路径中
			if(a[tx][ty] == 0 && book[tx][ty] == 0)
			{
				//把这个点标记为已经走过
				//注意宽搜每个点只入队列一次，所以和深搜不同，不用将book数组还原
				book[tx][ty] = 1;
				//插入新的点到队列之中
				que[tail].x = tx;
				que[tail].y = ty;
				que[tail].f = head;//因为这个点是从head扩展出来的，所以他的父亲就是head，本题目不需要求路径，因此本句可省略
				que[tail].s = que[head].s + 1;//步数是父亲的步数加1
				tail++;
			}
			//如果到目标点了，停止扩展，任务结束，退出循环
			if(tx == p && ty == q)
			{
				//注意下面两句话千万不要写颠倒了
				flag = 1;
				break;
			}
		}
		if(flag == 1)
		{
			break;
		}
		head++;//全部出列，注意这地方千万不要忘记，当一个点扩展结束后，head++才能对后面的点再进行扩展
	}
	//打印队列中末尾最后一个点(目标点)的步数
	//注意tail指向的是队列队尾(即最后一为)的下一个位置，所以这里需要-1
	printf("%d\n",que[tail - 1].s );
	getchar();getchar();
	return 0;
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