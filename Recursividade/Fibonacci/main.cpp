#include <iostream>
using namespace std;

int fibonacci(int x){
  if(x == 0 || x == 1){
    return 1;
  }
  else{
    return fibonacci(x - 1) + fibonacci(x - 2);
  }
}

int main(){

  for(int i = 0; i <= 10; i++){
    cout << fibonacci(i) << "\t";
  }

  return 0;
}
