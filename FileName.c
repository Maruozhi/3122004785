#include<stdio.h>

//�ó���Ϊ�ؼ�����ͬ�̶ȵļ��

 int read() {
	//fp1Ϊԭ�ģ�fp2Ϊ���� 
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
	int a = 0, b = 0, c = 0;//aΪԭ�ģ�bΪ���ģ�cΪ�ظ���
	int flag = 0;//��־��0���ҵ��ظ���1����
	char c1, c2;
	for (;;a++) {
		//ԭ��ѭ�����˽���
		if (feof(f1))  break;
		//����ѭ�����˽���
		if (feof(f2))  break;

		c1 = fgetc(f1);

		if (flag == 1) {
			//Ѱַʹ��f2ָ���ϴ�
			f2 = fp2;
			for (int o=0;o<b;o++) {
				c2 = fgetc(f2);
			}
		}
		//��ѯ��ǰλ�ü�����λ�Ƿ���ͬ
		for (int i=0;i<5;i++) {
			//�ظ�ִ�����
			c2 = fgetc(f2);
			if (c1 == c2) {
				c++;//�ظ��ȼ�һ
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
	printf("������Ϊ:%.2f%%", r);
	fclose(fp1);
	fclose(fp2);
}



int main()
{
	read();
}