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
		if (buffer[i] == '\r') {
			buffer[i] = 0;
		}
		if (buffer[i] == '\n') {
			buffer[i] = 0;
			if (i+ 1 < n) lines [j++] = & buffer[i + 1];
		}
	}
	return lines;
}

int main()
{
	int i = 0;
	int j = 0;
	int num = 0;
	int size;
	int largest = 0;
	int smallest = 0;
	int total = 0;
	char** puzzle = read_file("day2-2017-input.txt", &size);
	while(j< size) {
		i = 0;
		num = 0;
		smallest = 0;
		largest = 0;
		do {
			if (puzzle[j][i] >= '0' && puzzle[j][i] <= '9') {
				//	            printf("%c", puzzle[j][i]);
				num = num * 10 + puzzle[j][i] - '0';
			}
			if (puzzle[j][i] == ' ' || puzzle[j][i] == 0 || puzzle[j][i] == '\t') {
				printf("num = %i\n", num);
				if (largest == 0) {
					smallest = num;
				}
				if (num > largest) {
					largest = num;
				}
				if (num < smallest) {
					smallest = num;
				}
				num = 0;
			}
			//i++;
		} while (puzzle[j][i++] != 0);
		printf("\n");
		printf("largest = %i\nsmallest = %i\n", largest, smallest);
		total += largest - smallest;
		j++;
	}
	printf("the total is %i", total);

	return 0;
}
