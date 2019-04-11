//去重；排序
/*****************************************
示例输入：                               *
	10                                   *
	20 40 32 67 40 20 89 300 400 15      *
示例输出                                 *
	8                                    *
	15 20 32 40 67 89  300 400           *
******************************************/	
#include<stdio.h>
int a[101], n;
void quicksort(int left, int right)
{
	int i, j, t, temp;
	if (left > right)
		return;
	temp = a[left];
	i = left;
	j = right;
	while (i != j)
	{
		while (a[j] >= temp && i < j)
			j--;
		while (a[i] <= temp && i < j)
			i++;
		if (i < j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	a[left] = a[i];
	a[i] = temp;
	quicksort(left, i - 1);
	quicksort(i + 1, right);
	return;
}
int main()
{
	int i, j, k;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	quicksort(1, n);//先排序
	k = 1;//统计一共需买多少本书
	for (i = 2; i <= n; i++)
	{
		if (a[i] != a[i - 1])
			k++;
	}
	printf("%d\n", k);
	printf("%d ", a[1]);//从小到大依次输出
	for (i = 2; i <= n; i++)
	{
		if (a[i] != a[i - 1])
			printf("%d ", a[i]);
	}
	getchar();getchar();
	return 0;
}