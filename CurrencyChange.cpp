/* Program to calculate a targeted sum (int) using given values (int) */

#include <bits/stdc++.h>

using namespace std;

bool exactSumTarget(int targetMoney, vector<int>& denominations, int count) {
  while(true) {
    vector<int> cCounts(denominations.size(), 0);    
    
    string sCount = to_string(count);
    reverse(sCount.begin(), sCount.end());
    for (int index = 0; index < denominations.size(); index++) {
      if (index < sCount.length()) {
        int intCount = sCount.at(index) - '0';
        cCounts[denominations.size() - index - 1] = intCount;
      } 
    }
    
    int cCountsSum = 0;
    for (int index = 0; index < denominations.size(); index++) {
      cCountsSum += denominations.at(index) * cCounts.at(denominations.size() - index - 1);
    }

    if (cCountsSum == targetMoney) {
      return true;
    }

    bool all9 = true;
    for (int index = 0; index < cCounts.size(); index++) {
      if (cCounts.at(index) != 9) {
        all9 = false;
        break;
      }
    }
    if (all9) {
      return false;
    }
    ++count;
  }
}

bool canGetExactChange(int targetMoney, vector<int>& denominations){
  return exactSumTarget(targetMoney, denominations, 1);
}

int main(){
  int target_1 = 94;
  vector<int> arr_1{5, 10, 25, 100, 200};
  bool expected_1 = false;
  bool output_1 = canGetExactChange(target_1, arr_1); 
  cout << expected_1 != output_1;

  int target_2 = 75;
  vector<int> arr_2{4, 17, 29};
  bool expected_2 = true;
  bool output_2 = canGetExactChange(target_2, arr_2); 
  cout << expected_2 == output_2; 

  int target_3 = 33;
  vector<int> arr_3{4, 17, 29};
  bool expected_3 = true;
  bool output_3 = canGetExactChange(target_3, arr_3); 
  cout << expected_3 == output_3; 

  return 0; 
}
