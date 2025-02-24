#include "FindDuplicates.h"
#include <unordered_map>

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
  unordered_map<int, int> numCounts;

  vector<int> duplicates;
  // Filler
  for (auto itr : nums) {
      if(numCounts.find(itr) == numCounts.end()){
          numCounts.insert({itr,1});
      } else { // found
          numCounts[itr]++;
      }
            cout << "numscount: "<< itr << ": " << numCounts[itr] << endl;
  }

  for(auto itr: numCounts){
      if(itr.second > 1){
          duplicates.push_back(itr.first);
      }
  }

  return duplicates;
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
