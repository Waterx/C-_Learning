#include<stdio.h>
#include<stdlib.h>
#include<time.h>
FILE* fp;

int main() {

	//��ȡ����
	int array[2000];
	int i = 0;
	fp = fopen("data.txt", "r");
	char line[10];
	while (fgets(line, sizeof(line), fp)) {
		//printf("%s", line);//��Ԫ���������Ļ��
		array[i++] = atoi(line);
	}
	fclose(fp);
	
	//���ü�ʱ��ʼ
	double duration;
	clock_t  finish, start;
	start = clock();

	//����XXXXXXX
	

	//���ü�ʱ����
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;  // ͳ��ʱ��duration
	printf("\nThe CPU time is %2.6f seconds:\n", duration);

	//���������ļ�resultsXX.txt
	fp = fopen("results.txt", "w+");
	fprintf(fp, "Time = %f\n", duration);
	for (i = 0; i < 2000; i++) {
		fprintf(fp, "%d\n", array[i]);
	}
	return 0;
}
