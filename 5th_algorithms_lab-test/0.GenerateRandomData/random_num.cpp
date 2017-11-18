#include <stdio.h>
#include <time.h>
#include <stdlib.h>
FILE* fp; 

void data_generate(int array[], int len){
	srand((unsigned)time(NULL));
	for(int i=0; i<len; i++){
		array[i] = (rand() % (10000 - 1 + 1)) + 1;
		printf("%d    %d\n", i, array[i]);
		fprintf(fp, "%d\n", array[i]);
	}
}

int main(){
	int array[2000] = {0};
	if((fp=fopen("data.txt","w+")) == NULL)
	{
		printf("The file can not be opened.\n");
	    exit(1);
	}
	data_generate(array, sizeof(array)/sizeof(int));
	return 0;
}
