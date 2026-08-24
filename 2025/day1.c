#include <stdio.h>

int main() {
	int zero = 0;
	int dial = 50;
	int n;
	char ch;

	char bar[1024];
	FILE* input;
	input = fopen("input.txt", "r");

	printf ("The dial starts by pointing at %i\n", dial);
	while (fgets(bar, sizeof(bar), input)) {
		printf("%s\n", bar);

		sscanf(bar, " %c %i ", &ch, &n);
		printf ("%c %i\n", ch, n);
		if (ch == 'L' ) {
			dial = dial - n;
		}
		else if (ch == 'R' ) {
			dial = dial + n;
		}
		else {
			printf("nope >%x<\n", ch);
		}
		// dial is at 10, input is L677.
		// dial -667
		// -567, -467, -367, -267, -167, -67, 67
		// if dial < 0 then dial += 100;
		while (dial < 0) {
			dial += 100;
		};
		while (dial > 99) {
			dial -= 100;
		};
		printf ("The dial is rotated %s to point at %i\n", bar, dial);
		if (dial == 0) {
			zero++;
			printf ("The dial landed on 0  %i\n", zero);
		}
	}
	printf("the dial will count how mant times it lands on 0, the curent number is %i\n", zero);

	return 0;
}
