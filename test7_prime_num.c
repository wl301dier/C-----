/*将大于形参m且仅靠m的k个素数存入xx所指的数组中。
 *例如，输入17，5，则应输出：19，23，29，31，37.
*/
#include<stdio.h>

int isPrimeNum(int m){
	for(int i = 2;i<=m-1;i++){//如果m仅能被1和m自身整除（即，2到m-1都不能被m整除），则m是素数。
		if(m % i == 0){//发现整除可以马上return，可以判定不是素数
			return 1;
		}
	}
	return 0;//运行到这里，说明2到m-1都不能被m整除。即m是素数。
}

void fun(int m,int n,int xx[]){
		int i = 0;
		for(;;){
			m++;
			if(isPrimeNum(m)==0){
				xx[i]=m;
				i++;
			}

			if(i==n){
				break;
			}
		}
}

void fun1(int m,int n,int xx[]){
		int i = 0;
		//for(;;)
		//while(1)
		while(m++){
			if(isPrimeNum(m)==0){
				xx[i]=m;
				i++;
			}

			if(i==n){
				break;
			}
		}
}

int main(){
	int m,n,zz[1000];
	printf("\nPlease enter two integers:");
	scanf("%d %d",&m,&n);
	fun(m,n,zz);
	for(m=0;m<n;m++){
		printf("%d ",zz[m]);
	}
	printf("\n");
	return 0;
}
