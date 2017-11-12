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
	//可以对比一下calloc与malloc的时间差异,结果是calloc更快一些
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

//lp为左半边开始，rp为右半边开始
void Merge(int A[], int tmp[], int lp, int rp, int right_end) {
	int left_end = rp - 1;
	int num_elements = right_end - lp + 1;
	int i = lp;

	//主循环
	while (lp <= left_end && rp <= right_end) {
		if (A[lp] <= A[rp]) {  
			tmp[i++] = A[lp++];
		}
		else if (A[lp] > A[rp]) {
			tmp[i++] = A[rp++];
		}
	}
	while (lp <= left_end) {//把左半剩下的拷贝
		tmp[i++] = A[lp++];
	}
	while (rp <= right_end) {//把右半剩下的拷贝
		tmp[i++] = A[rp++];
	}

	//把元素拷贝回去
	for (i = 0; i < num_elements; i++, right_end--) {
		A[right_end] = tmp[right_end];
	}
}


int main() {

	//设置计时开始
	double duration;
	clock_t  finish, start;
	start = clock();

	//------以下实现了一行行读取数据-------
	int array[2000];
	int i = 0;
	fp = fopen("data.txt", "r");
	char line[10];
	while (fgets(line, sizeof(line), fp)) {
		//printf("%s", line);//把元素输出到屏幕上
		array[i++] = atoi(line);
	}
	fclose(fp);

	//运行归并排序
	MergeSort(array, 2000);

	//设置计时结束
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;  // 统计时间duration
	printf("\nThe CPU time is %2.6f seconds:\n", duration);

	//输出结果到文件resultsMS.txt
	fp = fopen("resultsMS.txt", "w+");
	fprintf(fp, "TimeMS = %f\n", duration);
	for (i = 0; i < 2000; i++) {
		fprintf(fp, "%d\n", array[i]);
	}
	return 0;

}