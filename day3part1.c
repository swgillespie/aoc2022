#include "aoc.h"

int
score_char(char value)
{
  if (value >= 'A' && value <= 'Z') {
    return value - 'A' + 26;
  } else {
    return value - 'a';
  }
}

int
score_input(char* line)
{
  int len = strlen(line);
  int first_item_set[52];
  int second_item_set[52];
  memset(first_item_set, 0, 52 * sizeof(len));
  memset(second_item_set, 0, 52 * sizeof(len));

  char* second_half = line + len / 2;
  for (int i = 0; i < len / 2; i++) {
    first_item_set[score_char(line[i])]++;
    second_item_set[score_char(second_half[i])]++;
  }

  for (int i = 0; i < 52; i++) {
    if (first_item_set[i] > 0 && second_item_set[i] > 0) {
      return i + 1;
    }
  }
}

int
main()
{
  char buffer[256];
  int score = 0;
  while (gets(buffer) != 0) {
    score = score + score_input(buffer);
  }

  printf("%d\n", score);
}