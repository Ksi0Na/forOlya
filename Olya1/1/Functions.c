#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stdio.h>
#include <stdlib.h>

enum humans {
	people_1 = 0b0101010101010101,
	people_2 = 0b1001001001001001,
	people_3 = 0b0011001100110011,
	people_4 = 0b1110001110001110,
	people_5 = 0b1111111111111111
};

void put_value(unsigned* var, unsigned value) {
	*((unsigned*)(var)) = value;
}

int request_input(int begin, int end) {
	int number;
	int real_read_count = scanf("%d", &number);
	while ((real_read_count == 0) || !((begin <= number) && (number <= end))) {
		char c;
		while ((c = getchar()) != '\n');
		printf("\nIncorrect input.");
		printf("\nPlease enter in range (%d - %d): ", begin, end);
		real_read_count = scanf("%d", &number);
	}
	return number;
}

int questions_(unsigned form, unsigned number) {

	printf("\nWhat do you want to do?\n");
	printf("[1] Leave information about yourself\n");
	printf("[2] View information about past users\n");
	printf("[3] Get away\n");

	unsigned action = request_input(1, 3);
	
	switch (action)
	{
	case 1:
		number++;
		leave_info_(form);
		questions_(form, number);
		break;
	case 2:
		view_info_(form, number);
		questions_(form, number);
		break;
	case 3:
		return 3;
		break;
	}
}

void view_info_(unsigned form, unsigned number) {
	
	unsigned info = 0;

	printf("Choose a person:\n");
	printf("[1] people 1\n");
	printf("[2] people 2\n");
	printf("[3] people 3\n");
	printf("[4] people 4\n");
	printf("[5] people 5\n");

	if (number) {
		printf("[6] I\n");
		info = request_input(1, 6);
	}
	else 
		info = request_input(1, 5);

	switch (info)
	{
	case 1:
		info = people_1;
		break;
	case 2:
		info = people_2;
		break;
	case 3:
		info = people_3;
		break;
	case 4:
		info = people_4;
		break;
	case 5:
		info = people_5;
		break;
	case 6:
		info = form;
		break;
	}
	decripter_(info);
}

void decripter_(unsigned info) {

	decript_gender_(info);
	decript_age_(info);
	decript_education_(info);
	decript_hair_color_(info);
	decript_color_eyes_(info);
	decript_state_of_family_(info);
	decript_state_of_life_(info);
}

void decript_gender_(unsigned info) {

	unsigned inf = (info >> 15) & ((1 << 1) - 1);

	switch (inf)
	{
	case 0:
		printf("Gender: Female\n");
		break;
	case 1:
		printf("Gender: Male\n");
		break;
	default:
		printf("Error\n");
		break;
	}
}

void decript_age_(unsigned info) {

	unsigned inf = (info << 1 >> 9) & ((1 << 7) - 1);

	if ((inf > 128) || (inf < 0)) printf("Error, inf: %u\n", inf);
	else printf("Age: %u\n", inf);
}

void decript_education_(unsigned info) {

	unsigned inf = (info << 8 >> 14) & ((1 << 2) - 1);

	switch (inf)
	{
	case 0:
		printf("Education: No\n");
		break;
	case 1:
		printf("Education: Incomplete secondary\n");
		break;
	case 2:
		printf("Education: Secondary\n");
		break;
	case 3:
		printf("Education: Higher\n");
		break;
	default:
		printf("Error, %u\n", inf);
		break;
	}
}

void decript_hair_color_(unsigned info) {

	unsigned inf = (info << 10 >> 14) & ((1 << 2) - 1);

	switch (inf)
	{
	case 0:
		printf("Hair: No\n");
		break;
	case 1:
		printf("Hair: Black\n");
		break;
	case 2:
		printf("Hair: Brown\n");
		break;
	case 3:
		printf("Hair: Blond\n");
		break;
	default:
		printf("Error, %u\n", inf);
		break;
	}
}

void decript_color_eyes_(unsigned info) {

	unsigned inf = (info << 13 >> 14) & ((1 << 2) - 1);

	switch (inf)
	{
	case 0:
		printf("Eyes: Blue\n");
		break;
	case 1:
		printf("Eyes: Green\n");
		break;
	case 2:
		printf("Eyes: Brown\n");
		break;
	case 3:
		printf("Eyes: Black\n");
		break;
	default:
		printf("Error, %u\n", inf);
		break;
	}
}

void decript_state_of_life_(unsigned info) {

	unsigned inf = (info << 15 >> 15) & ((1 << 1) - 1);

	switch (inf)
	{
	case 0:
		printf("State of life: Dead\n");
		break;
	case 1:
		printf("State of life: Alive\n");
		break;
	default:
		printf("Error, %u\n", inf);
		break;
	}
}

void decript_state_of_family_(unsigned info) {

	unsigned inf = (info << 12 >> 15) & ((1 << 1) - 1);

	switch (inf)
	{
	case 0:
		printf("State of family: Not married\n");
		break;
	case 1:
		printf("State of family: Married\n");
		break;
	default:
		printf("Error, %u\n", inf);
		break;
	}
}

void leave_info_(unsigned form) {

	printf("\nform = %u\n\n", form);
	
	gender_(form);
	age_(form);
	education_(form);
	hair_color_(form);
	color_eyes_(form);
	state_of_family_(form);
	state_of_life_(form);
}

void state_of_family_(unsigned form) {

	printf("What's your state of family?\n");
	printf("[0] Not married\n");
	printf("[1] Married\n");

	unsigned answer = request_input(0, 1);
	printf("\nform = %u\n\n", form);
	switch (answer)
	{
	case 0:
		(form) |= (1 << 1) - (1 << 3);
		break;
	case 1:
		//form = 1;
		(form) |= (1 << 2) - (1 << 3);
		break;
	}
	printf("\nform = %u\n\n", form);
}

void gender_(unsigned form) {

	printf("What's your gender?\n");
	printf("[0] Female\n");
	printf("[1] Male\n");
	
	unsigned answer = request_input(0, 1);
	printf("\nform = %u\n\n", form);
	switch (answer)
	{
	case 0:
		form |= (1 << 1) - (1 << 15);
		break;
	case 1:
		form |= (1 << 2) - (1 << 15);
		break;
	}
}

void age_(unsigned form) {
	
	printf("How old are you?\n");

	unsigned answer = request_input(0, 127);
	printf("\nform = %u\n\n", form);
	form |= (1 << 9) - (1 << 0);
	printf("\nform = %u\n\n", form);
}

void education_(unsigned form) {
	
	printf("What's your education?\n");
	printf("[0] No education\n");
	printf("[1] Incomplete secondary education\n");
	printf("[2] Secondary education\n");
	printf("[3] Higher education\n");

	unsigned answer = request_input(0, 3);
	printf("\nform = %u\n\n", form);
	switch (answer)
	{
	case 0:
		form |= (1 << 1) - (1 << 6);
		break;
	case 1:
		form |= (1 << 2) - (1 << 6);
		break;
	case 2:
		form |= (1 << 3) - (1 << 6);
		break;
	case 3:
		form |= (1 << 4) - (1 << 6);
		break;
	}
	printf("\nform = %u\n\n", form);
}

void hair_color_(unsigned form) {

	
	printf("What's your hair color?\n");
	printf("[0] No hair\n");
	printf("[1] Black\n");
	printf("[2] Brown\n");
	printf("[3] Blond\n");

	unsigned answer = request_input(0, 3);

	printf("\nform = %u\n\n", form);

	switch (answer)
	{
	case 0:
		form |= (1 << 1) - (1 << 4);
		break;
	case 1:
		form |= (1 << 2) - (1 << 4);
		break;
	case 2:
		form |= (1 << 3) - (1 << 4);
		break;
	case 3:
		form |= (1 << 4) - (1 << 4);
		break;
	}

	printf("\nform = %u\n\n", form);
}

void color_eyes_(unsigned form) {

	printf("What's your eyes color?\n");
	printf("[0] Blue\n");
	printf("[1] Green\n");
	printf("[2] Brown\n");
	printf("[3] Black\n");

	unsigned answer = request_input(0, 3);

	printf("\nform = %u\n\n", form);

	switch (answer)
	{
	case 0:
		form |= (1 << 1) - (1 << 1);
		break;
	case 1:
		form |= (1 << 2) - (1 << 1);
		break;
	case 2:
		form |= (1 << 3) - (1 << 1);
		break;
	case 3:
		form |= (1 << 4) - (1 << 1);
		break;
	}

	printf("\nform = %u\n\n", form);
}

void state_of_life_(unsigned form) {

	printf("What's your state?\n");
	printf("[0] Dead\n");
	printf("[1] Alive\n");

	unsigned answer = request_input(0, 1);

	printf("\nform = %u\n\n", form);

	switch (answer)
	{
	case 0:
		form |= (1 << 1) - (1 << 0);
		
		break;
	case 1:
		form |= (1 << 2) - (1 << 0);
		break;
	}
	printf("\nform = %u\n\n", form);
}