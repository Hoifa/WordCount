#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 1024

int main(void) {
	char buf[MAX_NUM];			//�ַ�������
	FILE* fp;
	int len, total = 0;           //ÿ���ַ�������������
	if ((fp = fopen("input.txt", "r")) == NULL) {
		perror("the file fail to read");
		getchar();				//��ͣ��ʾ
		exit(1);
	}
	while (!feof(fp) && !ferror(fp)) {	
   //while(fgets(buf,MAX_NUM,fp) != NULL)
		fgets(buf, MAX_NUM, fp);
		len = strlen(buf);
		if (buf[len - 1] == '\n') {
			buf[len - 1] = '\0'; 
			len--;
		}
		if (len == 0) continue;	//�����հ���
		printf("%s %d \n", buf, len);
		total += len;
	}
	printf("This txt total number of worlds %d \n", total);
	fclose(fp);				//�ر��ļ�
	getchar();
	return 0;
}