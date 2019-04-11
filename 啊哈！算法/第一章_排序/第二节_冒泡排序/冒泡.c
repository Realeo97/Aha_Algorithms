/*冒泡排序的基本思想是：每次比较两个相邻的元素，如果它们的顺序错误就把它们交换过来。*/
/*冒泡排序的时间复杂度为O(N²)*/
//#include <stdio.h>
//int main()
//{
//	int a[100], i, j, t, n;
//	scanf("%d", &n); //输入一个数n，表示接下来有n个数
//	for(i = 1; i <= n; i++) //循环读入n个数到数组a中
//		scanf("%d", &a[i]);
//	//冒泡排序的核心部分
//	for (i = 1; i <= n - 1; i++) //n个数排序，只用进行n-1趟
//	{
//		for (j = 1; j <= n - i; j++) //从第1位开始比较直到最后一个尚未归位的数，想一想为什么到n - i就可以了。
//		{
//			if (a[j]<a[j + 1]) //比较大小并交换
//			{
//				t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
//			}
//		}
//	}
//	for (i = 1; i <= n; i++) //输出结果
//		printf("%d ", a[i]);
//	getchar(); getchar();
//	return 0;
//}
/************************************************
 示例输入：                                     *
	10                                          *
	8 100 50 22 15 6 1 1000 999 0               *
示例输出：                                      *
	0 1 6 8 15 22 50 100 999 1000               *
*************************************************/

#include <stdio.h>
struct student
{
	char name[21];
	char score;
};//这里创建了一个结构体用来存储姓名和分数
int main()
{
	struct student a[100], t;
	int i, j, n;
	scanf("%d", &n); //输入一个数n
	for (i = 1; i <= n; i++) //循环读入n个人名和分数
		scanf("%s %d", a[i].name, &a[i].score);
	//按分数从高到低进行排序
	for (i = 1; i <= n - 1; i++)
	{
		for (j = 1; j <= n - i; j++)//理解j <= n - i
		{
			if (a[j].score<a[j + 1].score)//对分数进行比较从大到小排列
			{
				t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;//结构体的数据的替换
			}
		}
	}
	for (i = 1; i <= n; i++)//输出人名
		printf("%s\n", a[i].name);
	getchar(); getchar();
	return 0;
}
/************************************************
 示例输入：                                     *
	5                                           *
	huhu 5                                      *
	haha 3                                      *
	xixi 5                                      *
	hengheng 2                                  *
	gaoshou 8                                   *
示例输出：                                      *
	gaoshou                                     *
	huhu                                        *
	xixi                                        *
	haha                                        *
	hengheng                                    *
*************************************************/