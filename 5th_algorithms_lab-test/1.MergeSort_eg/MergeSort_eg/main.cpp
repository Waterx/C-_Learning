#include<stdio.h>
#include<stdlib.h>
#include<time.h>
FILE* fp;
void MSort(int A[], int tmp[], int left, int right);
void Merge(int A[], int tmp[], int lp, int rp, int right_end);
void MergeSort(int A[], int N);

void MSort(int A[], int tmp[], int left, int right) {
	int center = (left + right) / 2;
	if (left < right) {
		MSort(A, tmp, left, center);
		MSort(A, tmp, center + 1, right);
		Merge(A, tmp, left, center + 1, right);
	}
}

void MergeSort(int A[], int N) {
	int* tmp;
	//���ԶԱ�һ��calloc��malloc��ʱ�����,�����calloc����һЩ
	//tmp = (int*)malloc(N * sizeof(int));
	tmp = (int *)calloc(N, sizeof(int));
	if (tmp != NULL) {
		MSort(A, tmp, 0, N - 1);
		free(tmp);
	}
	else {
		exit(0);
	}
}

//lpΪ���߿�ʼ��rpΪ�Ұ�߿�ʼ
void Merge(int A[], int tmp[], int lp, int rp, int right_end) {
	int left_end = rp - 1;
	int num_elements = right_end - lp + 1;
	int i = lp;

	//��ѭ��
	while (lp <= left_end && rp <= right_end) {
		if (A[lp] <= A[rp]) {  
			tmp[i++] = A[lp++];
		}
		else if (A[lp] > A[rp]) {
			tmp[i++] = A[rp++];
		}
	}
	while (lp <= left_end) {//�����ʣ�µĿ���
		tmp[i++] = A[lp++];
	}
	while (rp <= right_end) {//���Ұ�ʣ�µĿ���
		tmp[i++] = A[rp++];
	}

	//��Ԫ�ؿ�����ȥ
	for (i = 0; i < num_elements; i++, right_end--) {
		A[right_end] = tmp[right_end];
	}
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
	MergeSort(array, 2000);

	//���ü�ʱ����
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;  // ͳ��ʱ��duration
	printf("\nThe CPU time is %2.6f seconds:\n", duration);

	//���������ļ�resultsMS.txt
	fp = fopen("resultsMS.txt", "w+");
	fprintf(fp, "TimeMS = %f\n", duration);
	for (i = 0; i < 2000; i++) {
		fprintf(fp, "%d\n", array[i]);
	}
	return 0;

}