#include "aoc.h"

int
score_input(char* input)
{
  int left_start;
  int left_end;
  int right_start;
  int right_end;
  sscanf(
    input, "%d-%d,%d-%d", &left_start, &left_end, &right_start, &right_end);

  // Case 1: Left contains right
  if (left_start <= right_start && left_end >= right_end) {
    return 1;
  }

  // Case 2: Right contains left
  if (right_start <= left_start && right_end >= left_end) {
    return 1;
  }

  return 0;
}

int
main()
{
  char buf[256];
  int score = 0;
  while (fgets(buf, 256, stdin)) {
    score = score + score_input(buf);
  }

  printf("%d\n", score);
}