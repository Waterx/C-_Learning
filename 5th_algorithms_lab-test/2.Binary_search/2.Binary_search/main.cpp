#include<stdio.h>

//binary_search

int binary_search(int A[], int key, int imin, int imax) {
	while (imin <= imax)
	{
		int imid = imin + (imin + imax) / 2;
		if (A[imid] == key)
			return imid;
		else if (A[imid] < key)
			imin = imid + 1;
		else
			imax = imid - 1;
	}
	return -1;
}

//inter_search
int inter_search(int A[], int size, int key) {
	int low = 0;
	int high = size - 1;
	int mid;
	while (A[high] != A[low] && key >= A[low] && key <= A[high]) {
		mid = low + (high - low)*((key - A[low]) / (A[high] - A[low]));
		if (A[mid] < key)
			low = mid + 1;
		else if (key < A[mid])
			high = mid - 1;
		else
			return mid;
	}
	if (key == A[low])
		return low;
	else
		return -1;
}

int main() {
	int A[6] = { 1,4,10,16,24,28 };
	int result = -1;
	int result2 = -1;
	result = binary_search(A, 28, 1, 28);
	result2 = inter_search(A, 6, 16);
	return 0;
}