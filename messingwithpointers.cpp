// more pointers
#include <iostream>
using namespace std;

int main ()
{
  int numbers[5];
  //defines array with 5 spaces
  int * p;
  //defines a pointer with the ability to reference integers
  p = numbers;  
  //obtain pointer of numbers
  *p = 10;
  //set the first position to value 10
  p++;  
  //increase pointer offset to the next position
  *p = 20;
  //set the second position to value 20
  p = &numbers[2];  
  //obtain pointer of the 3rd position in numbers
  *p = 30;
  //set it to 30

  p = numbers + 3;
  //obtain pointer of numbers and add an offset of 3  (aka 4th position)
  *p = 40;
  p = numbers;  
  *(p+4) = 50;
  
  //references memory out of bounds of system allocated space and then crashes cause the os denies operation (just wanted to see what will happen lol)
  //for (int n=1; n<20; n++){*(p+4+n) = 50+n*10;}

  for (int n=0; n<5; n++)
    cout << numbers[n] << ", ";
  cout << p;
  return 0;
}
