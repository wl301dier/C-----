/*
* 假定输入的字符串只包含字母和*号。请编写函数fun，实现除了字符串前导的*号之外，将串中其它的*号全部删除。
*/
#include <stdio.h>

void fun(char *a)
{
	int i = 0, k;
	int j = 0;
	while(a[i] == '*') //跳过开头的*号
	{
		i++;
	}

	k=i;
	while(a[i] != '\0') /* 以下程序段实现非*字符前移 */
	{
		if(a[i] == '*')
		{
			k = i; //从i开始处理
			while(a[k] != '\0')
			{
				a[k] = a[k+1]; //后项覆盖到前项
				k++;           //调整k继续往后走
			}
		}else
		{
			i++; //a[i]不是*才移动。防止后面出现连续*，出现连续*时i不能移动。
		}
	}
	a[k]='\0';
}

int main(){
	char s[81];
	printf("Enter a string:\n");
	gets(s);
	fun(s);
	printf("The string after deleted:\n");
	puts(s);

	return 0;
}
