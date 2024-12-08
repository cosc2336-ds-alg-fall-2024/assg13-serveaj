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

TEST_CASE("STL List and Vector", "[list_vector]")
{
  list<int> customList = {1, 2, 3};
  vector<int> customVector = {10, 20, 30};

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

TEST_CASE("STL Set", "[set]")
{
  set<int> customSet = {3, 1, 4, 1, 5};

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