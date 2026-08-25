#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char line[1024];
	FILE* input;
	char first, last;
	int total = 0;

	input = fopen("day1-input.txt", "r");
	while (fgets(line, sizeof(line), input)) {
		printf("%s\n", line);
		int i = 0, combined;
		first = last = 0;
		while (line[i] != 0) {
			if ((line[i] >= '0') && (line[i] <= '9')) {
				printf("number %c\n", line[i]);
				if (first == 0) {
					first = line[i];
				}
				last = line[i];
			}
			i++;
		}
		printf("first %c, last %c\n", first, last);
		first -= '0';
		last -= '0';
		combined = (first * 10) + last;
		printf("total = %i\n", combined);
		total += combined;
	};
	printf("\n");
	printf("final total = %i\n", total);

	return 0;
}
