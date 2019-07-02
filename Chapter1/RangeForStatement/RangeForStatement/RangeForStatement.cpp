// Copyright © 2019 by Xitalogy.  MIT license:  https://opensource.org/licenses/MIT

#include <iostream>

int main() {

  int intAry[]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  int numElements = sizeof(intAry) / sizeof(int);

  std::cout << "Classic for statement:" << std::endl;

  for (int ii = 0; ii < numElements; ii++) {
    std::cout << intAry[ii] << ' ';
  }

  std::cout << std::endl << std::endl << "range-for-statement" << std::endl;

  for (auto xx : intAry) {
    std::cout << xx << ' ';
  }

  std::cout << std::endl << std::endl << "range-for-statement direct element list expression" << std::endl;

  for (auto xx : { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }) {
    std::cout << xx << ' ';
  }

  std::cout << std::endl << std::endl << "range-for-statement use reference to increment in place" << std::endl;

  for (auto& xx : intAry) {
    ++xx;
  }

  for (auto xx : intAry) {
    std::cout << xx << ' ';
  }

  std::cout << std::endl;
}