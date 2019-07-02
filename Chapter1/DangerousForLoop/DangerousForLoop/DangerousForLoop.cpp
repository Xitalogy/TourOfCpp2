// Copyright © 2019 by Xitalogy.  MIT license:  https://opensource.org/licenses/MIT

#include <iostream>

struct {
  const char chAry1[4] = { '1', '2', '3', '4' };
  const char chAry2[4] = { '5', '6', '7', '\0' };
} twoChArys;

// Bjarne Stroustrup's code - dangerous - if p not null terminated,
// could loop for a long time, reading far past p's buffer contents
int count_x(const char* p, char x)

// count the number of occurrences of x in p[]
// p is assumed to point to a zero-terminated array of char (or to nothing)
{
  if (p == nullptr)
    return 0;
  
  int count = 0;
  
  for (; *p != 0; ++p)
    if (*p == x) ++count;

  return count;
}

// Not "safe," but "safer" - could read beyond end of ptrToStrZero,
// but limited by maxStrSize, so better control here than Stroustrup's example
size_t CountOfChSafer(const char* ptrToStrZero, char ch, size_t maxStrSize) {

  if (ptrToStrZero == nullptr) {
    throw std::runtime_error("ptrToStrZero was null pointer.");
  }

  size_t ii = 0;
  
  size_t count = 0;

  for (size_t ii = 0; ptrToStrZero[ii] != 0; ++ii) {

    if (ii == maxStrSize) {

      // Returning maxStrSize signals error condition - no null character found but
      // maxStringSize reached. Also resturns maxStrSize if string valid but bigger
      // than maxStringSize (string size inclusive of terminating null).
      return maxStrSize;
    }

    if (ptrToStrZero[ii] == ch) {
      ++count;
    }
  }

  return count;
}

int main()
{
  std::cout << count_x("h", 'h') << std::endl;
  std::cout << count_x(twoChArys.chAry1, '7') << std::endl;
  std::cout << std::endl;
  std::cout << CountOfChSafer("h", 'h', 1) << std::endl;
  std::cout << CountOfChSafer("h", 'h', 0) << std::endl;
  std::cout << std::endl;
  std::cout << CountOfChSafer(twoChArys.chAry1, '3', 4) << std::endl;
  std::cout << CountOfChSafer(twoChArys.chAry1, '3', 5) << std::endl;
  std::cout << CountOfChSafer(twoChArys.chAry1, '3', 6) << std::endl;
  std::cout << std::endl;
  std::cout << CountOfChSafer(twoChArys.chAry1, '7', 8) << std::endl;
  std::cout << CountOfChSafer(twoChArys.chAry1, '7', 9) << std::endl;
  std::cout << CountOfChSafer(twoChArys.chAry1, '7', 10) << std::endl;
}