/*统计一行字符串中单词的个数，作为函数值返回。一行字符串在主函数中输入，
 *规定所有单词由小写字母组成，单词之间由若干个空格隔开，一行的开始没有空格。
*/
#include<stdio.h>
#include<string.h>
#define N 80

int fun(char *s){
	int i = 0;
	int j = 0;						//作为单词计数使用
	int findNewWord = 1;			//遇到单词的标志
	for(i=0;i<N;i++){
		if(*(s+i) == ' '){			//当前是空格
			if(findNewWord == 1){	//判断空格前一个字符是否是单词
				j++;				//单词计数加 1
			}
			findNewWord = 0;//将标志置为0，以便于告诉后面前一个字符不是单词
		}else{
			findNewWord = 1;//当前是单词，将标志置为1，以便于告诉后面前一个字符是单词
		}
	}
	if(findNewWord == 1){//判断结束时，前一个字符是否为单词。主要考虑，字符串结尾无空格的情况
		j++;//是单词，计数加1，以便能够正确统计所有单词
	}
	return j;
	
}

int main(){
	char line[N];
	int num = 0;
	printf("Enter a string:\n");
	gets(line);
	num=fun(line);
	printf("The num of word is : %d\n\n",num);
	return 0;
}
