/*将大于形参m且仅靠m的k个素数存入xx所指的数组中。
 *例如，输入17，5，则应输出：19，23，29，31，37.
*/
#include<stdio.h>

int fun(int m){
	for(int i = 2;i<=m-1;i++){//如果m仅能被1和m自身整除（即，2到m-1都不能被m整除），则m是素数。
		if(m % i == 0){//发现整除可以马上return，可以判定不是素数
			return 1;
		}
	}
	return 0;//运行到这里，说明2到m-1都不能被m整除。即m是素数。
}

int main(){
	int m = 17;
	int n = 5;
	int i = 0;

	while(i<n){
		m++;
		if(fun(m)==0){
			i++;
			printf("%d ",m);
		}
	}
	printf("\n");
	return 0;
	
}
