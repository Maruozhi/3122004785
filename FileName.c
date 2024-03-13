#include<stdio.h>

//该程序为关键字相同程度的检测

 int read() {
	//fp1为原文，fp2为仿文 
	FILE* fp1,* fp2;
	fp1 = fopen("D:/text/text.txt", "r");
	fp2= fopen("D:/text/text_empty.txt", "r");

	if (fp1 == NULL) {

		perror("open file failed:");
		return;
	}
	if (fp2 == NULL) {

		perror("open file failed:");
		return;
	}

	FILE* f1 = fp1;
	FILE* f2 = fp2;
	int a = 0, b = 0, c = 0;//a为原文，b为仿文，c为重复数
	int flag = 0;//标志，0则找到重复，1则无
	char c1, c2;
	for (;;a++) {
		//原文循环完了结束
		if (feof(f1))  break;
		//仿文循环完了结束
		if (feof(f2))  break;

		c1 = fgetc(f1);

		if (flag == 1) {
			//寻址使得f2指向上次
			f2 = fp2;
			for (int o=0;o<b;o++) {
				c2 = fgetc(f2);
			}
		}
		//查询当前位置及后四位是否相同
		for (int i=0;i<5;i++) {
			//重复执行五次
			c2 = fgetc(f2);
			if (c1 == c2) {
				c++;//重复度加一
				flag = 0;
				break;
			}
			else {
				flag = 1;

			}
		}
		if (flag == 1)b--;
		b++;
	}

	float r =100* c / a;
	printf("查重率为:%.2f%%", r);
	fclose(fp1);
	fclose(fp2);
}



int main()
{
	read();
}