#include "Functions.c"

int main()
{
	printf("\nWelcome!\n");

	unsigned* form = malloc(2);
	unsigned* f = &form;
	form = 0;
	unsigned number = 0;

	questions_(f, number);

	free(form);
	return 0;
}