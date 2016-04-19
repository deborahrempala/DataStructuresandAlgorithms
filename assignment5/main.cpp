/* Deborah Rempala
CSCI 201
Assignment 5: book exercise
Due: friday, Feb 28, 2014
*/ 

#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;
bool palindromes(string);
int fractions (int);


int main()
{
int choice;
string sentence;
cout<<"1. Fractions"<<endl;
cout<<"2. Palindromes"<<endl;
cout << "Choice: ";
cin>> choice;
if( choice ==2)
{
  cout<<"Enter a sentence: ";
  cin >> sentence;
palindromes(sentence);
}
 if(choice ==1)
{
   cout<<"Enter a number greater than 0: ";
   int num;
    cin >> num;
    cout<<num;
    fractions(num);
   cout<<endl;
   
}
else
{
  cout<<"USER ERROR"<<endl;
 cout<<"This program will now terminate"<<endl;
system("PAUSE");
  return 0;
}

system("PAUSE");
return 0;
}
// function for palindromes
bool palindromes(string sentence)
{ string letter;
  int n = sentence.length();
  if (n<=1)
  return true;
for(int i=0; i<=sentence.length(); i++)
{
  if(ispunct(i))
    sentence.erase(i);
  if(isspace(i))
  sentence.erase(i);
}
  if(sentence[0] !=sentence[n-1])
{cout<<"This is not a palindrome"<<endl;
  return false;
}

  cout<<"This a palindrome"<<endl;

 return palindromes(letter);
 
  }    
// functions for fractions  
int fractions (int num)
{
  if(num <= 1)
  return num;

else
{

  cout<<"+"<<"(1/"<<num<<")";

}
return fractions(num -1);

}
