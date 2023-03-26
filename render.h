struct color {
  unsigned char red, green, blue;
};

struct cube {
  unsigned int width, height, depth;
  unsigned int x, y, z;
};

int render2d(struct color ***world, unsigned int mapHeight,
             unsigned int mapWidth);
