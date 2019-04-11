/*广度优先搜索解炸弹人*/
/*#表示墙、G表示敌人、.表示空地
问炸弹放在那个位置才可以消灭最多的敌人
示例输入：
	13 13 3 3
	#############
	#GG.GGG#GGG.#
	###.#G#G#G#G#
	#.......#..G#
	#G#.###.#G#G#
	#GG.GGG.#.GG#
	#G#.#G#.#.#.#
	##G...G.....#
	#G#.#G###.#G#
	#...G#GGG.GG#
	#G#.#G#G#.#G#
	#GG.GGG#G.GG#
	#############
示例输出：
	将炸弹放置在(7,11)处，最多可消灭10个敌人
*/
#include "stdio.h"
struct note
{
	int x;//横坐标
	int y;//纵坐标
};

char a[20][21];//用来存储地图

int getnum(int i,int j)
{
	int sum,x,y;
	sum = 0;//sum用来计数(可以消灭的敌人数)，所以需要初始化为0
	//将坐标i,j复制到两个新变量x,y中，以便之后上下左右四个方向统计可以消灭的敌人数
	//向上统计可以消灭的敌人数
	x = i;y = j;
	while(a[x][y] != '#')//判断的点是不是墙，如果不是墙就继续
	{
		//如果当前点是敌人，则进行计数
		if(a[x][y] == 'G')
			sum++;
		//x--的作用是继续向上统计
		x--;
	}

	//向下统计可以消灭的敌人数
	x = i;y = j;
	while(a[x][y] != '#')//判断的点是不是墙，如果不是墙就继续
	{
		//如果当前点是敌人，则进行计数
		if(a[x][y] == 'G')
			sum++;
		//x--的作用是继续向上统计
		x++;
	}

	//向右统计可以消灭的敌人数
	x = i;y = j;
	while(a[x][y] != '#')//判断的点是不是墙，如果不是墙就继续
	{
		//如果当前点是敌人，则进行计数
		if(a[x][y] == 'G')
			sum++;
		//x--的作用是继续向上统计
		y++;
	}

	//向左统计可以消灭的敌人数
	x = i;y = j;
	while(a[x][y] != '#')//判断的点是不是墙，如果不是墙就继续
	{
		//如果当前点是敌人，则进行计数
		if(a[x][y] == 'G')
			sum++;
		//x--的作用是继续向上统计
		y--;
	}
	return sum;
}

int main()
{
	struct note que[401];//假设地图大小不超过20*20，因此队列扩展不会超过400个
	int head,tail;
	int book[20][20] = {0};//定义一个标记数组并全部初始化为0
	int i,j,k,sum,max = 0,mx,my,n,m,startx,starty,tx,ty;

	//定义一个表示走的方向的数组
	int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};//分别表示向右，向下，向左，向上走

	//读入n和m，n表示有多少行字符，m表示有多少列字符
	scanf("%d %d %d %d",&n,&m,&startx,&starty);

	//读入n行字符
	for(i = 0;i <= n - 1;i++)
	{
		scanf("%s",a[i]);
	}

	//队列初始化
	head = 1;
	tail = 1;
	//往队列插入小人的起始坐标
	que[tail].x = startx;
	que[tail].y = starty;
	tail++;
	book[startx][starty] = 1;
	max = getnum(startx,starty);
	mx = startx;
	my = starty;
	//当队列不为空时循环
	while(head < tail)
	{
		//枚举四个方向
		for(k = 0;k <= 3;k++)
		{
			//尝试走下一个点的坐标
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];

			//判断是否越界
			if(tx < 0 || tx > n - 1  || ty < 0 || ty > m - 1)
			{
				continue;
			}

			if(a[tx][ty] == '.' && book[tx][ty] == 0)
			{
				//每个点只入队一次，所以需要标记这个点已经走过
				book[tx][ty] = 1;
				//插入行扩展的点到队列中
				que[tail].x = tx;
				que[tail].y = ty;
				tail++;

				//统计当前性扩展的点可以消灭的敌人总数
				sum = getnum(tx,ty);
				//跟新max的值
				if(sum > max)
				{
					//如果当前统计出所能消灭敌人数大于max，则更新max，并用mx和my记录改点
					max = sum; 
					mx = tx;
					my = ty;
				}
			}
		}
		head++;//注意这个地方千万不能忘记，当一个点扩展结束后，必须要对head++后才能对后面的点进行扩展
	}

	//最后输出这个点和最多可以消灭的敌人总数
	printf("将炸弹放在(%d,%d)处，可以消灭%d个敌人\n",mx,my,max );
	getchar();getchar();
	return 0;
}