#include <stdio.h>
#include <iostream>

void CharVarTest() {
  char c;  // Define a variable whose name is c, type is char
  c = 'g'; // assign the character 'g' to variable c
           // placing a 'g' in c's memory "storage area"

  printf("%c", c); // Print out: g
}

void IntVarTest() {
  int i;     // Define a variable whose name is i, type is int
  i = 15339; // assign the integer value 15339 to i

  printf("%d", i); // Print out: 15339
}

void DefiningPointersTest() {
  char *pc; // Defines a variable of type "pointer to char"
  int *pi;  // Defines a variable of type "pointer to int"
}

void AssigningValuesToPointersTest() {
  char c;   // Define a char variable
  int i;    // Define an integer variable

  char *pc; // Defines a variable of type "pointer to char"
  int *pi;  // Defines a variable of type "pointer to int"

  pc = &c;  // Get the address of the char variable c and put it in pc
  pi = &i;  // Get the address of the int variable i and put it in pi

  printf("%p %p", pc, pi); // Print out: 00EFFB0B 00EFFAFC
}

void UsingPointersTest() {
  char c = 'g';  // define char variable c and give it a value: 'g'
  char* pc = &c; // define pointer to char variable pc and give it the value: address of c

  printf("%c %p %c", c, pc, *pc); // prints out: g 00EFFB0B g
}

void ChangingPointersTest() {
  char c = 'g';   // Define char variable c and assign 'g' to it
  char d = 'f';   // Define char variable c and assign 'f' to it

  char *pc = &c;  // Define pointer-to-char variable pc and assign address of c to it
  char *pd = &d;  // Define pointer-to-char variable pd and assign address of d to it

  printf("%c %c %p %p %c %c", c, d, pc, pd, *pc, *pd); // prints out: g f 00EFFB0B 00EFFAFF g f

  pd = pc; // Assign value of pc (address of char variable c) to pd
  printf("%p %p %c %c", pc, pd, *pc, *pd); // prints out: 00EFFB0B 00EFFB0B g g

  pc = &d; // Assign directly address of char variable d to pc
  printf("%p %p %c %c", pc, pd, *pc, *pd); // prints out: 00EFFAFF 00EFFB0B f g
}

void AssigningValuesUsingPointersTest() {
  char c = 'g';  // Define char variable c and assign g to it
  char *pc = &c; // Define pointer-to-char variable pc and assign address of c to it

  printf("%p %c", pc, c); // prints out: 00EFFB0B g

  *pc = 'f'; // Assign 'f' to variable c using dereferenced pointer-to-char variable pc
             // Does not change value of variable pc, rather changes value of variable c to which it points
  printf("%p %c", pc, c); // prints out: 00EFFB0B f
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
