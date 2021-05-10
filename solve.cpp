#include <iostream>

using namespace std;


bool isPrime(int n){

  if(n == 1 ){
    cout << "is not prime"<<endl;

  }



  for(int i=1; i<=n/2;i++){

    if(n%i==0){
      return false;
    }else{
      return true;
    }
  }


}

int main() {
  int num=0;

  cin>>num;

  if(isPrime(num)){cout<<"is Prime"<<endl;}
  else{cout<<"is not Prime"<<endl;}


}
