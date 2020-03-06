#include <stdio.h>
#include <iostream>

void CharVarTest() {
  char c;  // Define a variable whose name is c, type is char
  c = 'g'; // assign the character 'g' to variable c
           // placing the value 'g' in c's memory "storage area"

  printf("%c", c); // Output: g
}

void IntVarTest() {
  int i;     // Define a variable whose name is i, type is int
  i = 15339; // assign the integer value 15339 to i

  printf("%d", i); // Output: 15339
}

void DefiningPointersTest() {
  char* pc; // Defines a variable named pc of type "pointer to char"
  int* pi;  // Defines a variable named pi of type "pointer to int"
}

void AssigningValuesToPointersTest() {
  char c;   // Define a char variable
  int i;    // Define an integer variable

  char* pc; // Defines a variable of type "pointer to char"
  int* pi;  // Defines a variable of type "pointer to int"

  pc = &c;  // Get the address of the char variable c and put it in pc
  pi = &i;  // Get the address of the int variable i and put it in pi

  printf("%p %p", pc, pi); // Output: 02 04
}

void PointerAddressesTest() {
  char c;    // Define a char variable
  int i;     // Define an int variable

  char* pc; // Define a variable of type "pointer to char"
  int* pi;  // Define a variable of type "pointer to int"

  pc = &c;  // Get the address of c and put it in pc
  pi = &i;  // Get the address of i and put it in pi
  
  printf("%p %p %p %p", &pc, &pi, pc, pi);
  // Output: 0C 09 02 04
}

void UsingPointersTest() {
  char c = 'g';  // define char variable c
                 // Give it the value: g
  char* pc = &c; // define pointer to char variable pc
                 // Give it the value: address of c

  printf("%c %p %p %c", c, &pc, pc, *pc);
  // Output: g 006FFBC0 006FFBCF g
}

void ChangingPointersTest() {
  char c = 'g';   // Define char variable c
                  // Assign 'g' to it
  char d = 'f';   // Define char variable c
                  // Assign 'f' to it

  char* pc = &c;  // Define pointer-to-char variable pc
                  // Assign address of c to it
  char* pd = &d;  // Define pointer-to-char variable pd
                  // Assign address of d to it

  printf("%c %c %p %p %p %p %c %c", c, d, &pc, &pd, pc, pd, *pc, *pd);
  // Output: g f 006FFBB4 006FFBA8 006FFBCF 006FFBC3 g f

  pd = pc; // Assign value in pc to pd

  printf("%p %p %c %c", pc, pd, *pc, *pd);
  // Output: 006FFBCF 006FFBCF g g

  pc = &d; // Assign address of char variable d to pc
  printf("%p %p %c %c", pc, pd, *pc, *pd);
  // Output: 006FFBC3 006FFBCF f g
}

void AssigningValuesUsingPointersTest() {
  char c = 'g';  // Define char variable c and assign 'g' to it
  char* pc = &c; // Define pointer-to-char variable pc
                 // Assign address of c to it

  printf("%c", c);
  // Output: g

  *pc = 'f'; // Assign 'f' to variable c using dereferenced pointer pc

  printf("%c", c);
  // Output: f
}

int main()
{
  std::cout << "CharVarTest():" << std::endl;
  CharVarTest();
  std::cout << std::endl << std::endl << "IntVarTest:" << std::endl;
  IntVarTest();
  std::cout << std::endl << std::endl << "DefiningPointersTest():" << std::endl;
  DefiningPointersTest();
  std::cout << std::endl << std::endl << "AssigningValuesToPointersTest:" << std::endl;
  AssigningValuesToPointersTest();
  std::cout << std::endl << std::endl << "UsingPointersTest():" << std::endl;
  UsingPointersTest();
  std::cout << std::endl << std::endl << "ChangingPointersTest():" << std::endl;
  ChangingPointersTest();
  std::cout << std::endl << std::endl << "AssigningValuesUsingPointersTest():" << std::endl;
  AssigningValuesUsingPointersTest();
  std::cout << std::endl;
}
