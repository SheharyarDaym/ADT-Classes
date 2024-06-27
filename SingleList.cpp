#pragma
#include"SingleList.hh"

void Node::display(){
    cout << data << " ";
}

void SLL::insert_Append(int x)
{
    if(start == NULL){
        start = new Node(x);
        end = start;
    }
    else{
        end->link = new Node(x);
        end = end->link;
    }
}

void SLL::insert_At_First(int x)
{
    if(start == NULL){
        start = new Node(x);
        end = start;
    }
    else{
        Node* temp = new Node(x);
        temp->link = start;
        start = temp;
    }
}

void SLL::insert_Before(int x, int y)
{
    if(start == NULL) return;
    if(start->data == x){
        Node* temp = new Node(y);
        temp->link = start;
        start = temp;
    }
    else{
        Node* temp = start;
        Node* prev = start;
        while(temp->link!=NULL && temp->data != x){
            prev = temp;
            temp = temp->link;
        }
        if(temp->data == x){
            Node* t2 = new Node(y);
            prev->link = t2;
            t2->link = temp;
        }
        else{
            cout << "Value Not Found! " << endl;
        }
    }
}

void SLL::insert_After(int x, int y)
{
    if(start == NULL) return;
    Node* temp = start;
    while(temp->link != NULL && temp->data != x){
        temp = temp->link;
    }
    if(temp->data == x){
        Node* t2 = new Node(y);
        t2->link = temp->link;
        temp->link = t2;
    }
    else{
        cout << "Value Not Found! " << endl;
    }
}

void SLL::delete_First()
{
    if(start == NULL) return;
    if(start->link == NULL){
        Node* temp = start;
        delete temp;
        start = NULL;
    }
    else{
        Node* temp = start;
        start = start->link;
        delete temp;
    }
}

void SLL::delete_Kth(int x, int occurence)
{
    int count = 0;
    Node* temp = start;
    Node* prev = start;

    while(temp != NULL){
        if(temp->data == x){
            count++;
            if(count == occurence){
                // Start
                if(temp == start && start->link!=NULL){
                    start = start->link;
                    delete temp;
                    return;
                }
                else if(start->link == NULL){
                    delete temp;
                    return;
                }
                // last
                if(temp->link == NULL){
                    prev->link = NULL;
                    delete temp;
                    return;
                }
                // Middle
                prev->link = temp->link;
                delete temp;
                break;  
            }
        }
        prev = temp;
        temp = temp->link;
    }
}

void SLL::delete_All()
{
    if(start == NULL) return;
    Node* temp = start;
    while(start != NULL){
        start = start->link;
        temp = start;
        delete temp;
    }
    cout << "All Elements are deleted" << endl;
}

void SLL::display()
{
    Node* temp = start;
    while(temp != NULL){
        temp->display();
        temp = temp->link;
    }
    cout << endl;
}