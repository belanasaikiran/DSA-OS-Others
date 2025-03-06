#include "GroupAnagrams.h"
#include <vector>

vector<vector<string>> groupAnagrams(const vector<string> &strings) {
  //   +=====================================================+
  //   |                 WRITE YOUR CODE HERE                |
  //   | Description:                                        |
  //   | - This function groups anagrams from a given vector |
  //   |   of strings.                                       |
  //   | - It uses an unordered_map for organization.        |
  //   | - It sorts each string to form a canonical version. |
  //   | - Groups strings with the same canonical form.      |
  //   |                                                     |
  //   | Return type: vector<vector<string>>                 |
  //   |                                                     |
  //   | Tips:                                               |
  //   | - 'anagramGroups' maps canonical strings to groups. |
  //   | - 'canonical' is a sorted version of each string.   |
  //   | - 'result' holds the final groups of anagrams.      |
  //   | - Check output from Test.cpp in "User logs".        |
  //   +=====================================================+

  unordered_map<string, vector<string>> anagramGroups;

  for (auto word : strings) {
      string key = word;
      sort(key.begin(), key.end());
      anagramGroups[key].push_back(word);
  }


  vector<vector<string>> returnArray;

  for(auto wordInAnagramGroups : anagramGroups){
      returnArray.push_back(wordInAnagramGroups.second); // adding that entire vector of anagramGroups map to the returnArray.
  }

  return returnArray;

}


int main(){
    vector<string> inputArr = {"eat", "ate", "bat", "tab"};

    vector<vector<string>> output = groupAnagrams(inputArr);

    for(auto eachArray : output){
        cout << "[ " ;

        for(auto word : eachArray){
            cout << " " << word;
        }
        cout << " ]" << endl;
    }
}
