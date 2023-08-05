#include <bits/stdc++.h>

using namespace std;

struct memo {
  int value;
  int index;
};

vector <int> findPositions(vector <int> arr, int x) {
  int n = arr.size();  
  int iterations = 0;
  
  vector<memo> arrStruct;
  vector<int> output;

  for (int index = 0; index < arr.size(); index++) {
    memo element;
    element.value = arr.at(index);
    element.index = index + 1; // 1-base indexing
    arrStruct.push_back(element);
  }
  
  while(iterations < x && arrStruct.size() > 0) {
    int elementsToPop = (x < arrStruct.size())?x:arrStruct.size();
    
    vector<memo> poppedNreducedStruct;
    int max = arrStruct.front().value;
    
    for (int getMaxIndex = 0; getMaxIndex < elementsToPop; getMaxIndex++) {
      if (max < arrStruct.at(getMaxIndex).value) {
        max = arrStruct.at(getMaxIndex).value;
      }
    }
    
    bool singleMaxPop = false;
    for (int popCount = 0; popCount < elementsToPop; popCount++) {
      if (max == arrStruct.front().value && !singleMaxPop) {
        output.push_back(arrStruct.begin()->index);
        arrStruct.erase(arrStruct.begin());
        singleMaxPop = true;
      } else {
        int pnrVal = arrStruct.front().value;
        int pnrIndex = arrStruct.front().index;
        pnrVal = (pnrVal > 0)? --pnrVal : pnrVal;
        memo pnrStruct;
        pnrStruct.value = pnrVal;
        pnrStruct.index = pnrIndex;
        poppedNreducedStruct.push_back(pnrStruct);
        arrStruct.erase(arrStruct.begin());
      }
    }

    for (int indexPNR = 0; indexPNR < poppedNreducedStruct.size(); indexPNR++) {
      arrStruct.push_back(poppedNreducedStruct.at(indexPNR));
    }
    poppedNreducedStruct.clear();

    iterations++;
  }
  
  return output;
}

int main() {
  int n_1 = 6;
  int x_1 = 5;
  vector <int> arr_1{1, 2, 2, 3, 4, 5};
  vector <int> expected_1{5, 6, 4, 1, 2 };
  vector <int> output_1 = findPositions(arr_1, x_1);
  cout << expected_1 == output_1;

  int n_2 = 13;
  int x_2 = 4;
  vector <int> arr_2{2, 4, 2, 4, 3, 1, 2, 2, 3, 4, 3, 4, 4};
  vector <int> expected_2{2, 5, 10, 13};
  vector <int> output_2 = findPositions(arr_2, x_2);
  cout << expected_2 == output_2;  
}
