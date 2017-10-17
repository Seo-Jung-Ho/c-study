#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
	int age;
	char name[100];
} Person;

void main() {
	/*
	Person p;
	p.age = 10;
	strcpy(p.name ,"¼­Á¤È£");
	printf("%s", p.name);*/

	//Person *p1 = (Person*)malloc(sizeof(Person));
	Person p;
	Person *ptr;

	ptr = &p;
	
	strcpy(p.name, "¤¾¤±¤¤");
	p.age = 100;

	printf("%s\n", p.name);
	printf("%s\n", ptr -> name);


}