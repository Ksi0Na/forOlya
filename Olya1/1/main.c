#include "Functions.c"

int main()
{
	printf("\nWelcome!\n");

	unsigned* form = malloc(2);
	
	put_value(form, 0);

	unsigned number = 0;

	questions_(form, number);

	free(form);
	return 0;
}