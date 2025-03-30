#include <stdio.h>

void TOH(int n, char source, char heper, char destination)
{
  if (n == 1)
  {
    printf("move disk 1 from %c to %c \n", source, destination);
    return;
  }
  TOH(n - 1, source, destination, heper);
  printf("move disk %d from %c to %c \n", n, source, destination);
  TOH(n - 1, heper, source, destination);
}

int main()
{
  int n = 3;
  TOH(n, 'A', 'B', 'C');
  return 0;
}