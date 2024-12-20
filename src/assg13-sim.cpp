/** @file assg-main.cpp
 * @brief main/debug executable for Assignment Classes: classes defining user-defined
 *   data types.
 *
 * @author Jane Programmer
 * @note   cwid : 123 45 678
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VS Code Server 3.9.3 and Gnu/Make build tools
 * @note   assg : Assignment STL
 * @date   December 7, 2021
 *
 * Assignment C++ Standard Template Library STL
 */
#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * @brief Demonstrates the usage of Queue and Stack data structures using STL.
 *
 * This function creates a queue and a stack of integers, displays their
 * elements, and demonstrates how to access and remove elements using STL.
 *
 * @returns void
 */
void demonstrateQueueAndStack()
{
  // create a queue of integers
  queue<int> myQueue;

  // create a stack of integers
  stack<int> myStack;

  // Displaying queue elements
  cout << "Queue elements: ";
  while (!myQueue.empty())
  {
    // print the front element
    cout << myQueue.front() << " ";

    // remove the front element
    myQueue.pop();
  }

  // new line
  cout << endl;

  // Displaying stack elements
  cout << "Stack elements: ";
  while (!myStack.empty())
  {
    // print the top element
    cout << myStack.top() << " ";

    // remove the top element
    myStack.pop();
  }

  // new line
  cout << endl;
}

/**
 * @brief Demonstrates the usage of Maps and Unordered Maps using STL.
 *
 * This function creates an ordered map and an unordered map. it will displays
 * their key value pairs and show the differences between the two
 * types of maps.
 *
 * @returns void
 */
void demonstrateMaps()
{
  // create an ordered map
  map<int, string> orderedMap;

  // create an unorder map
  unordered_map<int, string> unorderedMap;

  // Displaying ordered map
  cout << "Ordered Map: ";
  for (const auto& pair : orderedMap)
  {
    // print key value
    cout << pair.first << ":" << pair.second << " ";
  }

  // new line
  cout << endl;

  // Displaying unordered map
  cout << "Unordered Map: ";
  for (const auto& pair : unorderedMap)
  {
    // print key value
    cout << pair.first << ":" << pair.second << " ";
  }

  // new line
  cout << endl;
}

/**
 * @brief Demonstrates the usage of List and Vector data structures using STL.
 *
 * This function creates a list and a vector of integers and displays their
 * elements. it will show us how to iterate through both data structures.
 *
 * @returns void
 */
void demonstrateListAndVector()
{
  // create a list
  list<int> myList;

  // create a vector
  vector<int> myVector;

  // display list elemements
  cout << "List: ";
  for (int value : myList)
  {
    // print each value
    cout << value << " ";
  }

  // new line
  cout << endl;

  // display vector elements
  cout << "Vector: ";
  for (int value : myVector)
  {
    // print each vector
    cout << value << " ";
  }

  // new line
  cout << endl;
}

/**
 * @brief Demonstrates the usage of Set data structure using STL.
 *
 * This function creates a set of integers and displays its elements,
 * this will show us how to iterate through a set.
 *
 * @returns void
 */
void demonstrateSet()
{
  // create set of integers
  set<int> mySet;

  // displaying set
  cout << "Set elements: ";
  for (int value : mySet)
  {
    // print line
    cout << value << " ";
  }

  // new value
  cout << endl;
}

/**
 * @brief Demonstrates the usage of Priority Queue data structure using STL.
 *
 * This function creates a priority queue of integers, displays its
 * elements, and show us how to access and remove elements from
 * the priority queue.
 *
 * @returns void
 */
void demonstratePriorityQueue()
{
  // create a priority queue
  priority_queue<int> myPQ;

  // displaying priority queue
  cout << "Priority Queue elements: ";
  while (!myPQ.empty())
  {
    // print the top element
    cout << myPQ.top() << " ";

    // remove the top element
    myPQ.pop();
  }

  // new line
  cout << endl;
}

/**
 * @brief Demonstrates STL Sorting on a Vector.
 *
 * This function creates a vector of integers, sorts it in ascending
 * order, and displays the sorted elements.
 *
 * @returns void
 */
void demonstrateSTLSorting()
{
  // new vector
  vector<int> myVector;

  // sorting the vector ascending order
  sort(myVector.begin(), myVector.end());

  // display the vector elemets
  cout << "Sorted vector: ";
  for (int value : myVector)
  {
    // print value
    cout << value << " ";
  }

  // new line
  cout << endl;
}

/** main entry point
 * Main entry point for debugging functions.
 *
 * @param argc The command line argument count, the number of arguments
 *   provided by user on the command line.
 * @param argv An array of char* old style c-strings.  Each argv[x]
 *   that is passed in holds one of the command line arguments provided
 *   by the user to the program when started.
 *
 * @returns int Returns 0 to indicate successfull completion of program,
 *   and a non-zero value to indicate an error code.
 */
int main(int argc, char** argv)
{
  // add code for debugging here
  cout << "Hello Assignment STL" << endl;

  // demonstrate functions
  demonstrateQueueAndStack();
  demonstrateMaps();
  demonstrateListAndVector();
  demonstrateSet();
  demonstratePriorityQueue();
  demonstrateSTLSorting();

  // return 0 to indicate successful completion
  return 0;
}