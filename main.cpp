/*****************************************************

Ahmad Habibollahzadeh
CISP 430 - MoWe 5:30 pm
Programming Project 22(hash)
May 14, 2019

*****************************************************/
#include<bits/stdc++.h>
#include<iostream>
using namespace std; 

ifstream in("input.txt");


void hashFunc(int a, int (&z)[10] );
int hashB(int a, int (&z)[10] );

int main(){
  int z[10] ={0};
  int a,res, b;
  while (in.good()){
    in>>a;
    res = a%10;
    if(z[res]== 0){
      z[res] = a;
    }
    else{
      hashFunc(a,z);
    }
  }
  cout << "The array : "; 
  for(int i = 0; i <10 ; ++i){
    cout << z[i] << " ";
  }
  cout << endl;
  cout << "Enter the number : ";
  cin >> b;
  cout << "The item is on : " << hashB(b,z) << endl;
    
}



void hashFunc(int a, int (&z)[10] ){
  int H1,H2,H3,H4,Co = 1;
  H1 = a%10;
  H2 = 7 - (a%7);
  if(z[H1]== 0){
    z[H1] = a;
  }
  else{
    if(z[H1+H2]== 0){
      z[H1+H2] = a;
    }
    else{
      ++Co;
      for (int i = 1; i < 4;++i){
        H3 = (a + i )%10;
        if(z[H3]== 0){
          z[H3]= a;
          break;
        }
        ++Co;
      }
      if (z[H3] != a){
        for (int i = 0; i < 10;++i){
          H4 = H3 + i;
          if(z[H4]== 0){
            z[H4]= a;
            break;
          }
          ++Co;
        }
      }
    }
  }
  cout << a << " : " << Co << " collisions" << endl;
}



int hashB(int a, int (&z)[10] ){
  int H1,H2,H3,H4,Co = 1;
  H1 = a%10;
  H2 = 7 - (a%7);//5
  if(z[H1]== a){
    return H1; 
  }
  else{
    if(z[H1+H2]== a){
      return H1+H2;
    }
    else{
      ++Co;
      for (int i = 1; i < 4;++i){
        H3 = (a + i )%10;
        if(z[H3]== a){
          return H3;
        }
        ++Co;
      }
      if (z[H3] != a){
        for (int i = 0; i < 10;++i){
          H4 = H3 + i;
          if(z[H4]== a){
            return H4;
          }
          ++Co;
        }
      }
    }
  }
  cout << "It is not on the list! "<< endl;
  return -1;
}