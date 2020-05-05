#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoubleLinkedList.h"

Node *getNode(Time time, char *text)
{
	Node *newNode = malloc(sizeof(Node));
	newNode->data = malloc(sizeof(Data));
	newNode->data->time.wait = time.wait;
	newNode->data->time.length = time.length;
	
	int i;
	for (i = 0; i < strlen(text); i++)
		newNode->data->text[i] = text[i];
	newNode->data->text[i] = '\0';
	
	//strcpy(newNode->data->text, text);
	newNode->prev = NULL;
	newNode->next = NULL;

	return newNode;
}

List createList()
{
	List list = { NULL, NULL };

	return list;
}

void pushFront(List *plist, Time time, char *text)
{
	Node *newNode = getNode(time, text);
	newNode->next = plist->first;

	if (!plist->last)
		plist->last = newNode;
	else
		plist->first->prev = newNode;
	plist->first = newNode;
}

void pushBack(List *plist, Time time, char *text)
{
	Node *newNode = getNode(time, text);
	newNode->prev = plist->last;

	if (!plist->first)
		plist->first = newNode;
	else
		plist->last->next = newNode;
	plist->last = newNode;
}

void printList(List list)
{
	Node *temp = list.first;
	/*
	while (temp) {
		printf("%d ", temp->info);
		temp = temp->next;
	}
	*/
}

void printListReversed(List list)
{
	Node *temp = list.last;
	/*
	while (temp) {
		printf("%d ", temp->info);
		temp = temp->prev;
	}
	*/
}

void deleteList(List list)
{
	Node *temp = list.last, *old;

	while (temp) {
		old = temp;
		temp = temp->next;
		free(old);
	}
}