#include <stdio.h>
#include <iostream>

void CharVarTest() {
  char c;  // Define a variable whose name is c, type is char
  c = 'a'; // assign the character 'a' to variable c

  printf("%c", c); // Output: a
}

void IntVarTest() {
  int i;     // Define a variable whose name is i, type is int
  i = 15339; // assign the integer value 15339 to i

  printf("%d", i); // Output: 15339
}

void DefiningPointersTest() {
  char* pc; // Define a variable named pc of type `pointer to char`
  int* pi;  // Define a variable named pi of type `pointer to int`
}

void AssigningValuesToPointersTest() {
  char c;   // Define a char variable
  int i;    // Define an int variable

  char* pc; // Define a variable of type `pointer to char`
  int* pi;  // Define a variable of type `pointer to int`

  pc = &c;  // Get the address of c and put it in pc
  pi = &i;  // Get the address of i and put it in pi

  // Print out the addresses stored in pc and pi
  printf("%p %p", pc, pi);
  // Output: 02 04
}

void PointersAreJustVariablesInMemoryTooTest() {
  char c;   // Define a char variable
  int i;    // Define an int variable

  char* pc; // Define a variable of type `pointer to char`
  int* pi;  // Define a variable of type `pointer to int`

  pc = &c;  // Get the address of c and put it in pc
  pi = &i;  // Get the address of i and put it in pi

  // Print out the address of pi and pc and the addresses stored in them
  printf("%p %p %p %p", &pc, &pi, pc, pi);
  // Output: 0C 09 02 04
}

void UsingPointersTest() {
  char c = 'a';  // define char variable c and give it the value: a
  char* pc = &c; // define "pointer to char" variable pc
                 // and give it the value: `address of c`

  printf("%c %c", c, *pc); // Output: a a
}

void ChangingPointersTest() {
  char c = 'a';   // Define char variable c and assign it value: a
  char d = 'f';   // Define char variable c and assign it value: f

  char* pc = &c;  // Define pointer-to-char variable pc
                  // and assign it the value: `address of c`
  char* pd = &d;  // Define pointer-to-char variable pd
                  // and assign it the value `address of d`

  printf("%c %c %p %p %c %c", c, d, pc, pd, *pc, *pd);
  // Output: a f 02 04 a f

  std::cout << std::endl;

  pd = pc; // Assign value in pc to pd

  printf("%c %c %p %p %c %c", c, d, pc, pd, *pc, *pd);
  // Output: a f 02 02 a a

  std::cout << std::endl;

  pc = &d; // Assign `address of d` to pc
  printf("%c %c %p %p %c %c", c, d, pc, pd, *pc, *pd);
  // Output: a f 04 02 f a
}

void AssigningValuesUsingPointersTest() {
  char c = 'a';  // Define char variable c and assign it the value: a
  char* pc = &c; // Define pointer-to-char variable pc
                 // and assign it the value: `address of c`

  // print out value stored in c directly then with dereferenced pc
  printf("%c %c", c, *pc);
  // Output: a a

  std::cout << std::endl;

  *pc = 'f'; // Using the dereferenced pointer pc, assign c the value: f

  // Print out the value stored in c directly then with dereferenced pc
  printf("%c %c", c, *pc);
  // Output: f f
}

void UsingARealMemorySpaceImplementationTest() {
  char c = 'a';  // Define a char variable and assign value: 'a'
  int i = 15336; // Define an int variable and assign value: 15336

  char* pc; // Define a variable of type `pointer to char`
  int* pi;  // Define a variable of type `pointer to int`

  pc = &c;  // Get the address of c and put it in pc
  pi = &i;  // Get the address of i and put it in pi

  // Print out the address of pi and pc and the addresses stored in them
  printf("%p %p %p %p", &pc, &pi, pc, pi);
  // Output: 00CFFB84 00CFFB78 00CFFB9F 00CFFB90
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
