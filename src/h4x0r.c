#include "h4x0r.h"

#include <stdio.h>
#include <curses.h>

#define BUFFER_SIZE 256

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Ange lite filer yo.\n");
		return 0;
	}
	screen_setup();
	for (int i = 1; i < argc; i++)
		hackertype(argv[i]);
	endwin();

	return 0;
}

void hackertype(char *filename)
{
	int x, y;
	FILE *file = fopen(filename, "r");
	char buff[BUFFER_SIZE];
	char ch;
	while ((ch = getch()) != 'q') {
		type(buff, file);
		getyx(curscr, y, x);
		//if (y > 10)
		//	scroll(stdscr);
	}
	fclose(file);
}

void type(char *buff, FILE *file)
{
	fgets(buff, 10, file);
	printw("%s", buff);
}

void screen_setup()
{
	initscr();
	noecho();
	scrollok(stdscr, 1);
	refresh();
}

