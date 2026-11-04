#include "mylib.h"

#include <iostream>

using namespace std;

// int positionX = 1;
// int positionY = 1;
string textcolor = "white";
string message = "";

// void setposition(int x, int y) {
//   positionX = x;
//   positionY = y;
//   cout << "\033[" << positionY << ";" << positionX << "H";
// }

void setColor(string color) {
  textcolor = color;
  if (textcolor == "red") {
    cout << "\033[31m";
  } else if (textcolor == "green") {
    cout << "\033[32m";
  } else if (textcolor == "yellow") {
    cout << "\033[33m";
  } else if (textcolor == "blue") {
    cout << "\033[34m";
  } else if (textcolor == "magenta") {
    cout << "\033[35m";
  } else if (textcolor == "cyan") {
    cout << "\033[36m";
  } else if (textcolor == "white") {
    cout << "\033[37m";
  }
}

// void setText(string text) {
//   message = text;
//   cout << message;
// }

void display(int x, int y, string message) {
  cout << "\033[" << y << ";" << x << "H";
  cout << message;
  // setposition(x, y);
  // setText(message);
  cout.flush();
}