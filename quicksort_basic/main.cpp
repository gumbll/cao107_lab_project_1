#include <iostream>
#include <string>
#include <chrono>
#include <cmath>
#include <vector>
#include "Timer.h"
using namespace std;

// Quicksort a portion (or all of) a vector of ints in ascending order
// args: reference to the vector, start and end indices of the section we want to sort
void quicksort(vector<int>& numbers, int start, int end);
// Used by quicksort: chooses pivot, moves lower numbers left, higher numbers right
int partition(vector<int>& numbers, int start, int end);
// Swap the values of two variables (using references)
void swap(int& left, int& right);
// Simple function to print out the contents of a vector (of integers)
void displayVector(vector<int>& theVector);

int main()
{
  vector<int>randomInts {13, 4, 20, 15, 13, 9, 2, 17, 1, 24, 22, 8, 14, 5, 13, 5, 7};
  cout << "\nUnsorted integers:\n";
  displayVector(randomInts);
  
  dmac::Timer timer;
  timer.start();
  quicksort(randomInts, 0, randomInts.size()-1);
  timer.stop();
  
  cout << "\nSorted integers:\n";
  displayVector(randomInts);
  cout << "\n--------------------------------------------\n";
  cout << "Total sort time: " << timer.timeTakenMilli() << " milliseconds.\n";
  cout << "--------------------------------------------\n";
}

void quicksort(vector<int>& numbers, int start, int end)
{
  // If our left and right indicies haven't finally collided 
  int pivotIndex = 0;
  if (start < end)
  {
    // Picks a number in (part of the) array and moves all 
    // smaller numbers left, all larger numbers right. 
    pivotIndex = partition(numbers, start, end);
    // Recursively call self for left and right sides until array is sorted.
    quicksort(numbers, start, pivotIndex - 1);
    quicksort(numbers, pivotIndex + 1, end);
  }
}

int partition(vector<int>& numbers, int left, int right)
{
  // Choose the left most number as the pivot.
  int pivotValue = numbers[left];
  int leftWall = left;  // Set up a wall always at latest lower-than-pivot-value index
  for (int i = leftWall + 1; i <= right; i++)
  {
    if (numbers[i] < pivotValue)
    {
      // Swap the small number with the large one next to the wall 
      swap(numbers[i], numbers[leftWall + 1]);
      leftWall += 1;	// Move the wall to gobble up the nice low value.
    }
  }
  // Swap original pivot (first item in list) with small number at wall
  swap(numbers[leftWall], numbers[left]);
  return leftWall;
}

void swap(int& left, int& right)
{
  int temp = left;
  left = right;
  right = temp;
}

void displayVector(vector<int>& theVector)
{
  cout << "[";
  for (int i = 0; i < theVector.size(); i++)
  {
    cout << theVector[i];
    if (i < theVector.size()-1)
    {
      cout << ",";
    }
  }
  cout << "]\n";
}