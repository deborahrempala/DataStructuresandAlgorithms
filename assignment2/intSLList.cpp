// Move to front 
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
//header
// class to create a new node 
class IntSLLNode {
      public:
             IntSLLNode() {
                          next = NULL;
                          }
             IntSLLNode (string el, IntSLLNode *ptr = NULL) {
                               info = el; next =ptr;
                               }
string info;
IntSLLNode *next;
                };
// class to create the linked list 
class IntSLList {
      public :
             IntSLList() {
                         head=tail=NULL;
                         }
             ~IntSLList();
           int isEmpty() {
                    return head ==0;
                               } 
void addToTail(string &);  
void addToHead(string &);
bool isInList(string) const;
void printAll() const;
string deleteFromTail();
private:
        IntSLLNode *head, *tail;
};

                         
             

// functions
// deletes list 
IntSLList :: ~IntSLList() {
          for(IntSLLNode *p; !isEmpty(); ) {
                         p = head->next;
                         delete head;
                         head =p;
                         }
                         }
 // functions to add a new node to the tail                        
void IntSLList::addToTail(string & el ) {
    
           if(tail != NULL)
           {
           tail->next = new IntSLLNode(el);
           tail = tail-> next;
           
           }
           else head = tail = new IntSLLNode(el);
         
}
// function to prnt the entire list 
void IntSLList::printAll() const  {
     for(IntSLLNode *tmp = head; tmp !=NULL; tmp = tmp->next)
     cout<<tmp->info<<"->";
     cout<<endl;
    }
    // making sure a word is in the list
    // if not it will return false 
bool IntSLList::isInList(string el) const{
     for(IntSLLNode *tmp = head; tmp!=NULL; tmp=tmp->next)
     return tmp !=NULL;
     }
     // delete a node from the tail
     // used for duplicate words 
string IntSLList::deleteFromTail(){
              string el =tail->info;
              if(head = tail)
              {
                      delete head;
                      head = tail= NULL;
                      }
                      else {
                           IntSLLNode *tmp;
                           for(tmp = head; tmp->next !=tail; tmp=tmp->next);
                           delete tail;
                           tail = tmp;
                           tail->next =0;
                           }
                     return el;
                     }    

void IntSLList::addToHead (string & el)
{
     head = new IntSLLNode (el,head);
     if(tail==0)
     tail = head;
}
// main program *******************************************************
int main()
{
      IntSLList list;
   // variables 
int totalwords=0;
int actualwords =0;
int comparison =0;  
     string tmp;

    

fstream input;
// input a file
input.open("speech.txt",ios::in);

   do{
                   // using a temporary to read in the text
                  input>>tmp;
                  // maknig sure all the words are in the tmp variable 
                  totalwords++;
            
               
               // adding the temp variable to the linked list 
                    list.addToHead(tmp);
                    // counting the number of words that end up in the lnked list
                    // should be the same amount as the words then are in the tmp
                   actualwords++;
                   
         
              
               
     }while(!(input.eof()));

input.close();

// checking to make sure the fille was read
cout<<"done reading"<<endl;

//comparison
// using a for loop to go through all the words   
string tmpword;               
for(int i =1; i< totalwords; i++)
{
       // using a for loop to find the words 
        for(int j =1; j<totalwords; j++)
        {
           tmpword = tmpword[j];
        // adding one the the conmparison total 
         if(list.isInList(tmpword)==true)
         {
             comparison++;
             }
             } 
}

// print out the entire speech
 list.printAll();



      double average;
      // finding the average of the comparison
       average= comparison/totalwords;
      /////////////////////////Ending info///////////////
 cout<<"total words: "<<totalwords<<endl;
cout<<"Total Comparisons:"<<comparison<<endl;
 cout<<"average Comparison:"<<average<<endl;           
    system ("PAUSE");
    return 0;
}
