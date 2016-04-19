/* Deborah Rempala
CSCI 201: Data and algothrims
Assignemt 2: I have a dream speech
Due: Wednesday, Januaray 29th, 2014*/
#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST
class IntSLLNode{

public:
    IntSLLNode(){
    next =0;}
    IntSLLNode(int el, IntSLLNode * ptr =0){
    info = el; next = ptr;
    }
    int info;
    IntSLLNode *next;
    };
class IntSLList{
public:
    IntSLList() {
    head = tail = 0;
    }
    ~IntSLList();
    int isEmpty() {
    return head ==0;
    }
    void addtotail(string);
    bool isinlist(string) const;
    void printAll() const;
private:
    IntSLLNode *head, *tail;
};

#endif // INT_LINKED_LIST
