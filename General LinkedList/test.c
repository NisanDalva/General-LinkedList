#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "Person.h"


int main()
{
	LIST	lst;
	int i;
	NODE* ptr1;

	Person arr[5];
	for (i = 0; i < NUM_PERSONS; i++)
	{
		initPerson(&arr[i]);
	}

	printf("The persons in array:\n");
	for (int i = 0; i < NUM_PERSONS; i++)
	{
		showPerson(&arr[i]);
	}

	// Initialization
	L_init(&lst);

	//Add to list one after the other
	ptr1 = &lst.head;
	for (i = 0; i < NUM_PERSONS; i++)
		ptr1 = L_insert(ptr1, &arr[i]);

	printf("\nThe persons in list:\n");
	L_print(&lst, showPerson);

	L_delete(&lst.head);
	printf("The persons in list after delete the first one:\n");
	L_print(&lst, showPerson);

	printf("Enter id to find:\n");
	int id;
	scanf("%d", &id);
	Person temp;
	temp.id = id;
	ptr1 = L_find(lst.head.next, &temp, comparePersonById);
	if (ptr1)
	{
		printf("Person found:\n");
		showPerson(ptr1->key);
	}
	else
		printf("Person not found.\n");

	// Finish work
	L_free(&lst);
	system("pause");
}