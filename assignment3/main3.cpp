/*Deborah Rempala
CSCI 201: data structure and alogrthims
Assignment#3: maze game
Due: Feburary 10,2014*/

#include <iostream>
#include <cstring>
#include <stack>
#include <time.h>
#include <fstream>

using namespace std;
// template class
template<class T>
class Stack : public stack<T> {
public:
    T pop() {
        T tmp = stack<T>::top();
        stack<T>::pop();
        return tmp;
    }

};
// cell class 
class Cell {
public:
    Cell(int i = 0, int j = 0) {
        x = i; y = j;
    }
    bool operator== (const Cell& c) const {
        return x == c.x && y == c.y;
    }
private:
    int x, y;
    friend class Maze;
};
// maze class 
class Maze {
public:
    Maze();
    void exitMaze();

private:
    Cell currentCell, exitCell, entryCell;
    const char exitMarker, entryMarker, visited, passage, wall;
    Stack<Cell> mazeStack;
    char **store;         // array of strings;
    void pushUnvisited(int,int);
    int rows, cols;
    friend ostream& operator<< (ostream& out, const Maze& maze) {
        for (int row = 0; row <= maze.rows+1; row++)
            out << maze.store[row] << endl;
        out << endl;
        return out;
    }

};
// functions
Maze::Maze() : exitMarker('e'), entryMarker('m'), visited('.'),
               passage('0'), wall('1') {
     
    Stack<char*> mazeRows;
    char str[80], *s;
    int col, row = 0;
    string filename;
 ifstream input;
// user enters name of desired file 
cout<<"enter a filename: ";
 cin>>filename;
// file is opened 
 input.open(filename.c_str() );
 do{
// puts the file into a maze 
    while (input >> str) {
        row++;
        cols = strlen(str);
        s = new char[cols+3];    // two more cells for borderline columns;
        mazeRows.push(s);
        strcpy(s+1,str);
        s[0] = s[cols+1] = wall; // fill the borderline cells with 1s;
        s[cols+2] = '\0';
        if (strchr(s,exitMarker) != 0) {
             exitCell.x = row;
             exitCell.y = strchr(s,exitMarker) - s;
        }
        if (strchr(s,entryMarker) != 0) {
             entryCell.x = row;
             entryCell.y = strchr(s,entryMarker) - s;
        }
    }
    rows = row;
    store = new char*[rows+2];        // create a 1D array of pointers;
    store[0] = new char[cols+3];      // a borderline row;
    for ( ; !mazeRows.empty(); row--) {
        store[row] = mazeRows.pop();
    }
    store[rows+1] = new char[cols+3]; // another borderline row;
    store[0][cols+2] = store[rows+1][cols+2] = '\0';
    for (col = 0; col <= cols+1; col++) {
        store[0][col] = wall;         // fill the borderline rows with 1s;
        store[rows+1][col] = wall;
    }
}
while(!(input.eof()));
// closes the file 
input.close();
}


void Maze::pushUnvisited(int row, int col) {
    if (store[row][col] == passage || store[row][col] == exitMarker) {
        mazeStack.push(Cell(row,col));
    }
}
void Maze::exitMaze() {
    int row, col;
    currentCell = entryCell;
    while (!(currentCell == exitCell)) {
        row = currentCell.x;
        col = currentCell.y;
        cout << *this;
         // print a snapshot;
// time delay 
time_t start_time, cur_time;

         time(&start_time);
         do
         {
                 time(&cur_time);
         }
         while((cur_time - start_time) < 1);
// clearing the screen 
      system("CLS");
  
         
        if (!(currentCell == entryCell))
            store[row][col] = visited;
        pushUnvisited(row-1,col);
        pushUnvisited(row+1,col);
        pushUnvisited(row,col-1);
        pushUnvisited(row,col+1);
        if (mazeStack.empty()) {
             cout << *this;
             cout << "Failure\n";
             return;
        }
        else currentCell = mazeStack.pop();
    }
    cout << *this;
    cout << "Success\n";
}
/////////////main program//////////////////
int main() {
    Maze().exitMaze();
 
    system("PAUSE");

    return 0;
}
