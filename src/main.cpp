#include <iostream>

#include "mylib.h"

using namespace std;

int main() {
  cout << "\033[2J\033[H";  // clears terminal and moves cursor to top-left

  setColor("blue");
  display(5, 3, "Menu");

  display(5, 4, "Screen 1");

  setColor("white");
  display(5, 5, "Screen 2");

  display(1, 50, "Press any key to exit...");
  return 0;
}