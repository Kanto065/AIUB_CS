#include <iostream>
using namespace std;

int stack[5], s=5, top=-1;

void push(int val)
{
   if(top>=s-1)
   cout<<"Stack Overflow"<<endl;
   else
    {
      top++;
      stack[top]=val;
    }
}
void pop()
{
   if(top<=-1)
   cout<<"Stack is empty"<<endl;
   else
    {
      cout<<stack[top]<<endl;
      top--;
      cout<<endl;
    }
}
void display()
{
   if(top>=0)
    {
      for(int i=top; i>=0; i--)
      cout<<stack[i]<<" ";
      cout<<endl;
    }
    else
        cout<<"Stack is empty"<<endl;
}
int main()
    {
        int x, val;

        for(;;){
        cout<<"What you want to do?"<<endl;
        cout<<"1. Push element in the stack"<<endl;
        cout<<"2. Pop element in the stack"<<endl;
        cout<<"3. Display the stack"<<endl;
        cin>>x;
        cout<<endl;
    switch(x)
        {
        case 1:
            {
                cout<<"Enter value: ";
                cin>>val;
                push(val);
                break;
            }
         case 2:
            {
                pop();
                break;
            }
         case 3:
            {
                display();
                break;
            }
         default:
            {
            cout<<"Invalid Choice"<<endl;
            }
      }
        }
   return 0;
}

