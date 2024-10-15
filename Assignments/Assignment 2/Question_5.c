#include <stdio.h>

struct complex {
  int real;
  int image;
};

int main() {
  struct complex a, b, c;

  a.real = 3;
  a.image = 2;

  b.real = 4;
  b.image = 2;

  c.real = a.real + b.real;
  c.image = a.image + b.image;

  printf("%d + %d = %d\n", a.real, b.real, c.real);

  printf("%d - %d = %d ", a.image, b.image, c.image);

  return 0;
}

/*
output->

3 + 4 = 7
2 - 2 = 4

*/