#include<stdio.h>
#include<stdlib.h>
#include<time.h>
FILE* fp;

int main() {

	//读取数据
	int array[2000];
	int i = 0;
	fp = fopen("data.txt", "r");
	char line[10];
	while (fgets(line, sizeof(line), fp)) {
		//printf("%s", line);//把元素输出到屏幕上
		array[i++] = atoi(line);
	}
	fclose(fp);
	
	//设置计时开始
	double duration;
	clock_t  finish, start;
	start = clock();

	//运行XXXXXXX
	

	//设置计时结束
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;  // 统计时间duration
	printf("\nThe CPU time is %2.6f seconds:\n", duration);

	//输出结果到文件resultsXX.txt
	fp = fopen("results.txt", "w+");
	fprintf(fp, "Time = %f\n", duration);
	for (i = 0; i < 2000; i++) {
		fprintf(fp, "%d\n", array[i]);
	}
	return 0;
}
