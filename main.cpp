#include <iostream>
#include <vector>
#include <algorithm>
#include "stdlib.h"

using namespace std;


int minValue(int values[], int size) {
  int min = values[0];
  for (int i = 1; i < size; i++) {
    if (values[i] < min) {
      min = values[i];
    }
  }
  return min;
}

int maxValueAfterMin(int values[], int size, int min) {
  int max = 0;
  bool foundMin = false;
  for (int i = 0; i < size; i++) {
    if (values[i] == min) {
      foundMin = true;
    } else if (foundMin && values[i] > max) {
      max = values[i];
    }
  }
  return max;
}

int marketBuyer(vector<int> &data, int min, int max) {
    bool flag = true;
    bool buy = false;
    int lot = 0;
    int rev = 0;
    for (int i = 0; i < data.size(); i++) {
        int j = i + 1;
        if (data.at(i) == min || data.at(j) == min) {
            if (flag) {
                lot++;
                rev -= min;
                flag = false; 
                i++;
                j++;  
            }
        }
        if (!flag) {
            if (data.at(i) > data.at(j)) {
                while (lot > 0) {
                    rev += data.at(i);
                    lot--;
                    // cout << rev << " v " << lot << " v " << data.at(i) << endl;
                    buy = true;
                }
            }
            if (buy) {
                if (data.at(i) < data.at(j)) {
                    
                    lot += rev / data.at(i);
                    rev -= data.at(i) * lot;
                    // cout << rev << " v " << lot << " v " << data.at(i) << endl;
                    buy = false;
                }
            }
        }
        if (data.at(i) == max) {
            break;
        }
        // cout << "rev --> " << rev << " lot --> " << lot << endl;
        j++;
    }
    return rev;
}

int main(void) {
    
    int arr[] =  {20, 5, 15, 35, 10, 50, 80, 40};
    int min = minValue(arr, 8);
    int max = maxValueAfterMin(arr, 8, min);
    vector<int> data;

    for (int i : arr) {
        data.push_back(i);
    }

    int revenue = marketBuyer(data, min, max);
    cout << "max revenue is: " << revenue << endl;

}
