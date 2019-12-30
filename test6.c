/*将s所指字符串中的内容中除了下标为偶数，同时ASCII码值为偶数的字符外，
 *其余的全都删除；串中剩余字符所形成的一个新串放在t所指的数组中。
 *例如，若s所指的字符串中的内容为:"ABCDEFG123456"，其中字符A的ASCII码值为奇数，
 *因此应当删除；其中字符B的ASCII码值为偶数，但在数组中的下标为奇数，因此也应当删除。
 *而字符2的ASCII码值为偶数，所在的数组中的下标也为偶数，因此不应当删除，其他以此类推.
 *最后t所指的数组中的内容为:"246"。
*/
#include<stdio.h>
#include<string.h>

void fun(char *s,char t[]){
	int i,j=0;
	for(i=0;i<strlen(s);i++){
		if(i%2==0){				//判断数组下标是否为偶数
			if(s[i]%2==0){		//判断数组s中字符的ASCII码值是否为偶数
				t[j++]=s[i];	//将数组中删除后的的字符放入新的数组t中
			}
		}
	}
	t[j]='\0';					//所有字符处理完后，在形成新字符串s的末尾加上结束符'\0'
}

int main(){
	char s[100],t[100];
	printf("\nPlease enter string S:");
	scanf("%s",s);
	fun(s,t);
	printf("\nThe result is:%s\n",t);
	return 0;
}
