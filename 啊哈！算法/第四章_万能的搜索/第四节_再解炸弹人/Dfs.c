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
	将炸弹放置在(7,11)处，最多可消灭11个敌人
*/
#include "stdio.h"
char a[20][21];
int book[20][20],max,mx,my,n,m;
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

void dfs(int x,int y)
{
	//定义一个表示走的方向的数组
	int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};//分别表示向右，向下，向左，向上走
	int k,sum,tx,ty;
	//计算当前这个点可以消灭的敌人总数
	sum = getnum(x,y);

	//更新max的值
	if(sum > max)
	{
		//如果当前点统计出所能消灭敌人数大于max，则更新max，并用mx，my记录当前点的坐标
		max = sum;
		mx = x;
		my = y;
	}

	//枚举4个方向
	for(k= 0;k <= 3;k++)
	{
		//下一个点的坐标
		tx = x + next[k][0];
		ty = y + next[k][1];
		//判断是否越界
		if(tx < 0 || tx > n - 1 || ty < 0 || ty > m - 1)
		{
			continue;
		}
		//判断是否是围墙或者已经走过
		if(a[tx][ty] == '.' && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;//标记这个点已经走过
			dfs(tx,ty);//开始尝试下一个点
		}
	}
	return;
}

int main()
{
	int i,startx,starty;

	//读入n和m，n表示有多少行字符，m表示有多少列字符
	scanf("%d %d %d %d",&n,&m,&startx,&starty);

	//读入n行字符
	for(i = 0;i <= n - 1;i++)
	{
		scanf("%s",a[i]);
	}

	//从小人所站的位置开始尝试
	book[startx][starty] = 1;
	max = getnum(startx,starty);
	mx = startx;
	my = starty;
	dfs(startx,starty);

	printf("将炸弹放在(%d,%d)处，可以消灭%d个敌人\n",mx,my,max );
	getchar();getchar();
	return 0;
}