/* Deborah Rempala
CSCI 201: Data Structures and Algorithms
Assignment 8: heaps
Due: Wednesday, March 26, 2014 */

#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string>

using namespace std;
// class
void heapenqueue(int , string , int &);
void heapDequeue (int &);
class heapItem
{
  private:
  int years;
  string fullName;
  public:
  heapItem();
void  setyears(int);
void setfullName(string);

void display();
};
// constructor functiom
 heapItem::heapItem()
{
   years =0;
   fullName ="none";
}
void heapItem::setyears(int y)
{
   years =y;
}
void heapItem::setfullName (string h)
{
   fullName =h;
}

void heapItem::display()
{
  cout<<"Inserting "<<fullName<<" with "<<years<<" years experience"<<endl;
}
// main program
int main()
{ 
int size;
int year[10]={2,5,4,30,6,5,20,1,6,10};
      heapItem employee[11];
     string name[10]={"Tonks","Harry","Ron","Ginny","Hermonie","Snape","Lupin",
                    "Hagrid","Molly","Dumbledore"};
 for(int i =0; i<=10; i++)
{ srand(time(NULL));
     employee[i].setfullName(name[rand()%10]);
     employee[i].setyears(year[rand ()%10]);
   

     employee[i].display();
size ++;
     Sleep(1500);
//heapenqueue(name,year,size);

}
cout<<"Done Inserting"<<endl;
system("PAUSE");
for (int j=0; j<=5; j++)
 {
heapDequeue(size);
   cout<<"Removing "<<name<<" with "<<year<<"experience from queue"<<endl;
}
system("PAUSE");
return 0;
}
void heapenqueue(int years[], string fullname, int & size)
{ 
  heapItem t2[11];
  heapItem tmp[11];
  int loc = size;
  for(int i =0; i<=11; i++)
  {

  while (size !=0 && years[1] < years[i])
   { 
//       tmp = t2.setyears(years[])
       
   }
}
 }
 void heapDequeue(int &size)
{
   heapItem t3[11];
   t3[11] = t3[size -1];
   size --;
     
 }    
