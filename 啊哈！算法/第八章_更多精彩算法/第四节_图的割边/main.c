/*
割边(桥):即在一个无向连通图中，如何删除某条边之后，图不在连通
如果low[v]和num[u]相等则表示还可以回到父亲，而low[v] > num[u]则表示连父亲都回不到了。
倘若顶点v不能回到祖先，也没有另外一条路能回到父亲，那么u-v这条边就是割边
实际应用中需要改为邻接表来存储图，时间复杂度为OM((N + M)),否则时间复杂度为O(N2)
*/
#include "stdio.h"
int n,m,e[9][9],root;
int num[9],low[9],index;
int min(int a,int b)
{
	return a < b? a : b;
}

void dfs(int cur,int father)
{
	int i;

	index++;
	num[cur] = index;
	low[cur] = index;
	for(i = 1;i <= n;i++)
	{
		if(e[cur][i] == 1)
		{
			if(num[i] == 0)
			{
				dfs(i,cur);
				low[cur] = min(low[i],low[cur]);
				if(low[i] > num[cur])
				{
					printf("%d - %d\n",cur,i );
				}
			}
			else if(i != father)
			{
				low[cur] = min(low[cur],num[i]);
			}
		}
	}
	return;
}
int main()
{
	int i,j,x,y;
	scanf("%d %d",&n,&m);
	for(i = 1;i <= n;i++)
	{
		for(j = 1;j <= n;j++)
		{
			e[i][j] = 0;
		}
	}
	for(i = 1;i <= m;i++)
	{
		scanf("%d %d",&x,&y);
		e[x][y] = 1;
		e[y][x] = 1;
	}
	root = 1;
	dfs(1,root);
	getchar();getchar();
	return 0;
}
/*
示例输入：
6 6 		//第一行两个数n和m，n表示有n个顶点，m表示有m条边
1 4			//接下来m行，每行形如a,b表示顶点a和顶点b之间有边
1 3
4 2
3 2
2 5
5 6
示例输出：
5-6
2-5
*/ 