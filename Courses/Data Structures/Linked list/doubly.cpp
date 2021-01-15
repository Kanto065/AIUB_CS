//doubly linked list
#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node *prev;
};
void insert(node *s, int data){
    while(s->next != NULL){
        s = s->next;
    }
    s->next = new node();
    s->next->data = data;
    s->next->next = NULL;
    s->next->prev = s;
}
void insertBeginning(node *s, int data){
    node *temp = new node();
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    if(s->next != NULL){
        temp->next = s->next;
    }
    s->next = temp;
    temp->prev = s;
}
void display(node *s){
    while(s->next != NULL){
        cout<<s->next->data<<" ";
        s = s->next;
    }
}
void reverseDisplay(node *s){
    while(s->next != NULL){
        s = s->next;
    }
    while(s->prev != NULL){
        cout<<s->data<<" ";
        s = s->prev;
    }

}
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
int deleteNode(node *s, int data){
    while(s->next != NULL){
        if(s->next->data == data){
            s->next = s->next->next;
            return 0;
        }
        s= s->next;
    }
}
struct node *deleteBegining(node *s){
    node *temp = new node(*s);
    s->next = s->next->next;
    free(temp);
    temp = NULL;
    return s;
}
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
int main(){
    node *head = new node();
    head->next = NULL;
    head->prev = NULL;

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
            }
            break;
        case 2:
            cout<<" listed data: ";
            display(head);
            cout<<endl;
            cout<<" reverse order: ";
            reverseDisplay(head);
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
