#include "ItemInCommon.h"
#include<iostream>

bool itemInCommon(vector<int> vect1, vector<int> vect2) {
	//   +=====================================================+
	//   |                 WRITE YOUR CODE HERE                |
	//   | Description:                                        |
	//   | - This function checks if two vectors have a        |
	//   |   common element.                                   |
	//   | - It uses an unordered_map to store elements from   |
	//   |   the first vector.                                 |
	//   | - Then it checks each element from the second       |
	//   |   vector against the map.                           |
	//   |                                                     |
	//   | Return type: bool                                   |
	//   |                                                     |
	//   | Tips:                                               |
	//   | - 'myMap' stores elements from 'vect1' as keys.     |
	//   | - Loop through 'vect2' and check against 'myMap'.   |
	//   | - Check output from Test.cpp in "User logs".        |
	//   +=====================================================+
  std::unordered_map<int, bool> mp;

  for(auto i : vect1){ 
    mp.insert({i, true});
  } 

  for(auto i : vect2){
	if(mp[i]){
		return true;
	}
  }

  return 0;

}

int main(){
	vector<int> vect1 = {1, 2, 4};
	vector<int> vect2 = {3, 4, 5};

	std::cout << itemInCommon(vect1, vect2) << std::endl;
}
