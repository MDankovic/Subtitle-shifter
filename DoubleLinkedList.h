#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dz5.h"

Node *getNode(Time time, char *text);

List createList();

void pushFront(List *plist, Time time, char *text);

void pushBack(List *plist, Time time, char *text);

void printList(List list);

void printListReversed(List list);

void deleteList(List list);