#include "aoc.h"

int
main()
{
  char boxes[100][50];
  int box_depth[10];

  // ain't nobody got time to parse that
  boxes[0][0] = 'W';
  boxes[0][1] = 'B';
  boxes[0][2] = 'D';
  boxes[0][3] = 'N';
  boxes[0][4] = 'C';
  boxes[0][5] = 'F';
  boxes[0][6] = 'J';
  box_depth[0] = 7;

  boxes[1][0] = 'P';
  boxes[1][1] = 'Z';
  boxes[1][2] = 'V';
  boxes[1][3] = 'Q';
  boxes[1][4] = 'L';
  boxes[1][5] = 'S';
  boxes[1][6] = 'T';
  box_depth[1] = 7;

  boxes[2][0] = 'P';
  boxes[2][1] = 'Z';
  boxes[2][2] = 'B';
  boxes[2][3] = 'G';
  boxes[2][4] = 'J';
  boxes[2][5] = 'T';
  box_depth[2] = 6;

  boxes[3][0] = 'D';
  boxes[3][1] = 'T';
  boxes[3][2] = 'L';
  boxes[3][3] = 'J';
  boxes[3][4] = 'Z';
  boxes[3][5] = 'B';
  boxes[3][6] = 'H';
  boxes[3][7] = 'C';
  box_depth[3] = 8;

  boxes[4][0] = 'G';
  boxes[4][1] = 'V';
  boxes[4][2] = 'B';
  boxes[4][3] = 'J';
  boxes[4][4] = 'S';
  box_depth[4] = 5;

  boxes[5][0] = 'P';
  boxes[5][1] = 'S';
  boxes[5][2] = 'Q';
  box_depth[5] = 3;

  boxes[6][0] = 'B';
  boxes[6][1] = 'V';
  boxes[6][2] = 'D';
  boxes[6][3] = 'F';
  boxes[6][4] = 'L';
  boxes[6][5] = 'M';
  boxes[6][6] = 'P';
  boxes[6][7] = 'N';
  box_depth[6] = 8;

  boxes[7][0] = 'P';
  boxes[7][1] = 'S';
  boxes[7][2] = 'M';
  boxes[7][3] = 'F';
  boxes[7][4] = 'B';
  boxes[7][5] = 'D';
  boxes[7][6] = 'L';
  boxes[7][7] = 'R';
  box_depth[7] = 8;

  boxes[8][0] = 'V';
  boxes[8][1] = 'D';
  boxes[8][2] = 'T';
  boxes[8][3] = 'R';
  box_depth[8] = 4;

  int num_boxes = 9;
  char buf[256];
  while (fgets(buf, 256, stdin)) {
    if (buf[0] != 'm') {
      continue;
    }

    int quantity = 0;
    int from = 0;
    int to = 0;
    sscanf(buf, "move %d from %d to %d", &quantity, &from, &to);
    memcpy(&boxes[to - 1][box_depth[to - 1]],
           &boxes[from - 1][box_depth[from - 1] - quantity],
           quantity);
    memset(&boxes[from - 1][box_depth[from - 1] - quantity], 0, quantity);
    box_depth[from - 1] = box_depth[from - 1] - quantity;
    box_depth[to - 1] = box_depth[to - 1] + quantity;
  }

  for (int i = 0; i < num_boxes; i++) {
    fputc(boxes[i][box_depth[i] - 1], stdout);
  }
  fputc('\n', stdout);
}