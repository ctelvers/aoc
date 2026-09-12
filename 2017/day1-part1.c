#include <stdio.h>

int main()
{
	char line[10240];
	FILE* input;
	int i, j;
	int total = 0;
	input = fopen("day1-2017-input.txt", "r");
	while (fgets(line, sizeof(line), input)) {
		i = 0;
		printf("%s", line);
		while(line[i] != 0) {
			if (line[i + 1] == 0) {
				j = 0;
			} else {
				j = i + 1;
			}
			if (line[i] == line[j] ) {
				total = total + line[i] - 48;
			}
			i++;
		}
		printf("i = %i ", i);
		printf("total = %i", total);
	}
	return 0;
}
