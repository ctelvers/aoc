#include <stdio.h>

int main()
{
	char line[10240];
	FILE* input;
	int i, j, h, l;
	int total = 0;
	input = fopen("day1-2017-input.txt", "r");
	while (fgets(line, sizeof(line), input)) {

		l = 0;
		printf("%s", line);
		while(line[l] != 0) {
			l++;
		}
		printf(" length (l) = %i\n", l);
		h = l / 2;
		printf(" half (h) = %i\n", h);

		i = 0;
//		printf("%s", line);
		while(line[i] != 0) {
			j = i + h;
			if (j >= l) {
			j = j - l;
			}
			if (line[i] == line[j] ) {
				total = total + line[i] - 48;
			}
			i++;
		}
		printf(" i = %i ", i);
		printf("total = %i", total);
	}
	return 0;
}
