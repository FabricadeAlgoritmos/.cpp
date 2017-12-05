#include <iostream>
using namespace std;

int fatorial(int x){
  if(x == 0 || x == 1){
    return 1;
  }
  else{
    return x * fatorial(x - 1);
  }
}

int main(){

  for(int i = 0; i <= 5; i++){
    cout << i << "! = " << fatorial(i) << endl;
  }

  return 0;
}
