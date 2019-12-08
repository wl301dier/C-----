/*学生的记录由学号和成绩组成。N名学生的数据已在主函数中放入结构体数组s中，
* 请编写函数fun，它的功能是：把高于等于平均分的学生数据放在b所指的数组中，
* 高于等于平均分的学生人数通过形参n传回，平均分通过函数值返回。
* 请勿改动主函数main和其他函数中的任何内容，仅在函数fun的花括号中填入你编写的若干语句
*/
#include <stdio.h>
#include <string.h>

#define N 12
typedef struct {
	char num[10];
	double s;
}STREC;

double fun(STREC *a, STREC *b, int *n){
	int i,j = 0;
	double sum = 0; 
	double ave = 0.00; 
	int bigger = 0;

	//遍历数组a计算平均分
	for(i = 0; i < N; i++){
		sum += a[i].s;
	}
	ave = sum/N;//计算平均分

	//将大于平均分的信息放入数组b中
	for(i = 0; i < N; i++){
		if(a[i].s > ave){
			b[j].s = a[j].s;
			strcpy(b[j].num, a[j].num);

			j++;
			bigger++;
		}
	}
	*n = bigger;//将大于平均分的人数bigger通过指针n返回

	return ave;//返回平均分
}

int main(){
	STREC s[N]={{"GA05",85},{"GA03",76},{"GA02",69},{"GA04",85},{"GA01",91},{"GA07",72},
	{"GA08",64},{"GA06",87},{"GA09",60},{"GA11",79},{"GA12",73},{"GA10",90}};
	STREC h[N], t; FILE *out;
	int i, j, n;
	double ave;

	ave = fun(s, h, &n); //获取平均分ave，大于平均分的人数n和信息h

	//输出大于平均分ave的学生信息h
	printf("The %d student data which is higher than %7.3f:\n", n, ave);
	for(i = 0; i < n; i++)
		printf("%s %4.1f\n", h[i].num, h[i].s);

	printf("\n");
	out = fopen("out.data", "w");
	fprintf(out, "%d\n%7.3f\n", n, ave); //将大于平均分的人数n和平均分ave写入文件out.data
	
	//利用冒泡排序算法将大于平均分的成绩按由大到小排序
	for(i = 0; i < n-1; i++)
		for(j = i + 1; j < n; j++)//将i之后的每个大于h[i]的，都与h[i]进行内容交换。这样每次内层循环完以后h[i]就变成h[i]之后的最大值
			if(h[i].s < h[j].s){
				t = h[i];
				h[i] = h[j];
				h[j] = t;
			}

	//将排序后的结果写到文件
	for(i = 0; i < n; i++){
		printf("%4.1f\n", h[i].s);
		fprintf(out, "%4.1f\n", h[i].s);
	}
	fclose(out);

	return 0;
}
