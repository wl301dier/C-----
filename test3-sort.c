#include <stdio.h>
#define N 10

int main(){
	int i = 0;
	int j = 0;
	int t;
	int a[N] = {4,6,8,45,23,9,13,21,15,18};

	for(i = 0; i < N-1; i++){//i从0到倒数第二项
		for(j = i + 1; j < N; j++){//j从i-1项到最后一个
			if(a[i] < a[j]){//如果发现a[j]比a[i]大，则进行交换。最后a[i]成为a[i+1]到a[N]的最大项，则最大数
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	for(i = 0; i < N; i++)
		printf("%d\n", a[i]);
	return 0;
}


