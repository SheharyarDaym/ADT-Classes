#include<iostream>
using namespace std;
class Node{
friend class SLL;
private:
    int data;
    Node* link;
public:
    Node() : data(0), link(NULL) {}
    Node(int x) : data(x), link(NULL) {}
    void display();
};

class SLL{
private:
    Node* start;
    Node* end;
public:
// Constructor
    SLL() : start(NULL), end(NULL) {}
// Insert
    void insert_Append(int x);
    void insert_At_First(int x);
    void insert_Before(int x, int y);
    void insert_After(int x, int y);
// Delete
    void delete_First();
    void delete_Kth(int x, int occurence);
    void delete_All();
// Display
    void display();
// Destructor
    ~SLL(){
        if(start != NULL){
            Node* temp = start;
            while(start != NULL){
                start = start->link;
                temp = start;
                delete temp;
            }
        }
    }
};
