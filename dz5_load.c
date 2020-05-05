#include "dz5.h"
#include "DoubleLinkedList.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

List loadTitles(char oldFileName[MAX_LEN])
{
	enum states { timestamps, translation } state;

	FILE *oldFile;
	double fps = 23.976;//25; // Odaberi ovo za FPS nekako lepo
	int error;

	error = (oldFile = fopen(oldFileName, "r")) == NULL;
	if (error)
		exit(EXIT_FAILURE);

	Time time;
	List titles = createList();
	char sentenceRow[MAX_LEN];
	char text[MAX_LEN] = { '\0' };
	state = timestamps;
	error = 0;
	while (!error) {
		switch (state) {
		case timestamps: // Reading wait and length
			error = fscanf(oldFile, "%lf %lf\n", &time.wait, &time.length) == NULL;
			//printf("%.3f %.3f\n", time.wait, time.length);
			if (!error)
				state = translation;
			break;
		case translation: // Reading translation
			error = fgets(sentenceRow, MAX_LEN, oldFile) == NULL;
			while (!error && (int)strlen(sentenceRow) > 1) {
				sentenceRow[strlen(sentenceRow) - 1] = '\0';
				if (strlen(text) != 0)
					strcat(text, "|");
				//printf("%s\n", text);
				strcat(text, sentenceRow);
				error = fgets(sentenceRow, MAX_LEN, oldFile) == NULL;
			}
			pushBack(&titles, time, text);

			text[0] = '\0';
			state = timestamps;
			break;
		}
	}

	fclose(oldFile);
	return titles;
}