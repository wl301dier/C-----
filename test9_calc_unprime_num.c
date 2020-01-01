/*将所有大于1小于整数m的非素数存入xx所指数组中，非素数的个数，
 *通过k传回。例如，若输入：17，则输出：4，6，8，9，10，12，14，15，16.
*/
#include<stdio.h>

void fun(int m,int *k,int xx[]){
	int i,j;

	*k =0;
	for(i=2;i<m;i++){        //大于1小于整数m本身，也就是从2到m-1
		for(j=2;j<i;j++){    //判断i是不是素数
			if(i%j==0){      //i对2到i-1内任何一个数求余为0，则说明i是非素数
				xx[*k]=i;    //是非素数，将此非素数赋值给数组xx。k是指针，*k用于非素数的计数
				(*k)++;      //指针指向的的内容加1，数组下标向后移，防止下次赋值时，内容被覆盖
				break;
			}
		}
	}
}

int main(){
	int m,n,zz[100];
	printf("\nPlease enter an integer number between 10 and 100:");
	scanf("%d",&n);
	fun(n,&m,zz);
	printf("\n\nThere are %d:",m,n);
	for(n=0;n<m;n++){
		printf("\n %4d",zz[n]);
	}
	return 0;
}
