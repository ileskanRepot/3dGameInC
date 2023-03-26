#include "render.h"

#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

int render2d(struct color ***world, unsigned int mapHeight,
             unsigned int mapWidth) {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  unsigned int termHeight = w.ws_row;
  unsigned int termWidth = w.ws_col;

  for (int ii = 0; ii < mapHeight; ii++) {
    for (int jj = 0; jj < mapHeight; jj++) {
      printf("\033[48;2;%d;%d;%dm  \033[0m", world[ii][jj]->red,
             world[ii][jj]->green, world[ii][jj]->blue);
    }
    printf("\n");
  }
  if (termHeight > mapHeight && termWidth > mapWidth) {
    printf("Wee\n");
  }
  printf("Term Height %d\n", termHeight);
  printf("Term  Width %d\n", termWidth);

  return 0;
}