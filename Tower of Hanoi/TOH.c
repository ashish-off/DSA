#include <stdio.h>

void TOH(int n, char source, char heper, char destination)
{
  // Base case: If only 1 disk, move it directly from source to destination
  if (n == 1)
  {
    printf("move disk 1 from %c to %c \n", source, destination);
    return;
  }
  // Step 1: Move (n-1) disks from source to helper (using destination as temporary)
  TOH(n - 1, source, destination, heper);

  // Step 2: Move the nth (largest) disk from source to destination
  printf("move disk %d from %c to %c \n", n, source, destination);

  // Step 3: Move (n-1) disks from helper to destination (using source as temporary)
  TOH(n - 1, heper, source, destination);
}

int main()
{
  int n = 3;             // Number of disks
  TOH(n, 'A', 'B', 'C'); // A=Source, B=Helper, C=Destination
  return 0;
}