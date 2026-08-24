#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a, const void *b)
{
	int ia = *(const int *)a;
	int ib = *(const int *)b;
	return (ia > ib) - (ia < ib);
}

int main(void)
{
	int count;
	int dif = 0;
	char line[1024];
	FILE* input;
	int* left = malloc(1000 * sizeof(int));
	int* right = malloc(1000 * sizeof(int));

	count = 0;
	input = fopen("day1-input.txt", "r");
	while (fgets(line, sizeof(line), input)) {
		sscanf(line, " %i %i ", &left[count], &right[count]);
		count++;
	};

	for (int i = 0; i < 10; i++) {
		printf("%i %i\n", left[i], right[i]);
	}
	printf("\n");

	qsort(left, count, sizeof(int), compare_int);
	qsort(right, count, sizeof(int), compare_int);

	for (int i = 0; i < 10; i++) {
		printf("%i %i\n", left[i], right[i]);
	}
	printf("\n");

	for (int i = 0; i < count; i++) {
		if (left[i] < right[i]) {
			int n = right[i] - left[i];
			dif = dif + n;
		}
		else {
			int n = left[i] - right[i];
			dif = dif + n;
		}

	}
	
	printf("%i\n", dif);
	return 0;
}
