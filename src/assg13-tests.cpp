/** @file assg-tests.cpp
 * @brief Unit tests for Assignment Classes: practice on classes and user
 *   defined types.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VS Code Server 3.9.3 and Gnu/Make build tools
 * @note   assg : Assignment STL
 * @date   December 7, 2021
 *
 * Assignment Standard Template Library STL.
 */
#include "catch.hpp"
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

#define task1
#define task2
#define task3
#define task4
#define task5
#define task6

/** Task 1 example test task.  Demonstarte using an STL list
 * container.
 */
TEST_CASE("<list> test list STL container", "[task1]")
{
  // list of integers
  list<int> l1;

  // list should be initially empty
  CHECK(l1.empty());

  // add item, it is now not empty
  l1.push_front(5);
  CHECK_FALSE(l1.empty());
  CHECK(l1.size() == 1);
}

/**
 * Task 1 Queue and stack
 */
#ifdef task1
TEST_CASE("STL Queue and Stack", "[queue_stack]")
{
  queue<int> customQueue;
  stack<int> customStack;

  SECTION("Queue operations")
  {
    customQueue.push(10);
    customQueue.push(20);
    customQueue.push(30);

    CHECK(customQueue.size() == 3);
    CHECK(customQueue.front() == 10);

    customQueue.pop();
    CHECK(customQueue.front() == 20);
    CHECK(customQueue.size() == 2);

    customQueue.pop();
    customQueue.pop();
    CHECK(customQueue.empty());
  }

  SECTION("Stack operations")
  {
    customStack.push(1);
    customStack.push(2);
    customStack.push(3);

    CHECK(customStack.size() == 3);
    CHECK(customStack.top() == 3);

    customStack.pop();
    CHECK(customStack.top() == 2);

    customStack.pop();
    customStack.pop();
    CHECK(customStack.empty());
  }
}
#endif

/**
 * Task 2 Maps and Ordered maps
 */
#ifdef task2
TEST_CASE("STL Maps and Ordered Maps", "[maps]")
{
  map<int, string> orderedMap;
  unordered_map<int, string> unorderedMap;

  SECTION("Ordered map operations")
  {
    orderedMap[3] = "Three";
    orderedMap[1] = "One";
    orderedMap[2] = "Two";

    CHECK(orderedMap.size() == 3);
    auto it = orderedMap.begin();
    CHECK(it->first == 1);
    CHECK(it->second == "One");

    orderedMap.erase(2);
    CHECK(orderedMap.size() == 2);
    CHECK(orderedMap.count(2) == 0);
  }

  SECTION("Unordered map operations")
  {
    unorderedMap[3] = "Three";
    unorderedMap[1] = "One";
    unorderedMap[2] = "Two";

    CHECK(unorderedMap.size() == 3);
    CHECK(unorderedMap.count(1) == 1);

    unorderedMap.erase(3);
    CHECK(unorderedMap.size() == 2);
    CHECK(unorderedMap.count(3) == 0);
  }
}

// Additional STL Map Tests
TEST_CASE("STL Map - Extended", "[map]")
{
  map<int, string> customMap;
  customMap = {{1, "A"}, {2, "B"}, {3, "C"}};

  SECTION("Find and Count")
  {
    auto it = customMap.find(2);
    CHECK(it != customMap.end());
    CHECK(it->second == "B");

    CHECK(customMap.count(3) == 1);
    CHECK(customMap.count(5) == 0);
  }

  SECTION("Emplace and Swap")
  {
    customMap.emplace(4, "D");
    CHECK(customMap.size() == 4);
    CHECK(customMap[4] == "D");

    map<int, string> newMap;
    newMap = {{10, "X"}, {20, "Y"}};
    customMap.swap(newMap);

    CHECK(customMap.size() == 2);
    CHECK(customMap[10] == "X");
  }
}
#endif

/**
 * task 3 List and Vector
 */
#ifdef task3
TEST_CASE("STL List and Vector", "[list_vector]")
{
  list<int> customList;
  customList = {1, 2, 3};
  vector<int> customVector;
  customVector = {10, 20, 30};

  SECTION("List operations")
  {
    customList.push_back(4);
    customList.push_front(0);

    CHECK(customList.size() == 5);
    CHECK(customList.front() == 0);
    CHECK(customList.back() == 4);

    customList.pop_back();
    customList.pop_front();
    CHECK(customList.size() == 3);
  }

  SECTION("Vector operations")
  {
    customVector.push_back(40);
    customVector[0] = 100;

    CHECK(customVector.size() == 4);
    CHECK(customVector[0] == 100);
    CHECK(customVector.back() == 40);

    customVector.pop_back();
    CHECK(customVector.size() == 3);
  }
}

// Additional STL List Tests
TEST_CASE("STL List - Extended", "[list]")
{
  list<int> customList;
  customList = {10, 20, 30, 40, 50};

  SECTION("Insert and Remove Elements")
  {
    auto it = customList.begin();
    advance(it, 2); // Move iterator to the 3rd element
    customList.insert(it, 25);

    CHECK(customList.size() == 6);
    CHECK(*next(customList.begin(), 2) == 25);

    it = customList.begin();
    advance(it, 3); // Move iterator to the 4th element
    customList.erase(it);

    CHECK(customList.size() == 5);
    CHECK(*next(customList.begin(), 3) == 40);
  }

  SECTION("Reverse and Sort")
  {
    customList.reverse();
    CHECK(customList.front() == 50);
    CHECK(customList.back() == 10);

    customList.sort();
    CHECK(customList.front() == 10);
    CHECK(customList.back() == 50);
  }
}

// Additional STL Vector Tests
TEST_CASE("STL Vector - Extended", "[vector]")
{
  vector<int> customVector;
  customVector = {5, 15, 25, 35, 45};

  SECTION("Resize and Reserve")
  {
    customVector.resize(10, 100);
    CHECK(customVector.size() == 10);
    CHECK(customVector[6] == 100);

    customVector.reserve(20);
    CHECK(customVector.capacity() >= 20);
  }

  SECTION("Erase and Clear")
  {
    customVector.erase(customVector.begin() + 2);
    CHECK(customVector.size() == 4);
    CHECK(customVector[2] == 35);

    customVector.clear();
    CHECK(customVector.empty());
  }
}
#endif

/**
 * Task 4 set
 */
#ifdef task4
TEST_CASE("STL Set", "[set]")
{
  set<int> customSet;
  customSet = {3, 1, 4, 1, 5};

  SECTION("Set operations")
  {
    CHECK(customSet.size() == 4);
    CHECK(customSet.count(3) == 1);
    CHECK(customSet.count(6) == 0);

    customSet.insert(6);
    CHECK(customSet.size() == 5);
    CHECK(customSet.count(6) == 1);

    customSet.erase(1);
    CHECK(customSet.size() == 4);
    CHECK(customSet.count(1) == 0);
  }
}

// Additional STL Set Tests
TEST_CASE("STL Set - Extended", "[set]")
{
  set<int> customSet;
  customSet = {10, 20, 30, 40};

  SECTION("Lower and Upper Bound")
  {
    auto it = customSet.lower_bound(25);
    CHECK(it != customSet.end());
    CHECK(*it == 30);

    it = customSet.upper_bound(20);
    CHECK(it != customSet.end());
    CHECK(*it == 30);
  }
}
#endif

/**
 * Task 5 Priority Queue
 */
#ifdef task5
TEST_CASE("STL Priority Queue", "[priority_queue]")
{
  priority_queue<int> customPriorityQueue;

  SECTION("Priority Queue operations")
  {
    customPriorityQueue.push(10);
    customPriorityQueue.push(30);
    customPriorityQueue.push(20);

    CHECK(customPriorityQueue.size() == 3);
    CHECK(customPriorityQueue.top() == 30);

    customPriorityQueue.pop();
    CHECK(customPriorityQueue.top() == 20);
    CHECK(customPriorityQueue.size() == 2);

    customPriorityQueue.pop();
    customPriorityQueue.pop();
    CHECK(customPriorityQueue.empty());
  }
}

// Additional STL Priority Queue Tests
TEST_CASE("STL Priority Queue - Extended", "[priority_queue]")
{
  priority_queue<int> customPQ;

  SECTION("Custom Comparator")
  {
    auto cmp = [](int left, int right) { return left > right; };
    priority_queue<int, vector<int>, decltype(cmp)> minPQ(cmp);

    minPQ.push(20);
    minPQ.push(10);
    minPQ.push(30);

    CHECK(minPQ.top() == 10);

    minPQ.pop();
    CHECK(minPQ.top() == 20);
  }
}

#endif

/**
 * Task 6 Sorting
 */
#ifdef task6
TEST_CASE("STL Sorting and Algorithms", "[sorting_algorithms]")
{
  vector<int> customVector;
  customVector = {30, 10, 20, 50, 40};

  SECTION("Sorting")
  {
    sort(customVector.begin(), customVector.end());
    CHECK(customVector == vector<int>{10, 20, 30, 40, 50});
  }

  SECTION("Reverse Sorting")
  {
    sort(customVector.rbegin(), customVector.rend());
    CHECK(customVector == vector<int>{50, 40, 30, 20, 10});
  }

  SECTION("Using find algorithm")
  {
    auto it = find(customVector.begin(), customVector.end(), 20);
    CHECK(it != customVector.end());
    CHECK(*it == 20);

    it = find(customVector.begin(), customVector.end(), 100);
    CHECK(it == customVector.end());
  }

  SECTION("Count Algorithm")
  {
    customVector = {1, 2, 3, 4, 1, 1, 5};
    CHECK(count(customVector.begin(), customVector.end(), 1) == 3);
    CHECK(count(customVector.begin(), customVector.end(), 6) == 0);
  }
}

// Additional STL Algorithms
TEST_CASE("STL Algorithms - Extended", "[algorithms]")
{
  vector<int> customVector;
  customVector = {10, 20, 30, 40, 50};

  SECTION("Accumulate")
  {
    int sum = accumulate(customVector.begin(), customVector.end(), 0);
    CHECK(sum == 150);
  }

  SECTION("Replace")
  {
    replace(customVector.begin(), customVector.end(), 30, 99);
    CHECK(customVector[2] == 99);
  }

  SECTION("Unique")
  {
    customVector = {10, 10, 20, 30, 30, 30, 40};
    auto it = unique(customVector.begin(), customVector.end());
    customVector.erase(it, customVector.end());

    CHECK(customVector == vector<int>{10, 20, 30, 40});
  }

  SECTION("Partition")
  {
    auto it = partition(customVector.begin(), customVector.end(), [](int n) { return n % 20 == 0; });
    CHECK(distance(customVector.begin(), it) == 2);
  }
}
#endif