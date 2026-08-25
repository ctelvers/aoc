#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	fclose(input);

    total = 0;
	char* numbers[] = { "zero", "one", "two", "three", "four",
	                    "five", "six", "seven", "eight", "nine"
	                  };
	int number_lengths[] = { 4, 3, 3, 5, 4, 4, 3, 5, 5, 4 };

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
			} else {
				for (int j = 0; j < 10; j++) {
					if (strncmp(line + i, numbers[j], number_lengths[j]) == 0) {
						printf("number match %s\n", numbers[j]);
						if (first == 0) {
							first = '0' + j;
						}
						last = '0' + j;
					}
				}
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
	fclose(input);

	return 0;
}
