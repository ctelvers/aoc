#include <stdio.h>

#define SIZE 12

int main()
{
	int i = 0;
	char line[1024];
	int o[12] = {0};
	int z[12] = {0};
	int gamma = 0;
	int epsilon = 0;
	FILE* input = fopen("day3-2021-input.txt", "r");
	while (fgets(line, sizeof(line), input)) {
		i = 0;
		while (i < SIZE) {
			if(line[i] == '1') {
				printf("one\n");
				o[i]++;
			} else if (line[i] == '0') {
				printf("zero\n");
				z[i]++;
			}
			i++;
		}
	}
	for (i=0; i<SIZE; i++) {
		printf("%i,", o[i]);
	}
	printf("\n");
	for (i=0; i<SIZE; i++) {
		printf("%i,",z[i]);
	}
	printf("\n");

	for (i = 0; i<SIZE; i++) {
		if (o[i]>z[i]) {
			printf("1");
			gamma = gamma * 2 + 1;
			epsilon = epsilon * 2;
		} else {
			printf("0");
			gamma = gamma * 2 + 0;
			epsilon = epsilon * 2 + 1;
		}
	}

	printf("gamma = %i\n", gamma);
	printf("epsilon = %i\n", epsilon);
	printf("%i\n", epsilon * gamma);
	return 0;
}
