#include <stdio.h>
#include <stdlib.h>

#include "render.h"

int main(int argc, char** argv) {
  struct color*** a;
  int height = 10;
  int width = 10;
  a = (struct color***)malloc(sizeof(struct color**) * height);
  for (int ii = 0; ii < height; ii++) {
    a[ii] = (struct color**)malloc(sizeof(struct color*) * width);
    for (int jj = 0; jj < width; jj++) {
      a[ii][jj] = (struct color*)malloc(sizeof(struct color));
      if ((ii) % 2 == 0) {
        a[ii][jj]->red = 0;
        a[ii][jj]->green = 255;
        a[ii][jj]->blue = 255;
      } else {
        a[ii][jj]->red = 255;
        a[ii][jj]->green = 0;
        a[ii][jj]->blue = 255;
      }
    }
  }

  render2d(a, height, width);

  for (int ii = 0; ii < height; ii++) {
    for (int jj = 0; jj < width; jj++) {
      free(a[ii][jj]);
    }
    free(a[ii]);
  }
  free(a);
  return 0;
}