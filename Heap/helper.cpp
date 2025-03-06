#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
  vector<int> heap;

  //  Helper Functions
  int leftChild(int index) {
    return 2 * index +
           1; // since we are using the first index as well. otherwise if not
              // using zero index, we can just return 2 * index
  }

  int rightChild(int index) { return 2 * index + 2; }

  int parent(int index) {
    return (index - 1) / 2; // do this on a paper to easily understand
  }

  void swap(int index1, int index2) {
    int temp = heap[index1];
    heap[index1] = heap[index2];
    heap[index2] = temp;
  }

  // Donw with Helpers

public:
  // Insertion
  void insert(int value) {
    heap.push_back(value);
    int current = heap.size() - 1;
    while (current > 0 &&
           heap[current] > heap[parent(current)]) { // current is the index
      swap(current, parent(current));
      current = parent(current);
    }
  }

  void sinkDown(int index) {
    //  Not all necessary to pass index since we have to adjust the first node
    int maxIndex = index;
    while (true) {
      int leftIndex = leftChild(index);
      int rightIndex = rightChild(index);

      if (leftIndex < heap.size() && heap[leftIndex] > heap[maxIndex]) {
        maxIndex = leftIndex;
      }

      if (rightIndex < heap.size() && heap[rightIndex] > heap[maxIndex]) {
        maxIndex = rightIndex;
      }

      if (maxIndex != index) {
        swap(index, maxIndex);
        index = maxIndex;
      } else {
        return;
      }
    }
  }

  int remove() {
    if (heap.empty()) {
      return INT_MIN;
    }

    if (heap.size() == 1) {
      int maxValue = heap.front();
      heap.clear();
      return maxValue;
    }

    int maxValue = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    sinkDown(0); // helper function call to move it to the appropriate place
    return maxValue;
  }

  void printHeap() {
    cout << "\n[";
    for (size_t i = 0; i < heap.size(); i++) {
      cout << heap[i];
      if (i < heap.size() - 1) {
        cout << ", ";
      }
    }
    cout << "]" << endl;
  }
};

int main() {
  Heap *myHeap = new Heap;
  myHeap->insert(99);
  myHeap->insert(72);
  myHeap->insert(61);
  myHeap->insert(58);
  myHeap->printHeap();

  myHeap->insert(100);
  myHeap->printHeap();

  myHeap->insert(75);
  myHeap->printHeap();

  myHeap->remove();
  myHeap->printHeap();
}
