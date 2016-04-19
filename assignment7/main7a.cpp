/// main program

#include "tree.h"
#include "speech.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
// operator overload

int main()
{
 
 BST <string> word;
  string tmp =" ";
  int position =0;
  int wordscount =0;
  ifstream input;
  position = tmp[1];
  input.open("mlkspeech.txt");
 do
 {
   
    input>>tmp;
    wordscount ++;
  

int len = tmp.size();

for(int i =0;i<=len; i++)
 {
// deletes puncation 
   if(ispunct(tmp[i]))
   tmp.erase(i--,1);
// deletes extra spaces
  if(isspace(tmp[i]))
   tmp.erase(i--,1);
   len=tmp.size();

// delete duplicate words.
}

 word.insert(tmp);      
}
 while(!(input.eof()));
word.inorder();



 cout<<endl;

 cout<<"Total words in speech: "<<wordscount<<endl;
 system ("PAUSE");
return 0; 
}
