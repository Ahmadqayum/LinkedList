#include<iostream>
using namespace std;

class Node
{
    private:
        int info;
        Node *next;
    public:
        Node(int val)
        {
            info = val;
            next = NULL;
        }

        friend class Stack;
};
class Stack
{
    private:
        Node *top;
        int size;
        int length = 0;
    public:
        Stack(int size)
        {
            this->size = size;
            top = NULL;
        }

        bool isEmpty()
        {
            if(top == NULL)
            {
                return true;
            }
            else 
            {
                return false;
            }
        }

        bool isFull()
        {
            if(length == size - 1)
            {
                return true;
            }
            else 
            {
                return false;
            }
        }

        void Insert(int val)
        {
            Node *newNode = new Node(val);
            if(isEmpty())
            {
                top = newNode;
                length++;
                return;
            }
            else 
            {
                top = newNode;
                length++;
            }
        }
        int Length()
        {
            return length;
        }
        void Display()
        {
            cout<<"VALUE : "<<top->info<<endl;
        }

        void DeleteNode(int val)
        {
            if(isEmpty())
            {
                cout<<"System UnderFlows!"<<endl;
                return;
            }
            else 
            {
                length--;
            }
        }
};
int main()
{
    int size,insertValue,deleteValue;
    cout<<"Enter the amoutn of size : ";
    cin>>size;
    Stack s1(size);
    while(s1.Length() != size)
    {
        cout<<"Enter the value to insert : ";
        cin>>insertValue;
        s1.Insert(insertValue);

        s1.Display();
        cout<<"enter the value to delete : ";
        cin>>deleteValue;
        s1.DeleteNode(deleteValue);
    }

}