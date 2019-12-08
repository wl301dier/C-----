/*函数fun的功能是：将a,b中的两个两位正整数合并形成一个新的整数放在c中，合并的方式是：
* 将a中的十位和个位数依次放在变量c的千位和十位上，b中的十位数和个位数依次放在变量c的
* 个位和百位上，例如，当a=45，b=12，输出 c=4251.
*/
#include <stdio.h>
int main(){
	int a = 45;
	int b = 12;
	int c = 0;
	int a1, a2;
	int b1, b2;

	a1 = a % 10;//取出a的个位数
	a2 = a / 10; //取出a的十位数
	
	b1 = b % 10;//取出b的个位数
	b2 = b / 10; //取出b的十位数
	
	c += a2 * 1000;
	c += b1 * 100;
	c += a1 * 10;
	c += b2;
	
	printf("%d\n",c); //输出c的结果

	return c;
}
