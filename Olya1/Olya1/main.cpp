#include "Functions.cpp"

int main()
{
	printf("\nWelcome!\n");

	void* form = malloc(2);
	form = 0;

	questions_(form);

	free(form);
	return 0;
}