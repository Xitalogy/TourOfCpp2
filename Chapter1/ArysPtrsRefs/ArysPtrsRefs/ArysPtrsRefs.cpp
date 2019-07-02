// Copyright © 2019 by Xitalogy.  MIT license:  https://opensource.org/licenses/MIT

#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>

#pragma pack(push, 4)
struct {
  char a[4] { 0, 1, 2, 3 };
  char* pa{ a };

  int x{ 0x04030201 };
  int y{ 0x08070605 };

  int* p1{ &x };
  int* p2{ &y };

  int& rx{ x };
  int& ry{ y };
} st;
#pragma pack(pop)

size_t ii = 0;

/*
void theDataStructureCodeExampleTest() {
  int i{ st.x };    // i now equals 0x04030201, which is the value in x
  int* p3{ st.p1 }; // p3 points to the same thing as p1 (that is, st.x)
  *p3 = *st.p2;     // The contents of what p3 points to now equals the contents
                    // of what st.p2 points to (that is, st.x == st.y)
}

void ArrayAndPointerBasicsCodeExampleTest() {
  st.a[1] = 5; // second array element (st.a[1]) now equals 5
  *st.pa = 12; // first array element (st.a[0]) now equals 12
}

void ArrayAndPointerBasicsArraysCodeExampleTest01() {
  char a[4]{ 'a', 'b', 'c', 'd' };
}

void ArrayAndPointerBasicsArraysCodeExampleTest02() {
  char a[]{ 'a', 'b', 'c', 'd' };
}

//void ArrayAndPointerBasicsArraysCodeExampleTest03() {
//  struct {
//    char a[]{ 'a', 'b', 'c', 'd' }; // "Error(active) E0070 incomplete type is not allowed" - Visual Studio
//  } st;
//}

void ArrayAndPointerBasicsArraysCodeExampleTest04() {
  char a[]{ 'a', 'b', 'c', 'd' }; // declare and initialize a 4 element char array
  char c{ a[0] }; // initialize the char variable c to the contents of the first element in array a
  a[3] = 'q';     // a[3], the fourth element in the array a, now equals 'q'
  c = a[3];       // c now equals 'q'
}

void ArrayAndPointerBasicsPointersCodeExampleTest01() {
  char a[]{ 'a', 'b', 'c', 'd' }; // declare and initialize a 4 element char array
  char* pa{ a }; // declare pointer-to-char variable pa and point it to a[0]
  pa = &a[3];    // pa now contains the address of a[3], hence, pointing to fourth element in a
}

void ArrayAndPointerBasicsPointersCodeExampleTest01a() {
  char a[]{ 'a', 'b', 'c', 'd' }; // declare and initialize a 4 element char array
  char* pa{ &a[0] }; // declare pointer-to-char variable pa and point it to a[0]
  char c{ *pa };     // declare a char variable c, initialize it with a[0], which is the character 'a'
  pa = a;            // no change to address in pointer pa - a equivalent to &a[0]
  c = *pa;           // contents of a[0], the character 'a', just reassigned to c - no change in c
}

void ArrayAndPointerBasicsPointersCodeExampleTest02() {
  char a[]{ 'a', 'b', 'c', 'd' }; // declare and initialize a 4 element char array
  char* pa1{ a };     // pa1 now points to a[0]
  *pa1 = 'q';         // The contents of a[0] is now 'q'
  pa1 = &a[3];        // pa1 now points to a[3], the fourth element of array a
  char c{ *pa1 };     // Declare a char variable c and initialize it with the contents of a[3]
  char* pa2{ &a[2] }; // Declare a pointer to char variable pa2 and initialize it with the address of a[2]
  pa1 = pa2;          // Put the address in pa2 in pa1.  pa1 now points to a[2]
}

void ArrayAndPointerBasicsPointersCodeExampleTest03() {
  char a[]{ 0x05, 0x11, 0x07, 0x12, 0x39, 0x4B, 0x7F, 0x02 }; // Declare and initialize array of 8 numbers (char type)
  char* pa{ &a[2] }; // pa points to a[2], the third element in array a
  char c = *pa;      // char variable c == 0x07, the "contents of" what pa points to
}

void ArrayAndPointerBasicsPointersCodeExampleTest04() {
  char a[]{ 0x05, 0x11, 0x07, 0x12, 0x39, 0x4B, 0x7F, 0x02 }; // Declare and initialize array of 8 numbers (char type)
  char* pa{ a };  // pa points to first element of a, a[0]
  pa++;           // increment address in pa by 1 char (byte) - points to a[1]
  char c{ *pa };  // c == 0x11 - the contents of a[1]
  char* pa2{ a }; // pa points to a[0], first element of a
  pa2 += 7;       // pa points to a[7], eighth (last) element of a
  *pa2 = 3;       // "contents of" pa (a[7]) now equals 3
}

void ArrayAndPointerBasicsPointersCodeExampleTest05() {
  int a[]{ 0x04020100, 0x07060504, 0x0B0A0908 }; // Declare and initialize array of 3 integers
  int* pa{ a };  // pointer to int pa points to first element of a, a[0]
  pa++;          // increment the address in pa by 1 int (4 bytes) - points to a[1]
  int i{ *pa };  // i == 0x07060504 - the contents of a[1]
  int* pa2{ a }; // pa2 points to a[0], first element of a
  pa2 += 2;      // pa2 points to a[2], the third element of a.  The address stored in
                 // pa2 is now 8 (2 * 4) bytes higher than it was before the addition
  ++(*pa2);      // "contents of" pa (a[2]) now equals 0x0B0A0909 (notice ending 9)
                 // address in the pointer variable p2 stays the same
}

void referenceBasicsCodeExampleTest01() {
  int x;        // declare integer variable x
  int& rx{ x }; // rx is a reference variable referring to the integer variable x
}

void referenceBasicsCodeExampleTest02() {
  int x;        // declare x
  int& rx{ x }; // declare the rx reference member object and initialize to to refer to x
  rx = 3;       // x (not rx) now equals 3
  int y{ rx };  // Declare an integer y and initialize it to 3, the contents of x
}

void referenceBasicsCodeExampleTest03() {
  int x{ 1 };    // declare x, initialize value to 1
  int y{ 2 };    // declare y, initialize value to 2
  int& rx{ x };  // declare and initialize reference to x
  int& ry{ y };  // declare and initialize reference to y
  rx = y;        // doesn't change the reference rx - puts the value of y in x
  rx = 3;        // doesn't change the reference rx - puts 3 in x
  rx = ry;       // does not make rx reference y, just puts value of y in x
  int* px{ &x }; // declare and initialize a pointer to x
  //ry = px;       // Error(active) E0513 a value of type "int *" cannot be assigned to an entity of type "int" - Visual Studio
}

void referenceBasicsCodeExampleTest04() {
  int x{ 1 };   // declare x and initialize to 1
  int& rx{ x }; // declare and initialize reference to x
  rx++;         // x == 2; rx unchanged
  rx *= 6;      // x == 12; rx unchanged
}

void theDataStructureAgainCodeExampleTest() {
  struct myStruct { // declare the struct and give it a name
    int x;          // single member variable inside the struct
  } st;             // instantiate the declared struct as the variable st

  struct myStruct* stp{ &st }; // declare a pointer of type myStruct and point it to st
  st.x = 3;      // set the member object x within the struct st to 3 using the name
  int i{ 5 };    // declare a variable of type int and initialize it with the value 5
  i = stp->x;    // using the pointer to the struct st, put the contents of member element x in i (i == 3)
  (*stp).x = 12; // illustrates explicitly what the arrow pointer above does - dereference the struct
                 // then access the member inside by name - puts the value 12 in st.x
}

void deepDiveInitialDiscussionCodeExampleTest() {
  size_t ii = 0;         // declare and initialize index variable ii
  st.a[ii] = 'x';        // set a[ii] to printable character
  std::cout << st.a[ii]; // example only: output first char array element at index 0
}
*/

std::string numToHexStr(uintptr_t num, size_t size)
{
  std::stringstream ss;

  uintptr_t mask{ 0 };
  size_t shiftBits = (sizeof(mask) - size) * 8;

  mask = (~mask << shiftBits) >> shiftBits;

  ss << std::hex << std::uppercase << std::setw(static_cast<std::streamsize>(size) * 2) << std::setfill('0') << (num & mask);

  return ss.str();
}

std::string memDump()
{
  std::stringstream ss;

  ss << "Hex Dump of Structure Memory - Low Address ----> High Address" << std::endl << " ";

  struct dMeta {
    std::string desc;
    size_t len;
  };

  std::vector<dMeta> dmpMeta{ { "a", sizeof(st.a) }, { "pa", sizeof(st.pa) }, { "x", sizeof(st.x) }, { "y", sizeof(st.y) },
                              { "p1", sizeof(st.p1) }, { "p2", sizeof(st.p2) }, { "rx", sizeof(uintptr_t) }, { "ry", sizeof(uintptr_t) } };

  for (size_t ii = 0; ii < dmpMeta.size(); ii++) {
    ss << std::setw(static_cast<std::streamsize>(dmpMeta[ii].len) * 2 + 1) << std::left << dmpMeta[ii].desc;
  }

  ss << std::endl << "|";

  unsigned char* stp = reinterpret_cast<unsigned char*>(&st);
  
  size_t ii = 0;
  size_t kk = 0;
  size_t sz = sizeof(stp[kk]);

  while (true) {
    for (size_t jj = 0; jj < dmpMeta[ii].len; jj++, kk++) {
      ss << numToHexStr(stp[kk], sz);
    }
    if (++ii < dmpMeta.size()) {
        ss << " ";
    } else {
      break;
    }
  }

  ss << "|";

  return ss.str();
}

void printAll(std::string s) {
  std::cout << s << std::endl;
  std::cout << " pa: 0x" << numToHexStr(reinterpret_cast<uintptr_t>(st.pa), sizeof(uintptr_t));
  std::cout << "  ii: 0x" << numToHexStr(ii, sizeof(ii)) << std::endl;
  std::cout << "*pa: 0x" << numToHexStr(*st.pa, sizeof(*st.pa));
  std::cout << "     a[ii]: 0x" << numToHexStr(st.a[ii], sizeof(st.a[ii])) << std::endl;
  std::cout << "  x: 0x" << numToHexStr(st.x, sizeof(st.x)) << "   y: 0x" << numToHexStr(st.y, sizeof(st.y)) << std::endl;
  std::cout << " p1: 0x" << numToHexStr(reinterpret_cast<uintptr_t>(st.p1), sizeof(uintptr_t));
  std::cout << "  p2: 0x" << numToHexStr(reinterpret_cast<uintptr_t>(st.p2), sizeof(uintptr_t)) << std::endl;
  std::cout << "*p1: 0x" << numToHexStr(*st.p1, sizeof(*st.p1)) << " *p2: 0x" << numToHexStr(*st.p2, sizeof(*st.p2)) << std::endl;
  std::cout << " rx: 0x" << numToHexStr(st.rx, sizeof(st.rx)) << "  ry: 0x" << numToHexStr(st.ry, sizeof(st.ry)) << std::endl;
  std::cout << memDump();
  std::cout << std::endl;
  std::cout << std::endl;
}

int main()
{
  printAll("Initial");
  
  ii = 1; st.pa = &st.a[2];
  printAll("ii = 1; st.pa = &st.a[2];");
  
  st.a[ii] = 4; *st.pa = 5;
  printAll("st.a[ii] = 4; *st.pa = 5;");
  
  st.a[1] = 1; st.pa = &st.a[0]; *(st.pa + 2) = 2;
  printAll("st.a[1] = 1; st.pa = &st.a[0]; *(st.pa + 2) = 2;");
  
  st.x = 1; st.y = 2;
  printAll("st.x = 1; st.y = 2;");
  
  *st.p2 = *st.p1;
  printAll("*st.p2 = *st.p1;");
  
  st.y = 2;
  printAll("st.y = 2;");
  
  st.p2 = st.p1;
  printAll("st.p2 = st.p1;");
  
  *st.p2 = 3; st.y = 4;
  printAll("*st.p2 = 3; st.y = 4;");
  
  st.p2 = &st.y;
  printAll("st.p2 = &st.y;");
  
  st.ry = st.rx;
  printAll("st.ry = st.rx;");
  
  st.x = 5; st.ry = 6;
  printAll("st.x = 5; st.ry = 6;");
  
  st.p2 = &st.rx;
  printAll("st.p2 = &st.rx;");
  
  *st.p2 = 7; st.ry = 8;
  printAll("*st.p2 = 7; st.ry = 8;");
  
  st.p2 = &st.y; st.rx = 9; *st.p2 = 10;
  printAll("st.p2 = &st.y; st.rx = 9; *st.p2 = 10;");
  
  //st.ry = &st.rx; // Does not compile: Error	C2440	'=': cannot convert from 'int *' to 'int' (Visual Studio)
  //st.rx = st.p2;  // Does not compile: Error	C2440	'=': cannot convert from 'int *' to 'int' (Visual Studio)

  //theDataStructureCodeExampleTest();
  //ArrayAndPointerBasicsCodeExampleTest();
  //ArrayAndPointerBasicsArraysCodeExampleTest01();
  //ArrayAndPointerBasicsPointersCodeExampleTest01a();
  //ArrayAndPointerBasicsArraysCodeExampleTest02();
  //ArrayAndPointerBasicsArraysCodeExampleTest04();
  //ArrayAndPointerBasicsPointersCodeExampleTest01();
  //ArrayAndPointerBasicsPointersCodeExampleTest02();
  //ArrayAndPointerBasicsPointersCodeExampleTest03();
  //ArrayAndPointerBasicsPointersCodeExampleTest04();
  //ArrayAndPointerBasicsPointersCodeExampleTest05();
  //referenceBasicsCodeExampleTest01();
  //referenceBasicsCodeExampleTest02();
  //referenceBasicsCodeExampleTest03();
  //referenceBasicsCodeExampleTest04();
  //theDataStructureAgainCodeExampleTest();
  //deepDiveInitialDiscussionCodeExampleTest();
}