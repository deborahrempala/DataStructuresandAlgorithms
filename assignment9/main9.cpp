/* Deborah Rempala
CSCI 201: Data Structures and Alogorithms
Assignment 9: hash Tables
Due: Friday, April 11, 2014
*/

#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;
// function prototype
unsigned int hash (string );
void linearprobe (int);
int main()
{

string temp;
string temp1;
fstream input;
char letter;
double collison =0;
double wordcount =0;
input.open("speech1.txt");
// inputting file
while((!input.eof()))
{

  getline(input,temp);
wordcount ++;
    for(int i =0; i<=temp.size(); i++)
{
  // change string from lower case to upper case
 


// getting rid of puncatition
  if(ispunct(temp[i])|| temp[i]=='-' || temp[i]=='"')
{
  
 temp.erase(i,1);
 
 }
// taking the spaces out of the total count
if(isspace(temp[i]))
wordcount --;

 temp[i] = (toupper(temp[i]));

cout << temp[i];

// erasing duplicate words



}
}
input.close();
hash(temp);
int tablesize = 563;
int position;
// quadaritic probe
for (int i =1; i<(tablesize-1); i++)
{


    
 
  position =( ((i+1)/2)^2);
  
  if( temp.empty())
    {
      position = temp[i];
     } 
  if (!(temp.empty()))
      {
         continue;
      }
     
}
cout<<endl<<"Number of words in speech: "<<abs(wordcount)<<endl;
cout<<"Number of mean collision: "<<setprecision(3)<<abs(wordcount)/position<<endl;
system("PAUSE");
}
// hashing function
unsigned int hash (string w)
{
unsigned int temp =0, temp2=0;
for( int i=0; i<w.size(); i++)
{
   temp2 = w[i];
   temp = temp <<1;
   temp - temp^temp2;

   }
 return temp;
}




