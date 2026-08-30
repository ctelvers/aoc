#include <stdio.h>
#include <stdlib.h>

char** read_file(char* name, int* lc) {
	FILE* input = fopen(name,"r");
	fseek(input, 0L, SEEK_END);
	long length = ftell(input) + 1;
	fseek(input, 0L, SEEK_SET);
	char* buffer  = malloc(length);
	int n = fread(buffer, sizeof(char), length, input);
	fclose(input);
	buffer[n] = '\0';
	int line_count = 1;
	for (long i = 0; i < n; i++) {
		if (buffer[i]== '\n') {
			line_count++;
		}
	}
	*lc = line_count;
	char** lines = malloc(line_count * sizeof (*lines));
	int j = 0;
	lines[j] = buffer;
	j++;
	for (int i = 0; i<n; i++) {
		if (buffer[i] == '\n') {
			buffer[i] = 0;
			if (i+ 1 < n) lines [j++] = & buffer[i + 1];
		}
	}
	return lines;
}
int main()
{
	int total = 2020;
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int size = 6;
	//	int puzzle[6] = {1721,979,366,299,675,1456};
	char** puzzle = read_file("day1-2020-input.txt", &size);
	int i,j,k;
	for (i = 0; i < size; i++) {
		for (j = i + 1; j < size; j++) {
			for (k = j + 1; k < size; k++) {
				//			printf("%i\n", puzzle[i] + puzzle[j]);
				if (atoi(puzzle[i]) + atoi(puzzle[j]) + atoi(puzzle[k]) == total) {
					//				printf("%i %i\n", puzzle[i], puzzle[j]);
					num1 =	atoi(puzzle[i]);
					num2 = 	atoi(puzzle[j]);
					num3 = 	atoi(puzzle[k]);
				}
			}
		}
	}
	printf("the answer is %i\n", num1 * num2 * num3);
	return 0;
}
