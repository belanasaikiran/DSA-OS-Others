// You are given an array of CPU tasks, each labeled with a letter from A to Z,
// and a number n. Each CPU interval can be idle or allow the completion of one
// task. Tasks can be completed in any order, but there's a constraint: there
// has to be a gap of at least n intervals between two tasks with the same
// label.

// Return the minimum number of CPU intervals required to complete all tasks.

// Example 1:
// Input: tasks = ["A","A","A","B","B","B"], n = 2
// Output: 8
// Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A ->
// B. // After completing task A, you must wait two intervals before doing A
// again. The same applies to task B. In the 3rd interval, neither A nor B can
// be done, so you idle. By the 4th interval, you can do A again as 2 intervals
// have passed.

// Example 2:
// Input: tasks = ["A","C","A","B","D","B"], n = 1
// Output: 6
// Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.
// With a cooling interval of 1, you can repeat a task after just one other
// task.
//
// Example 3:
// Input: tasks = ["A","A","A", "B","B","B"], n = 3
// Output: 10
// Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle
// -> idle -> A -> B.
// There are only two types of tasks, A and B, which need to be separated by 3
// intervals. This leads to idling twice between repetitions of these tasks.
//
//
#include <complex.h>
#include <iostream>
#include <queue>
#include <uchar.h>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {

    int freq[26] = {0};
    for (char &ch : tasks) {
      freq[ch - 'A']++; // convert to int and store in an Array -> A-Z = 0-26
                        // for indices, and values are frequency
    }

    // Use Max Heap to store frquencies
    priority_queue<int> pq;
    for (int i = 0; i < 26; i++) {
      if (freq[i] > 0) {
        pq.push(freq[i]); // values with more frequcney are on Top in Max Heap
      }
    }

    // process each task until the heap is empty
    int time = 0;

    while (!pq.empty()) { // run this until the heap is empty
      int cycle = n + 1;
      vector<int> store;
      int taskCount = 0;

      while (cycle-- && !pq.empty()) {
        if (pq.top() > 1) {
          store.push_back(pq.top() - 1);
        }
        pq.pop();
        taskCount++;
      }

      for (int &x : store) {
        pq.push(x);
      }

      time += (pq.empty() ? taskCount : n + 1);
    }
    return time;
  }

  int leastInterval2(vector<char> &tasks, int n) {
    unordered_map<char, int> counts;
    for (char c : tasks)
      counts[c]++;
    priority_queue<int> pq;
    for (auto c : counts)
      pq.push(c.second);

    int result = 0;
    while (!pq.empty()) {
      int time = 0;
      vector<int> tmp;
      for(int i = 0; i < n+1; ++i){
          if(!pq.empty()){
              tmp.push_back(pq.top() - 1);
              pq.pop();
              time++;
          }
      }

      for(auto t: tmp){
          if(t) pq.push(t); // if count > 0, push it back to pq.
      }

      result += pq.empty() ? time : n+1;
    }

    return result;
  }
};

int main() {
  Solution *mySol = new Solution;
  // Input: tasks = ["A","A","A","B","B","B"], n = 2
  vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  int n = 2;

  int minIntervals = mySol->leastInterval(tasks, n);

  cout << minIntervals << endl;

  return 0;
}
