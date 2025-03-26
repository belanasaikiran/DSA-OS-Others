So, I haven't learned about STL yet. (21st March, 2025).

Last week, I gave an exam for Amazon and I have messed up with creating my own data structures which was really painful.
I wish I learned STL before the exam.

It's okay, It's not too late to learn it.
Starting it now.

---

Similar to how we include math.h, we include the header file for STL.

> STL library has all the data structures and algorithms that we need


STL has

- Algorithms
- Containers
- Iterators
- Functions
- Adaptors


### Containers

1. Pairs
  We can create a pair of two elements of different types or create a pair of two elements of the same type.

  ```cpp
  std::pair<int, std::string> p1(1, "Hello");
  std::pair<int, int> p2(2, 3);

  //  To access
  std::cout << p1.first << " " << p1.second << std::endl;
  std::cout << p2.first << " " << p2.second << std::endl;

  //  Can also have more than 2 elements using nested pairs
  std::pair<int, std::pair<int, int>> p3(1, std::make_pair(2, 3));
  std::cout << p3.first << " " << p3.second.first << " " << p3.second.second << std::endl;


 //  Pair Arrays
  pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
  cout << arr[1].first << " " << arr[1].second << std::endl;
  ```

2. Tuples
  We can create a tuple of two elements of different types or create a tuple of two elements of the same type.

  ```cpp
  std::tuple<int, std::string> t1(1, "Hello");
  std::tuple<int, int> t2(2, 3);
  ```

3. Vectors
  We can create a vector of elements of the same type.

  - push_back()
  - pop_back()
  - emplace_back()
  - insert()  - costly for inserting at the front of vector since vector uses Singly Linked Lists
  - erase()
  - clear()
  - capacity()
  - size()
  - empty()
  - at()
  - data()
  - begin()
  - end()
  - rbegin()
  - rend()

4. Lists
  We can create a list of elements of the same type.

  - push_back()
  - pop_back()
  - emplace_back()
  - push_front()
  - pop_front()
  - emplace_front()
  - insert()
  - erase()
  - clear()
  - size()
  - empty()
  - front()
  - back()
  - begin()
  - end()
  - rbegin()
  - rend()

5. Deques
  We can create a deque of elements of the same type.

  - push_back()
  - pop_back()
  - emplace_back()
  - push_front()
  - pop_front()
  - emplace_front()
  - insert()
  - erase()
  - clear()
  - size()
  - empty()
  - front()
  - back()
  - begin()
  - end()
  - rbegin()
  - rend()

6. Stack
  We can create a stack of elements of the same type.

  - push()
  - pop()
  - top()
  - size()
  - empty()

7. Queue
  We can create a queue of elements of the same type.

  - push()
  - pop()
  - front()
  - back()
  - size()
  - empty()

8. Priority Queue
  We can create a priority queue of elements of the same type.

  - push()
  - pop()
  - top()
  - size()
  - empty()

9. Set
  We can create a set of elements of the same type.

  - insert()
  - erase()
  - clear()
  - size()
  - empty()
  - find()
  - count()
  - lower_bound()
  - upper_bound()
  - equal_range()
  - begin()
  - end()
  - rbegin()
  - rend()

10. Map
  We can create a map of elements of the same type.

  - insert()
  - erase()
  - clear()
  - size()
  - empty()
  - find()
  - count()
  - lower_bound()
  - upper_bound()
  - equal_range()
  - begin()
  - end()
  - rbegin()
  - rend()
