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

  if (left_start > right_end) {
    return 0;
  }

  if (right_start > left_end) {
    return 0;
  }

  return 1;
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