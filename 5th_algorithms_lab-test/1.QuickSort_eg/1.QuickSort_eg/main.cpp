#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define cutoff 3
FILE* fp;

void Swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}
int Median3(int A[], int Left, int Right) {
	int Center = (Left + Right) / 2;
	//��������if����ʵ��С��������
	if (A[Left] > A[Center]) {
		Swap(A[Left], A[Center]);
	}
	if (A[Left] > A[Right]) {
		Swap(A[Left], A[Right]);
	}
	if (A[Right] < A[Center]) {
		Swap(A[Right], A[Center]);
	}

	//����ŦԪ�ŵ�Right-1��λ�á����ء�
	Swap(A[Center], A[Right - 1]);
	return A[Right - 1];
}

void Qsort(int A[], int Left, int Right) {

}

void QuickSort(int A[], int N) {
	Qsort(A, 0, N - 1);
}

// �������򣬴���N<20ʱ�ȿ�������죬����С��������
void InsertionSort(int A[], int N) {
	int i, j, tmp;
	for (i = 1; i < N; i++) {
		tmp = A[i];
		j = i ;
		while (tmp < A[j - 1]) {
			A[j] = A[j - 1];//vs��gcc�����ﴦ����Ʋ�ͬ������--��һЩ
			j--;
			if (j == 0) break;
		}
		Swap(A[j], tmp);

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
		printf("%s", line);//��Ԫ���������Ļ��
		array[i++] = atoi(line);
	}
	fclose(fp);

	//���п�������
	InsertionSort(array, 2000);
	//QuickSort(array, 2000);

	//���ü�ʱ����
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;  // ͳ��ʱ��duration
	printf("\nThe CPU time is %2.6f seconds:\n", duration);

	//���������ļ�resultsMS.txt
	fp = fopen("resultsMS.txt", "w+");
	fprintf(fp, "TimeMS = %f\n", duration);
	for (i = 0; i < 2000; i++) {
		fprintf(fp, "%d\n", array[i]);
		printf("%d\n", array[i]);
	}
	return 0;

}