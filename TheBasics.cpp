// my first string
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;
bool containsOnlyLetters(string const &str){
    bool output = true;
    for (auto i = 0; i < str.size(); i++)
    {
      char c = str[i];
      int test23 = isalpha(c);
      if ((test23 == 0) && c != ' '){
        output = false;
      } 
    };
    return output;
}
map <int,int> price_map = {
  {1,25},
  {2,300},
  {3,14},
  {4,32},
  {5,120000}
};
//dont want to keep typing the prices over and over again

//dynamic array implementation that i blatantly copied from some stackoverflow answer
typedef struct{
  int *array;
  size_t used;
  size_t size;
}Array;
//creates a struct with the name "Array" and the members , integer array , used and size

void initArray(Array *a , size_t initialSize){
  (*a).array = (int*)(malloc(initialSize * sizeof(int)));
  //got so tired of debugging this section i straight up filled the memory with 5s so i can spot what variable changes
  /*for (int i = 0; i < initialSize; i++)
  {
    (*a).array[i] = 5;
  }*/
  //intializes an array with a initial size and casts the void pointer into the int pointer
  if ((*a).array == NULL || (*a).array == 0 || (*a).array == nullptr){
    cout << "Allocating memory has failed.. Program exiting."<<endl;
    exit(EXIT_FAILURE);
    //if allocating memory fails, exit
}
  (*a).used = 0;
  (*a).size = initialSize;
}

void insertArray(Array *a, int element){
  if((*a).used == (*a).size){
    //doubles size and reallocs if too full
    (*a).size = (*a).size * 2;
    (*a).array = (int*)realloc((*a).array , (*a).size * sizeof(int));
    if ((*a).array == NULL || (*a).array == 0 || (*a).array == nullptr){
      cout << "Allocating memory has failed.. Program exiting."<<endl;
      exit(EXIT_FAILURE);
    }
  }
  
  (*a).array[(*a).used] = element;
  (*a).used += 1;
  
}

void freeArray(Array *a) {
  free((*a).array);
  (*a).array = NULL;
  a->used = a->size = 0;
}

int main ()
{
  string Name;
  string Order;
  Array Cart;
  int OrderInt;
  int Temporary;
  initArray(&Cart,10);
  cout << "Enter Name:";
  getline(cin,Name);
  if (Name == "" || !(containsOnlyLetters(Name))) {
    cout << "Couldnt understand ur name. Just gonna call you Anon. Pick whatever you want from the list below" << endl;
    Name = "Anon";
  }else{
    cout << "Hi "<<Name<<"! Pick whatever you want from the list below" <<endl;
  }

  while(true){
    if (Cart.used > 1){
    cout << "Total Items:" << Cart.used<<endl;
    cout << "Total Cost:";
    Temporary = 0;
    for (int i = 0; i < Cart.used; i++)
    {
      Temporary += price_map[Cart.array[i]];
    }
    cout << Temporary << endl;
    }
    cout << "1 - Item A - 25$\n2 - Item B - 300$\n3 - Item C - 14$\n4 - Item D - 32$\n5 - How much im paying for glorified youtube videos - 120000$" <<endl;
    cout<< "Your Order(1-5 or Checkout):";
    getline(cin,Order);
    stringstream(Order)>>OrderInt;
    transform(Order.begin(), Order.end(), Order.begin(), ::tolower);
   
    if (Order == "checkout"){
      /*
      for (int i = 0; i < Cart.used; i++)
      {
       cout << Cart.array[i] << endl;
       cout << *(Cart.array+i) << endl;
       //functionally the same
      }
      cout << Cart.array <<endl;
      //more stuff used for debugging
      */
      cout << "So that will be "<<Temporary<<"$ for "<< Cart.used <<" items." << endl;
      cout << "Thanks for shopping at idk, please come again!\n";
      exit(EXIT_SUCCESS);
    }else{
      if(OrderInt == 1){
          cout << "Item 1 picked. You can continue shopping or check out now"<<endl;
          insertArray(&Cart,OrderInt);
      }else if(OrderInt == 2){
          cout << "Item 2 picked. You can continue shopping or check out now"<<endl;
          insertArray(&Cart,OrderInt);
      }else if(OrderInt == 3){
          cout << "Item 3 picked. You can continue shopping or check out now"<<endl;
          insertArray(&Cart,OrderInt);
      }else if(OrderInt == 4){
          cout << "Item 4 picked, You can continue shopping or check out now"<<endl;
          insertArray(&Cart,OrderInt);
      }else if(OrderInt == 5){
          cout << "Item 5 picked. You can continue shopping or check out now"<<endl;
          insertArray(&Cart,OrderInt);
      }else{
          cout <<"Sorry but that isnt a valid option!" <<endl;
      }
    }
  }
}