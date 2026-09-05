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
	int size;
	char** line = read_file("day1-2015-input.txt", &size);
	printf("%i\n", size);
	int j = 0;
	int i = 0;
	int f = 0;
	while(line[i][j]!=0) {
			if (line[i][j] =='(') {
				f ++;
				j++;
			} else if (line[i][j] == ')' ) {
				f --;
				j++;
			}
			if (f < 0){
			   break;
			}
		}
	printf("the floor santa finishes on is %i\n", f);
	printf("he enters the basement at position %i\n", j);
	return 0;
}
