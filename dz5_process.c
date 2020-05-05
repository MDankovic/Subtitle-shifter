#include <stdio.h>
#include <stdlib.h>
#include "dz5.h"

#ifndef FRAMES_23
	#define FPS 25
#else
	#define FPS 23.976
#endif

// Helper da prebacim vreme u FPS
FrameTime timeToFPS(Time time, double sinceBeginning, double fps)
{
	FrameTime fTime;
	fTime.startFrame = (int)(sinceBeginning * fps);
	fTime.endFrame = (int)((sinceBeginning + time.length) * fps);

	return fTime;
}

// Pomera titlove u vremenu
void shiftTitles(List titles, double fps, double shift)
{
	Node *curr = titles.first;
	shift /= 1000.0;
	if (curr->data->time.wait + shift >= 0) {
		while (curr) {
			curr->data->time.wait += shift;
			curr = curr->next;
		}
	}
	else
		printf("Neispravna velicina promene");
}