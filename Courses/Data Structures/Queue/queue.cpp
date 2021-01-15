#include <iostream>
using namespace std;

int queue[3], s=3, front=-1, rear=-1;

void enqueue(int val)
{
    if(rear==s-1)
        cout<<"Queue overflowed!!!"<<endl;
    else
    {
        if(front==-1)
        front=0;
        rear++;
        queue[rear]=val;
    }
}
void dequeue()
{
   if(front==-1||front>rear)
   {
       cout<<"Queue is empty";
       return;
   }
   else
   {
       cout<<queue[front]<<endl;
       front++;
       //rear--;
   }
}
void display()
{
    if(front==-1)
        cout<<"Queue is empty"<<endl;
    else
    {
        cout<<"Queue elements are : ";
        for (int i=front; i<=rear; i++)
        cout<<queue[i]<<" ";
         cout<<endl;
    }
}
int main()
{
    int x, val;
    for(;;)
    {
        cout<<"What you want to do?"<<endl;
        cout<<"1. Enqueue element in the queue"<<endl;
        cout<<"2. Dequeue element in the queue"<<endl;
        cout<<"3. Display the queue"<<endl;
        cin>>x;
        cout<<endl;

        switch(x)
        {
        case 1:
            {
                cout<<"Enter value: ";
                cin>>val;
                enqueue(val);
                break;
            }
        case 2:
            {
                dequeue();
                break;
            }
        case 3:
            {
                display();
                break;
            }
        default:
            cout<<"Invalid Choice"<<endl;
        }
    }
}

