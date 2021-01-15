//singly linked list
#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};
//node insert at end
void insert(node *s, int data){
    while(s->next != NULL){
        s = s->next;
    }
    s->next = new node();
    s->next->data = data;
    s->next->next = NULL;
}
//node insert at beginning
void insertBeginning(node *s, int data){
    node *temp = new node();
    temp->data = data;
    temp->next = NULL;
    if(s->next != NULL){
        temp->next = s->next;
    }
    s->next = temp;
}
//insert at n-th position
int insertMiddle(node *s, int n, int data){
    node *temp1 = new node();
    temp1->data = data;
    temp1->next = NULL;
    if(n==1){
        temp1->next = s;
        s = temp1;
        return 0;
    }
    node *temp2 = s;
    for(int i=0;i<n-1;i++){
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}
//node display function
void display(node *s){
    while(s->next != NULL){
        cout<<s->next->data<<" ";
        s = s->next;
    }
}
//node search function
void search(node *s, int data){
    int count=0;
    while(s->next != NULL){
        if(s->next->data == data){
            count++;
        }
        s = s->next;
    }
    cout<<"Total result found: "<<count<<endl;
}
//node delete function
int deleteNode(node *s, int data){
    while(s->next != NULL){
        if(s->next->data == data){
            s->next = s->next->next;
            return 0;
        }
        s= s->next;
    }
}
//delete first node
struct node *deleteBegining(node *s){
    node *temp = new node(*s);
    s->next = s->next->next;
    free(temp);
    temp = NULL;
    return s;
}
//delete last node
struct node *deleteEnd(node *s){
    node *temp = new node(*s);
    node *temp2 = new node(*s);
    while(temp->next != NULL){
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = NULL;
    free(temp);
    temp = NULL;
    return s;
}
//main function
int main(){
    node *head = new node();
    head->next = NULL;
    int a, val;
    bool x = true;
    while(x){
    cout<<" 1.Create list/add data "<<endl;
    cout<<" 2.Display list "<<endl;
    cout<<" 3.Search in list "<<endl;
    cout<<" 4.Delete node"<<endl;
    cout<<" 5.Exit"<<endl<<endl;
    cout<<" Enter your choice "<<endl;
    cin>>a;
    cout<<endl;
        switch(a){
        case 1:
            cout<<"  1.enter data at end. "<<endl;
            cout<<"  2.enter data at beginning. "<<endl;
            cout<<"  3.enter data at after a specific node. "<<endl;
            cout<<"  Enter your choice "<<endl;
            int b;
            cin>>b;
            switch(b){
            case 1:
                cout<<"  enter data: ";
                cin>>val;
                insert(head, val);
                cout<<endl;
                break;
            case 2:
                cout<<"  enter data: ";
                cin>>val;
                insertBeginning(head, val);
                cout<<endl;
                break;
            case 3:
                int val2;
                cout<<"  enter position: ";
                cin>>val2;
                cout<<"  enter data: ";
                cin>>val;
                insertMiddle(head, val2, val);
                cout<<endl;
                break;
            }
            break;
        case 2:
            cout<<" listed data: ";
            display(head);
            cout<<endl<<endl;
            break;
        case 3:
            cout<<"  enter which data to search: ";
            cin>>val;
            search(head,val);
            cout<<endl;
            break;
        case 4:
            cout<<"  1.delete data at beginning. "<<endl;
            cout<<"  2.delete data at end. "<<endl;
            cout<<"  3.enter data to delete. "<<endl;
            cout<<"  Enter your choice "<<endl;
            int c;
            cin>>c;
            switch(c){
            case 1:
                deleteBegining(head);
                break;
            case 2:
                deleteEnd(head);
                break;
            case 3:
                cout<<"  enter data: ";
                cin>>val;
                deleteNode(head, val);
                break;
            }
            cout<<endl;
            break;
        case 5:
            cout<<"exiting..";
            x = false;
            break;
        default:
            cout<<"wrong input. chose 1-5."<<endl;
            break;
        }

    }
}
