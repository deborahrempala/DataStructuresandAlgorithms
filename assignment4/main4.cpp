/* Deborah Rempala
CSCI 201
Assignment 4: grocery store simulaton
Due: Monday, Feb 24th, 2014 */


#include <iostream>
#include <iomanip>
#include <cmath> 
#include <string>
#include <time.h>
#include <unistd.h>
#include <queue>
#include <vector>
#include "windows.h"
using namespace std;
int poissonRandom1(double expectedValue);
int poissonRandom2(double expectedValue);



// queue class
class CustomerQueue
{
private:
int *queueArray;
int queueSize;
int front;
int rear;
int numItems;
public:
CustomerQueue(int);
CustomerQueue(const CustomerQueue &);
~CustomerQueue();
void enqueue(int);
void dequeue(int &);
bool isEmpty() const;
bool isFull() const;
void clear();
};
 
// functions for custqueue class
// constructor
CustomerQueue::CustomerQueue(int s)
{
queueArray = new int[s];
queueSize = s;
front = -1;
rear = -1;
numItems =0;
}
// copy constructor
CustomerQueue::CustomerQueue(const CustomerQueue &obj)
{
queueArray = new int[obj.queueSize];
queueSize = obj.queueSize;
front = obj.front;
rear = obj.rear;
numItems = obj.numItems;
for(int count =0; count < obj.queueSize; count++)
queueArray[count] = obj.queueArray[count];
}
// Destructor 
CustomerQueue::~CustomerQueue()
{
delete [] queueArray;
}
// inserts value at end of queue
void CustomerQueue:: enqueue(int num)
{
if(isFull())
cout<<"The queue is full. \n";
else
{
rear = (rear + 1) % queueSize;
queueArray[rear] = num;
numItems ++;
}
}
// removes value at the front of the queue
void CustomerQueue::dequeue(int &num)
{
if(isEmpty())
cout<<"The queue is empty. \n";
else
{
front = (front + 1) % queueSize;
num = queueArray[front];
numItems --;
}
}
// is empty function
bool CustomerQueue::isEmpty() const
{
bool status;
if( numItems)
status = false;
else
status = true;
return status;
}
// is full function
bool CustomerQueue::isFull() const
{
bool status;
if( numItems < queueSize)
status = false;
else
status = true;
return status;
}
// clears the front and rear
void CustomerQueue::clear()
{
front = queueSize -1;
rear = queueSize - 1;
numItems =0;
}


  

// mainprogram/////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
// Simulation names
char name[20][15]={"Snape","Harry","Ron","Luna","Hermione",
              "Draco","Ginny","Fred","George","Dumbledore",
              "Mcgonagall","Umbridge","Hagrid","Moody","Lockhart",
              "Sirus","Neville","Cedric","Viktor","Tonks"};
// variables for figuring out values
int sum=0;
int meantime=0;
int sumtime =0;
// making sure the correct number of arguments are read in 
if(argc !=6)
cout<<"Invalid number of arguments.";
// variables to read in command line 
int runtime         = atoi(argv[1]);
double expectedArrival = atof(argv[2]);
float serviceTime     = atof(argv[3]);
int queues            = atoi(argv[4]);
int verbosemode       = atoi(argv[5]);
queue <CustomerQueue> line;

// checking to make sure input is correct
if(runtime <= 1 && runtime <=61)
cout<<"Invalid Runtime"<<endl;
 if(expectedArrival <= 0)
cout<<"Invalid expected Arrival"<<endl;
if(serviceTime <= 1 && serviceTime <= 60)
cout<<"Invalid Service Time"<<endl;
 if(queues <= 1)
cout<<"Invalid number of Queues"<<endl;
 if(verbosemode !=1 && verbosemode !=0)
cout<<"Invalid verbose mode selection"<<endl;
else 
cout<<"Quality Quidditch Supplies Simulation"<<endl;
int numService =0;
int numArrival =0;
int maxTime = 0;
srand(time(NULL));
/////////////////////verbose mode on///////////////////////////////////////////
if(verbosemode ==1)
{
// simulation
for(int i =1; i<=runtime; i++)
{
 Sleep(1000);
cout<<"minute "<<i<<":"<<endl;
// figure out how many people are arriving 
numArrival = poissonRandom1(expectedArrival);
 // for loop for num arrivals
for(int j=0;j<=numArrival; j++)
{
// figure out service time
numService=poissonRandom2(serviceTime);
// gets name and service time 
cout<<name[rand()%20]<<" arrives with "<<numService<<"-minute service time"<<endl;
cout<<"has entered queue"<<endl;
// puts it into queue
line.push(numService);
// adds to number of arrivals 
sum++;
sumtime= numService + sumtime;
}
// exiting the queue
if(numService = runtime)
{
cout<<"has exited queue"<<endl;
line.pop();
}

}
}
////////////////////////////verbose mode off///////////////////////////////////
else if(verbosemode ==0)
{
for(int i =1; i<=runtime; i++)
{
 Sleep(1000);
// figure out numArrivals
numArrival = poissonRandom1(expectedArrival);

for(int j=0;j<=numArrival; j++)
{

name[rand()%20];
// figure out service time
numService = poissonRandom2(serviceTime);
sum++;
sumtime= numService + sumtime;
}

}
}
// figure out the mean time 
meantime = sumtime/sum;
cout<<"DONE!"<<endl;
// print out info
cout<<"Number of arrivals: "<<sum<<endl;
cout<<"Mean Wait Time:"<<meantime<<" minutes"<<endl;
cout<<"Max Wait Time: "<<maxTime<<" minutes"<<endl;
system("PAUSE");

}
////////////////////////////////////// functions///////////////////////////////
int poissonRandom1(double expectedValue) {
  int n = 1; //counter of iteration
  double limit; 
  double x;  //pseudo random number
  limit = exp(-expectedValue);
  x = (1.0*rand()) / RAND_MAX; 
  while (x > limit) {
    n++;
    x *= (1.0*rand()) / RAND_MAX;
  }
  return n;
}
int poissonRandom2(double expectedValue) {
  int n = 1; //counter of iteration
  double limit; 
  double x;  //pseudo random number
  limit = exp(-expectedValue);
  x = (1.0*rand()) / RAND_MAX; 
  while (x > limit) {
    n++;
    x *= (1.0*rand()) / RAND_MAX;
  }
  return n;
}
