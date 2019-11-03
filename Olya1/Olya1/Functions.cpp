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
int devnull;
void questions_(void* form) {

	unsigned action = 0;

	printf("What do you want to do?\n");
	printf("[1] Leave information about yourself\n");
	printf("[2] View information about past users\n");
	printf("[3] Get away\n");


	devnull = scanf("%u", &action);

	switch (action)
	{
	case 1:
		leave_info_((unsigned)form);
		questions_(form);
		break;
	case 2:
		view_info_((unsigned)form);
		questions_(form);
		break;
	case 3:
		free(&form);
		exit(0);
	default:
		printf("Incorrect input.\n");
		questions_(form);
	}
}

void view_info_(unsigned form) {

	unsigned info = 0;
	printf("Choose a person:\n");
	printf("[1] people 1\n");
	printf("[2] people 2\n");
	printf("[3] people 3\n");
	printf("[4] people 4\n");
	printf("[5] people 5\n");
	if (!form) printf("[6] I\n");

	devnull = scanf("%u", &info);
	switch (info)
	{
	case 1:
		info = people_1;
		decripter_(info);
		break;
	case 2:
		info = people_2;
		decripter_(info);
		break;
	case 3:
		info = people_3;
		decripter_(info);
		break;
	case 4:
		info = people_4;
		decripter_(info);
		break;
	case 5:
		info = people_5;
		decripter_(info);
		break;
	case 6:
		info = form;
		decripter_(info);
		break;
	default:
		printf("Incorrect input.\n");
		view_info_(form);
		break;
	}
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

	unsigned inf = info >> 15;

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

	unsigned inf = (info << 1) >> 9;

	if ((inf > 127) || (inf < 0)) printf("Error\n");
	else printf("Age: %u\n", inf);
}

void decript_education_(unsigned info) {

	unsigned inf = (info << 8) >> 14;

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
		printf("Error\n");
		break;
	}
}

void decript_hair_color_(unsigned info) {

	unsigned inf = (info << 10) >> 14;

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
		printf("Error\n");
		break;
	}
}

void decript_color_eyes_(unsigned info) {

	unsigned inf = (info << 13) >> 14;

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
		printf("Error\n");
		break;
	}
}

void decript_state_of_life_(unsigned info) {

	unsigned inf = (info << 15) >> 15;

	switch (inf)
	{
	case 0:
		printf("State of life: Dead\n");
		break;
	case 1:
		printf("State of life: Alive\n");
		break;
	default:
		printf("Error\n");
		break;
	}
}

void decript_state_of_family_(unsigned info) {

	unsigned inf = (info << 12) >> 15;

	switch (inf)
	{
	case 0:
		printf("State of family: Not married\n");
		break;
	case 1:
		printf("State of family: Married\n");
		break;
	default:
		printf("Error\n");
		break;
	}
}

void leave_info_(unsigned form) {

	gender_(form);
	age_(form);
	education_(form);
	hair_color_(form);
	color_eyes_(form);
	state_of_family_(form);
	state_of_life_(form);
}

void state_of_family_(unsigned form) {

	unsigned answer = 0;

	printf("What's your state of family?\n");
	printf("[0] Not married\n");
	printf("[1] Married\n");

	devnull = scanf("%u", &answer);
	switch (answer)
	{
	case 0:
		form = form | (0 << 3);
		break;
	case 1:
		form = form | (1 << 3);
		break;
	default:
		printf("Incorrect input.\n");
		state_of_family_(form);
	}
}

void gender_(unsigned form) {

	unsigned answer = 0;

	printf("What's your gender?\n");
	printf("[0] Female\n");
	printf("[1] Male\n");

	devnull = scanf("%u", &answer);
	switch (answer)
	{
	case 0:
		form = form | (0 << 15);
		break;
	case 1:
		form = form | (1 << 15);
		break;
	default:
		printf("Incorrect input.\n");
		gender_(form);
	}
}

void age_(unsigned form) {

	unsigned answer = 0;

	printf("How old are you?\n");
	devnull = scanf("%u", &answer);

	if ((answer > 127) || (answer < 0)) {
		printf("Incorrect input.\n");
		age_(form);
	}
	else {
		form = form | (answer << 8);
	}
}

void education_(unsigned form) {

	unsigned answer = 0;

	printf("What's your education?\n");
	printf("[0] No education\n");
	printf("[1] Incomplete secondary education\n");
	printf("[2] Secondary education\n");
	printf("[3] Higher education\n");

	devnull = scanf("%u", &answer);
	switch (answer)
	{
	case 0:
		form = form | (0 << 6);
		break;
	case 1:
		form = form | (1 << 6);
		break;
	case 2:
		form = form | (2 << 6);
		break;
	case 3:
		form = form | (3 << 6);
	default:
		printf("Incorrect input.\n");
		education_(form);
	}
}

void hair_color_(unsigned form) {

	unsigned answer = 0;

	printf("What's your hair color?\n");
	printf("[0] No hair\n");
	printf("[1] Black\n");
	printf("[2] Brown\n");
	printf("[3] Blond\n");

	devnull = scanf("%u", &answer);

	switch (answer)
	{
	case 0:
		form = form | (0 << 4);
		break;
	case 1:
		form = form | (1 << 4);
		break;
	case 2:
		form = form | (2 << 4);
		break;
	case 3:
		form = form | (3 << 4);
		break;
	default:
		printf("Incorrect input.\n");
		hair_color_(form);
	}
}

void color_eyes_(unsigned form) {

	unsigned answer = 0;

	printf("What's your eyes color?\n");
	printf("[0] Blue\n");
	printf("[1] Green\n");
	printf("[2] Brown\n");
	printf("[3] Black\n");

	devnull = scanf("%u", &answer);

	switch (answer)
	{
	case 0:
		form = form | (0 << 1);
		break;
	case 1:
		form = form | (1 << 1);
		break;
	case 2:
		form = form | (2 << 1);
		break;
	case 3:
		form = form | (3 << 1);
		break;
	default:
		printf("Incorrect input.\n");
		color_eyes_(form);
	}
}

void state_of_life_(unsigned form) {

	unsigned answer = 0;

	printf("What's your state?\n");
	printf("[0] Dead\n");
	printf("[1] Alive\n");

	devnull = scanf("%u", &answer);

	switch (answer)
	{
	case 0:
		form = form | 0;
		break;
	case 1:
		form = form | 1;
		break;
	default:
		printf("Incorrect input.\n");
		state_of_life_(form);
	}
}