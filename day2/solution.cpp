#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main()  {
  int a, b;
  char c[2];
  char d[25];
  int i = 0;
  while(scanf("%d-%d %1s: %20s\n", &a, &b, &c, &d) != EOF) {
    // part one
    //int hits = 0;
    //for (int j = 0; j < strlen(d); j++) {
    // if(d[j] == c[0]) hits++;
    //}
    //if (hits >= a && hits <= b) i++;
    // part two
    const unsigned char bitOne = (d[a-1] == c[0]) ? 0x1 : 0x0;
    const unsigned char bitTwo = (d[b-1] == c[0]) ? 0x1 : 0x0;

    if (bitOne^bitTwo) i++;
  } 
  cout << i << endl;
  return 0;
}
