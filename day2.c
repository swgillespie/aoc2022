int
gets();
int
strtok();
int
printf();

int
main()
{
  char buffer[10];
  int score = 0;
  while (gets(buffer) != 0) {
    char them = buffer[0];
    char us = buffer[2];
    if (us == 'Y') {
      // forced draw.
      score = score + 3 + (them - 'A' + 1);
    } else if (us == 'Z') {
      // win.
      char winner;
      if (them == 'A') {
        winner = 'B';
      } else if (them == 'B') {
        winner = 'C';
      } else if (them == 'C') {
        winner = 'A';
      }

      score = score + 6 + (winner - 'A' + 1);
    } else if (us == 'X') {
      // loss.
      char loser;
      if (them == 'A') {
        loser = 'C';
      } else if (them == 'B') {
        loser = 'A';
      } else if (them == 'C') {
        loser = 'B';
      }

      score = score + (loser - 'A' + 1);
    }
  }

  printf("%d\n", score);
}