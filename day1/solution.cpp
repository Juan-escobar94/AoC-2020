#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#define MATCH_NUMBER 2020

using namespace std;

pair<int, int> findPairNumbers(vector<int> v) {
	
  int num;
  map<int,int> m;

  for(int i = 0; i < v.size(); i++) {
	  num = v[i];
	  m.insert(pair<int, int>(MATCH_NUMBER - num, num));
  }
  
  for(int i = 0; i < v.size(); i++) {
	  num = v[i];
	  if (m.count(num)) {
		  return (pair<int, int> (num, m.at(num)));
    }
  }
	  return pair<int, int> (-1, -1);
}

long long findProductOf3(vector<int> v) {
   long long ans;
   sort(v.begin(), v.end());
   for (int i = 0; i < v.size(); i++) {
     int l = i+1;
     int r = v.size() - 1;
     while (l < r) {
       if(v[i] + v[l] + v[r] == MATCH_NUMBER) {
	 printf("found 3 numbers: %d %d %d\n", v[i], v[l], v[r]);
         ans = v[i]*v[l]*v[r];
	 return ans;
       }
       else if (v[i] + v[l] + v[r] < MATCH_NUMBER) {
         l++;
       }
       else if (v[i] + v[l] + v[r] > MATCH_NUMBER) {
         r--;
       }
     }
   }
   return 0;
}

int main() {

  vector<int> v;

  int number;

  while(cin >> number) {
    v.push_back(number);
  }  

  pair<int, int> ansNumbers = findPairNumbers(v);

  cout << "first: " << ansNumbers.first << endl;
  cout << "second: " << ansNumbers.second << endl;
  cout << "product: " << ansNumbers.first * ansNumbers.second << endl;

 long long productOf3 = findProductOf3(v);

 cout << "product of 3: " << productOf3 << endl;
  return 0;
}
