/*
* 请编写fun函数的功能是：删去一维数组中所有相同的数，使之只剩一个。数组中的数已按由大到小的顺序排列，函数返回删除后数组中数据的个数。
* 例如，一维数组中的数据是：2，2，2，3，4，4，5，6，6，6，6，7，7，8，9，9，10，10，10，10.
* 删除后，数组中的内容应该是：2,3,4,5,6,7,8,9,10.
* 请勿改动主函数main和其他函数中的任何内容，仅在函数fun的花括号中填入你编写的若干语句。
*/

#include<stdio.h>
#define N 80

int fun(int a[], int n){
	int i, j;

	for (i = 0; i < n-1;){
		if (a[i] == a[i+1]){
			//借助j将a[i]之后的每一项覆盖到前项
			for (j = i; j < n-1; j++){
				a[j] = a[j+1];
			}

			n--; //每次挪动以后数组大小应减一
		} else {
			i++; //没有发生挪动时，i才加1
		}
	}

	return n;
}

main(){
	int a[N]={2,2,2,3,4,4,5,6,6,6,6,7,7,8,9,9,10,10,10,10},i,n=20;
	printf("The original data :\n");
	
	for(i = 0; i < n; i++)
		printf("%3d",a[i]);
	
	n=fun(a,n);
	printf("\n\nThe data after deleted:\n");
	
	for(i = 0; i < n; i++)
		printf("%3d",a[i]);

	printf("\n\n");
}
