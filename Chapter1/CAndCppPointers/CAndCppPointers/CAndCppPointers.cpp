#include <stdio.h>
#include <iostream>

void CharVarTest() {
  char c;  // Define a variable whose name is c, type is char
  c = 'g'; // assign the character 'g' to variable c

  printf("%c", c); // Output: g
}

void IntVarTest() {
  int i;     // Define a variable whose name is i, type is int
  i = 15339; // assign the integer value 15339 to i

  printf("%d", i); // Output: 15339
}

void DefiningPointersTest() {
  char* pc; // Define a variable named pc of type `pointer to char`
  int* pi;  // Define a variable named pi of type `pointer to int`

  // Output the addresses of the pointer variables pc and pi
  printf("%p %p", &pc, &pi); // output 0C 09
}

void AssigningValuesToPointersTest() {
  char c;   // Define a char variable
  int i;    // Define an int variable

  char* pc; // Defines a variable of type `pointer to char`
  int* pi;  // Defines a variable of type `pointer to int`

  pc = &c;  // Get the address of c and put it in pc
  pi = &i;  // Get the address of i and put it in pi

  // Print out the addresses stored in pc and pi
  printf("%p %p", pc, pi);
  // Output: 02 04
}

void PointersAreJustVariablesInMemoryTooTest() {
  char c;   // Define a char variable
  int i;    // Define an int variable

  char* pc; // Defines a variable of type `pointer to char`
  int* pi;  // Defines a variable of type `pointer to int`

  pc = &c;  // Get the address of c and put it in pc
  pi = &i;  // Get the address of i and put it in pi

  // Print out the addresses stored in pc and pi
  printf("%p %p %p %p", &pc, &pi, pc, pi);
  // Output: 0C 09 02 04
}

void UsingPointersTest() {
  char c = 'g';  // define char variable c and give it the value: g
  char* pc = &c; // define "pointer to char" variable pc
                 // and give it the value: `address of c`

  printf("%c %c", c, *pc); // Output: g g
}

void ChangingPointersTest() {
  char c = 'g';   // Define char variable c assign it value: g
  char d = 'f';   // Define char variable c assign it value: f

  char* pc = &c;  // Define pointer-to-char variable pc
                  // and assign it the value: `address of c`
  char* pd = &d;  // Define pointer-to-char variable pd
                  // and assign it the value `address of d`

  printf("%c %c %p %p %c %c", c, d, pc, pd, *pc, *pd);
  // Output: g f 02 04 g f

  std::cout << std::endl;

  pd = pc; // Assign value in pc to pd

  printf("%p %p %c %c", pc, pd, *pc, *pd);
  // Output: 02 02 g g

  std::cout << std::endl;

  pc = &d; // Assign `address of d` to pc
  printf("%p %p %c %c", pc, pd, *pc, *pd);
  // Output: 04 02 f g
}

void AssigningValuesUsingPointersTest() {
  char c = 'g';  // Define char variable c and assign it the value: g
  char* pc = &c; // Define pointer-to-char variable pc
                 // and assign the value: `address of c`

  printf("%c %c", c, *pc); // print out value stored in c
  // Output: g g

  std::cout << std::endl;

  *pc = 'f'; // Using the dereferenced pointer pc, assign c the value: f

  // Print out the value stored in c directly then with dereferenced pc
  printf("%c %c", c, *pc); // Output: f f
}

void UsingARealMemorySpaceImplementationTest() {
  char c;   // Define a char variable
  int i;    // Define an int variable

  char* pc; // Defines a variable of type `pointer to char`
  int* pi;  // Defines a variable of type `pointer to int`

  pc = &c;  // Get the address of c and put it in pc
  pi = &i;  // Get the address of i and put it in pi

  // Print out the addresses stored in pc and pi
  printf("%p %p %p %p", &pc, &pi, pc, pi);
  // Output: 0C 09 02 04
}

int main()
{
  std::cout << "CharVarTest:" << std::endl;
  CharVarTest();

  std::cout << std::endl << std::endl << "IntVarTest:" << std::endl;
  IntVarTest();

  std::cout << std::endl << std::endl << "DefiningPointersTest:" << std::endl;
  DefiningPointersTest();

  std::cout << std::endl << std::endl << "AssigningValuesToPointersTest:" << std::endl;
  AssigningValuesToPointersTest();

  std::cout << std::endl << std::endl << "PointersAreJustVariablesInMemoryTooTest:" << std::endl;
  PointersAreJustVariablesInMemoryTooTest();

  std::cout << std::endl << std::endl << "UsingPointersTest:" << std::endl;
  UsingPointersTest();

  std::cout << std::endl << std::endl << "ChangingPointersTest:" << std::endl;
  ChangingPointersTest();

  std::cout << std::endl << std::endl << "AssigningValuesUsingPointersTest:" << std::endl;
  AssigningValuesUsingPointersTest();

  std::cout << std::endl << std::endl << "UsingARealMemorySpaceImplementationTest:" << std::endl;
  UsingARealMemorySpaceImplementationTest();

  std::cout << std::endl;
}
