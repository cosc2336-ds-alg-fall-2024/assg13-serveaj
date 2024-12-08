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
#include <queue>
#include <stack>
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