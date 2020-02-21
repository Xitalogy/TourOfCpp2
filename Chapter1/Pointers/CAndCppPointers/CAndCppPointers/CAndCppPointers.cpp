#include <stdio.h>
#include <iostream>

void CharVarTest() {
  char c;  // Define a variable whose name is c, type is char
  c = 'g'; // assign the character 'g' to variable c
           // placing a 'g' in c's memory "storage area"

  printf("%c\n", c); // Print out value of c
}

void IntVarTest() {
  int i;     // Define a variable whose name is i, type is int
  i = 15339; // assign the integer value 15339 to i

  printf("%d\n", i); // Print out value of i
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

  printf("%p %p", pc, pi);
}

void UsingPointersTest() {
  char c = 'g';  // define char variable c and give it a value: 'g'
  char* pc = &c; // define pointer to char variable pc and give it the value: address of c

  printf("%c %p %c", c, pc, *pc); // prints out: g BA5EBA11 g
}

void ChangingPointersTest() {
  char c = 'g';
  char d = 'f';

  char *pc = &c;
  char *pd = &d;

  printf("%c %c %p %p %c %d", c, d, pc, pd, *pc, *pd); // prints out: g f BA5BA11 BA5BA12 g f

  pd = pc;
  printf("%p %p %c %c", pc, pd, *pc, *pd); // prints out: BA5BA11 BA5BA11 g g

  pc = &d;
  printf("%p %p %c %c", pc, pd, *pc, *pd); // prints out: BA5BA12 BA5BA11 f g
}

void AssigningValuesUsingPointersTest() {
  char c = 'g';
  char *pc = &c;

  printf("%p %c", pc, c); // prints out: BA5EBA11 g

  *pc = 'f';
  printf("%p %c", pc, c); // prints out: BA5EBA11 f
}

int main()
{
  CharVarTest();
  IntVarTest();
  DefiningPointersTest();
  AssigningValuesToPointersTest();
  UsingPointersTest();
  ChangingPointersTest();
  AssigningValuesUsingPointersTest();
}
