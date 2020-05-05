#pragma once

#define MAX_LEN 256

typedef struct
{
	int startFrame;
	int endFrame;
} FrameTime;

typedef struct
{
	double wait;
	double length;
} Time;

typedef struct
{
	Time time;
	char text[MAX_LEN];
} Data;

typedef struct
{
	Data *data;
	struct node *prev;
	struct node *next;
} Node;

typedef struct
{
	Node *first;
	Node *last;
} List;


List loadTitles(char oldFileName[MAX_LEN]);

FrameTime timeToFPS(Time time, double sinceBeginning, double fps);

void convertTitles(List titles, char newFileName[MAX_LEN], double fps);

void shiftTitles(List titles, double fps, double shift);