/* 
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

import java.util.ArrayList;
import java.util.Collections;

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
    
    ArrayList<Integer> list = new ArrayList<>();

    

    for(int number : nums1){
      list.add(number);
    }    
  
    for(int number : nums2){
      list.add(number);
  }

    // sorting the elements
   Collections.sort(list);

  // Cross checking if every element is sorted in the list
    // for(int number : list)
    //   System.out.println(number);


    if(list.size() % 2 == 0 ){
      double a = list.get((list.size()/2) - 1);
      double b = list.get(list.size()/2);
      return (double) (a+b)/2;
    } else{
      return list.get(list.size()/2);
    }
  }
}


public class findMedianSortedArrays{
  public static void main(String[] args){

    int nums1[] = {1, 3};
    int nums2[] = {2, 4};

    Solution mySol = new Solution();
    System.out.println("Returning: " + mySol.findMedianSortedArrays(nums1, nums2));
  }
}
