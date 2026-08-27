#include <stdio.h>

int main()
{
	char line[1024];
	int i = 0;
	int prev = 0;
	int num;
	FILE* input = fopen("day1-2021-input.txt", "r");
	while (fgets(line, sizeof(line), input)) {
		sscanf(line, " %i ", &num);
		printf(" this is a number: %i ", num);
		if (num > prev) {
			printf("increased\n");
			i++;
		} else if(num < prev) {
			printf("decreased\n");
		} else {
			printf("same\n");
		}
        prev = num;
	}
    printf("number of increased = %i", i-1);
	return 0;
}
