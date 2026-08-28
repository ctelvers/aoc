#include <stdio.h>

int main()
{
	int num;
	int h = 0;
	int d = 0;
	int a = 0;
	char der[1024];
	char line[1024];
	FILE* input = fopen("day2-2021-input.txt", "r");
	while (fgets(line, sizeof(line), input)) {
		sscanf(line, " %s %i ", &der, &num);
		if (der[0] == 'f') {
			printf("This goes forward %i\n", num);
			h += num;
			d += num*a;
		} else if(der[0] == 'u') {
			printf("This goes up %i\n", num);
			a -= num;
		} else if(der[0] == 'd') {
			printf("This goes down %i\n", num);
			a += num;
		}
	}
	printf("%i\n", h);
	printf("%i\n", d);
	printf("The answer is %i", h*d);
	return 0;
}
