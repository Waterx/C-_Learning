#include<stdio.h>
#include<stdlib.h>
#include<time.h>
FILE* fp;
void Merge(int A[], int tmp[], int leftstart, int rightend) {
	//find the min num
	for (int i = leftstart; i < rightend; i++) {
		if (A[i] < tmp[0]) {
			tmp[0] = A[i];
		}
		if (A[i] > tmp[1]) {
			tmp[1] = A[i];
		}
	}
}
void Find(int A[], int tmp[], int Left, int Right) {
	int Center;
	if (Left < Right) {
		Center = (Left + Right) / 2;
		Find(A, tmp, Left, Center);
		Find(A, tmp, Center + 1, Right);
		Merge(A, tmp, Left, Right);
	}
}
void FindPartition(int A[], int N) {
	int tmp[2] = { A[0], A[1] };  //[0] is the temp min num, [1] is the temp max num
	Find(A, tmp, 0, N - 1);
	printf("Min : %d, Max : %d", tmp[0], tmp[1]);
}
int main() {

	//���ü�ʱ��ʼ
	double duration;
	clock_t  finish, start;
	start = clock();

	//------����ʵ����һ���ж�ȡ����-------
	int array[2000];
	int i = 0;
	fp = fopen("data.txt", "r");
	char line[10];
	while (fgets(line, sizeof(line), fp)) {
		//printf("%s", line);//��Ԫ���������Ļ��
		array[i++] = atoi(line);
	}
	fclose(fp);

	//���й鲢����
	FindPartition(array, 2000);

	//���ü�ʱ����
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;  // ͳ��ʱ��duration
	printf("\nThe CPU time is %2.6f seconds:\n", duration);

	//���������ļ�resultsMS.txt
	fp = fopen("resultsFP.txt", "w+");
	fprintf(fp, "Time = %f\n", duration);
	for (i = 0; i < 2000; i++) {
		fprintf(fp, "%d\n", array[i]);
	}
	return 0;
}