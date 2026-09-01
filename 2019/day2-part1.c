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
		if (buffer[i]== ',') {
			line_count++;
		}
	}
	*lc = line_count;
	char** lines = malloc(line_count * sizeof (*lines));
	int j = 0;
	lines[j] = buffer;
	j++;
	for (int i = 0; i<n; i++) {
		if (buffer[i] == ',') {
			buffer[i] = 0;
			if (i+ 1 < n) lines [j++] = & buffer[i + 1];
		}
	}
	return lines;
}

int main()
{
	int size = 12;
	char** line = read_file("day2-2019-input.txt", &size);
	int i;
	int* memory = malloc(size * sizeof(int));
	for (i = 0; i < size; i++) {
		memory[i] = atoi(line[i]);
	}
	memory[1] = 12;
	memory[2] = 2;
	int pc = 0;
	while (memory[pc] != 99) {
		for (i = 0; i < size; i++) {
			printf("%i,", memory[i]);
		}
		printf("\n");
		if (memory[pc] == 1) {
			int num1 = memory[memory[pc + 1]];
			int num2 = memory[memory[pc + 2]];
			int res = num1 + num2;
			memory[memory[pc + 3]] = res;
			pc += 4;
			printf("Result = %i\n", res);
		}
		if (memory[pc] == 2) {
			int num1 = memory[memory[pc + 1]];
			int num2 = memory[memory[pc + 2]];
			int res = num1 * num2;
			memory[memory[pc + 3]] = res;
			pc += 4;
			printf("Result = %i\n", res);
		}
	}
	printf("%i\n", memory[0]);
	return 0;
}
