////////////////////string class///////////////////////////
////////////////////speech.h////////////////////
#include <iostream>
#include <iomanip>

using namespace std;

class text
{
private:
    string tmp;
    int count;
public:
text();
void settmp(string);
void setcount( int);
string gettmp();
int getcount();
};

text::text()
{
    tmp =" ";
    count =0;
}
void text::settmp(string s)
{
  tmp =s;
}
void text::setcount(int c)
{
 count =c;
}
string text::gettmp()
{
   cout<< tmp;
}
int text::getcount()
{
   return count;
}
