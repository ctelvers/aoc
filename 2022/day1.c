#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	char line[1024];
	FILE* input;
	char number;
	int most_calories = 0;
	int second_most = 0;
	int third_most = 0;
	int total = 0;
	int mega_total = 0;

	input = fopen("day1-2022-input.txt", "r");
	while (fgets(line, sizeof(line), input)) {
		printf("%s", line);
		if (line[0]=='\n') {
			printf("this is a line break\n");
			if (total >= most_calories)
			{
				third_most = second_most;
				second_most = most_calories;
				most_calories = total;
			}
			else if (total >= second_most)
			{
				third_most = second_most;
				second_most = total;
			}
			else if (total >= third_most)
			{
				third_most = total;
			}
			printf("most cals %i,%i,%i\n", most_calories, second_most, third_most);
			total=0;
		} else {
			int num;
			sscanf(line, " %i ", &num);
			printf("this is a number: %i\n", num);
			total += num;
			printf("running total: %i\n", total);
		}
	}
	printf("most cals %i\n", most_calories);
	printf("2 cals %i\n", second_most);
	printf("3 cals %i\n", third_most);
	mega_total = most_calories + second_most + third_most;
	printf("mega total %i\n", mega_total);

}
