#include <stdio.h>

int main()
{
	int num;
	int h = 0;
	int d = 0;
	char der[1024];
	char line[1024];
	FILE* input = fopen("day2-2021-input.txt", "r");
	while (fgets(line, sizeof(line), input)) {
		sscanf(line, " %s %i ", &der, &num);
		if (der[0] == 'f') {
			printf("This goes forward %i\n", num);
			h += num;
		} else if(der[0] == 'u') {
			printf("This goes up %i\n", num);
			d-= num;
		} else if(der[0] == 'd') {
			printf("This goes down %i\n", num);
			d+= num;
		}
	}
	printf("The answer is %i", h*d);
	return 0;
}
