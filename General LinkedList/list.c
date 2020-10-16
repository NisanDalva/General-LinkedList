#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*
create new list
Input:	pointer to the list structure
Output:	TRUE if succeeded
*/
BOOL L_init(LIST* pList)
{
	if (pList == NULL) return False;	// no list to initialize

	pList->head.next = NULL;
	return True;
}

/*
add new node
Input:	pointer to the node BEFORE the place for the new one
			a value to be stored in the new node
Output:	pointer to the new node
*/
NODE* L_insert(NODE* pNode, DATA Value)
{
	NODE* tmp;

	if (!pNode) return NULL;

	tmp = (NODE*)malloc(sizeof(NODE));	// new node

	if (tmp != NULL) {
		tmp->key = Value;
		tmp->next = pNode->next;
		pNode->next = tmp;
	}
	return tmp;
}

/*
erase node
Input:	pointer to the node BEFORE the node to be deleted
Output:	TRUE if succeeded
*/
BOOL L_delete(NODE* pNode)
{
	NODE* tmp;

	if (!pNode || !(tmp = pNode->next)) return False;

	pNode->next = tmp->next;
	free(tmp);
	return True;
}

/*
search for a value
Input:	pointer to the node to start with
			a value to be found, the DATA value,
			pointer to function that know to campare between two elements
			with type of DATA and determine if it's match
Output:	pointer to the node containing the Value
*/
NODE* L_find(NODE* pNode, DATA value, int(*compare)(const void*, const void*))
{
	NODE* temp = NULL;
	if (!pNode) return NULL;
	while (pNode != NULL)
	{
		if (compare(pNode->key, value) == 0)
		{
			temp = pNode;
			break;
		}
		pNode = pNode->next;
	}

	return temp;


}

/*
free the list memory
Input:	pointer to the list structure
Output:	TRUE if succeeded
*/
BOOL L_free(LIST* pList)
{
	NODE* tmp;

	if (!pList) return False;

	for (tmp = &(pList->head); L_delete(tmp); );
	return True;
}

/*
Input:	pointer to the list structure, pointer to a function that know to print DATA type
Output:	a number of the printed elements
*/
int L_print(LIST* pList, void(*print)(const void*))
{
	NODE* tmp;
	int	c = 0;

	if (!pList) return 0;

	for (tmp = pList->head.next; tmp; tmp = tmp->next, c++)
		print(tmp->key);
	printf("\n");
	return c;
}