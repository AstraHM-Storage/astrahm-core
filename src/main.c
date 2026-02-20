#include "raid6.h"
#include <stdio.h>

int main() {
  printf("AstraHM Storage Engine Starting...\n");

  raid6_init();
  raid6_encode();
  raid6_recover();
  raid6_layout();

  return 0;
}
