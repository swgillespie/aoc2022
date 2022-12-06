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
score_input(char* one, char* two, char* three)
{
  int first_item_set[52];
  int second_item_set[52];
  int third_item_set[52];
  int one_len = strlen(one);
  int two_len = strlen(two);
  int three_len = strlen(three);

  memset(first_item_set, 0, 52 * sizeof(one_len));
  memset(second_item_set, 0, 52 * sizeof(two_len));
  memset(third_item_set, 0, 52 * sizeof(three_len));

  int i = 0;
  while (1) {
    if (i >= one_len && i >= two_len && i >= three_len) {
      break;
    }

    if (i < one_len) {
      first_item_set[score_char(one[i])]++;
    }

    if (i < two_len) {
      second_item_set[score_char(two[i])]++;
    }

    if (i < three_len) {
      third_item_set[score_char(three[i])]++;
    }

    i++;
  }

  for (int i = 0; i < 52; i++) {
    if (first_item_set[i] > 0 && second_item_set[i] > 0 &&
        third_item_set[i] > 0) {
      return i + 1;
    }
  }
}

int
main()
{
  char one_buf[256];
  char two_buf[256];
  char three_buf[256];
  int score = 0;
  while (gets(one_buf) != 0) {
    gets(two_buf);
    gets(three_buf);
    score = score + score_input(one_buf, two_buf, three_buf);
  }

  printf("%d\n", score);
}