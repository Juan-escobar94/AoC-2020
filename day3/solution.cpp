#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>

#define A_SIZE 32

using namespace std;
int main () {

  long trees[6];
  memset(trees, 0, sizeof(trees));
  
  int i = 3, j = 1, l = 5, k = 7;
  int down_two = 1;
  int down_two_flag = 0;
  
  char tree_chart[A_SIZE];

  // ignore first line 
  scanf("%32s\n", &tree_chart);
  while(scanf("%32s\n", &tree_chart) != EOF) {
    if (tree_chart[i] == '#') trees[0]++;
    i = (i + 3) % (A_SIZE - 1);

    if(tree_chart[j] == '#') trees[1]++;
    j = (j + 1) % (A_SIZE - 1);

    if(tree_chart[l] == '#') trees[2]++;
    l = (l + 5) % (A_SIZE - 1);

    if(tree_chart[k] == '#') trees[3]++;
    k = (k + 7) % (A_SIZE - 1);
    
    if (down_two_flag) {
      if(tree_chart[down_two] == '#') trees[4]++; 
      down_two = (down_two + 1) % (A_SIZE -1);
    }
    down_two_flag = 1 - down_two_flag;    


  } 
  
  cout << "right(3): " << trees[0] << endl;
  cout << "right(1): " << trees[1] << endl;
  cout << "right(5): " << trees[2] << endl;
  cout << "right(7): " << trees[3] << endl;
  cout << "down(2): " << trees[4] << endl;
  long long product = trees[0] * trees[1] * trees[2] * trees[3] * trees[4];
  cout << "product: " << product << endl;
  return 0;
}
