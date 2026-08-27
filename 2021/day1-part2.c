#include <stdio.h>

int main()
{
	char line[1024];
	int i = 0;
	int sprev = 0;
	int total = 0;
	int ptotal = 0;
	int prev = 0;
	int num;
	FILE* input = fopen("day1-2021-input.txt", "r");
	while (fgets(line, sizeof(line), input)) {
		sscanf(line, " %i ", &num);
		printf(" this is a number: %i ", num);
		total = num + prev + sprev;
		printf("%i %i \n ", total, ptotal);
		if (total > ptotal) {
			printf("increased\n");
			i++;
		} else if(total < ptotal) {
			printf("decreased\n");
		} else {
			printf("same\n");
		}
		ptotal = total;
		sprev = prev;
		prev = num;
	}
	printf("number of increased = %i", i-3);
	return 0;
}
