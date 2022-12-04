#include "aoc.h"

int
main()
{
  char buffer[10];
  int elves[400];
  int count = 0;
  elves[0] = 0;
  while (gets(buffer) != 0) {
    if (strlen(buffer) == 0) {
      count++;
      elves[count] = 0;
    } else {
      elves[count] = elves[count] + atoi(buffer);
    }
  }

  for (int i = 1; i < count; i++) {
    for (int j = i; 0 <= j && elves[j] < elves[j - 1]; j--) {
      int tmp = elves[j - 1];
      elves[j - 1] = elves[j];
      elves[j] = tmp;
    }
  }

  printf("%d\n", elves[count - 1] + elves[count - 2] + elves[count - 3]);
}
