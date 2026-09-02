#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

#define MAX 100000

int main()
{
	int size;
	int n = 0;
	int i = 0;
	bool found = false;
	int* numbers = malloc(2 * MAX * sizeof(int));
	char** puzzle = read_file("day1-2018-input.txt", &size);
	while (!found) {
		i = 0;
		while (!found && i < size) {
			//printf("n=%i, i=%i results in %i\n", n, atoi(puzzle[i]), n + atoi(puzzle[i]));
			n += atoi(puzzle[i]);
			if (n > MAX || n < -MAX) {
				printf("out of bounds %i\n", n);
				found = true;
			}
			if (numbers[n + MAX] == 0) {
				numbers[n + MAX]++;
			} else {
				printf("found %i\n", n);
				found = true;
			}
			i++;
		}
	}
	return 0;
}
