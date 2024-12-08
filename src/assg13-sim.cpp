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
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

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

  // return 0 to indicate successful completion
  return 0;
}

// Task 1: Queue and Stack
void demonstrateQueueAndStack()
{
  queue<int> myQueue;
  stack<int> myStack;

  // Displaying queue elements
  cout << "Queue elements: ";
  while (!myQueue.empty())
  {
    cout << myQueue.front() << " ";
    myQueue.pop();
  }
  cout << endl;

  // Displaying stack elements
  cout << "Stack elements: ";
  while (!myStack.empty())
  {
    cout << myStack.top() << " ";
    myStack.pop();
  }
  cout << endl;
}

// Task 2: Maps and Ordered Maps
void demonstrateMaps()
{
  map<int, string> orderedMap;
  unordered_map<int, string> unorderedMap;

  // Displaying ordered map
  cout << "Ordered Map: ";
  for (const auto& pair : orderedMap)
  {
    cout << pair.first << ":" << pair.second << " ";
  }
  cout << endl;

  // Displaying unordered map
  cout << "Unordered Map: ";
  for (const auto& pair : unorderedMap)
  {
    cout << pair.first << ":" << pair.second << " ";
  }
  cout << endl;
}