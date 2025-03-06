#include "FindDuplicates.h"
#include <unordered_map>
#include <vector>

vector<int> findDuplicates(const vector<int> &nums) {
  //   +=====================================================+
  //   |                 WRITE YOUR CODE HERE                |
  //   | Description:                                        |
  //   | - This function finds duplicate integers in a given |
  //   |   vector.                                           |
  //   | - It uses an unordered_map to count each integer's  |
  //   |   occurrences.                                      |
  //   | - Loops through the map to find duplicates.         |
  //   |                                                     |
  //   | Return type: vector<int>                            |
  //   |                                                     |
  //   | Tips:                                               |
  //   | - 'numCounts' keeps track of each integer's count.  |
  //   | - 'duplicates' stores duplicate integers found.     |
  //   | - Check output from Test.cpp in "User logs".        |
  //   +=====================================================+

    unordered_map<int, int> mp;

    vector<int> duplicateReturner;

    for(auto i : nums){
        if(mp.find(i) == mp.end()){ // unavailable
            mp.insert({i,1});
        } else {
            mp[i]++;
        }
    }

    for(auto i : mp){
        if(i.second > 1){ // if the value is greater than 1 (NOTE: We are traversing through the map, that's why `i`)
            duplicateReturner.push_back(i.first);
        }
    }


    return duplicateReturner;
}

int main() {
  vector<int> vect1 = {1, 2, 3, 4, 2, 5, 7, 2, 4, 1};

  vector<int> duplicates = findDuplicates(vect1);
  cout << "Found duplicates: " << endl;


  for(auto i : duplicates){
      cout << i << endl;
  }
  return 0;
}
