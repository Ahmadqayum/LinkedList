#include<iostream>
using namespace std;

class Node
{
    private:
        int info;
        Node *next;
    public:
        Node(int value)
        {
            info = value;
            next = NULL;
        }

        friend class LinkedList;
};

class LinkedList
{
    private:
        Node *head;
    public:
        LinkedList()
        {
            head = NULL;
        }
        void Adding(int value)
        {
            Node *newNode = new Node(value);
            if(head == NULL)
            {
                head = newNode;
                return;
            }

            Node *current = head;
            while(current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
        }

        void deleting(int value)
        {
            if(head != NULL && head->info == value)
            {
                Node *temp = head;
                head = head->next;
                delete temp;
            }

            Node *current = head;
            Node *previous = NULL;
            while(current != NULL)
            {
                if(current->info == value)
                {
                    previous->next = current->next;
                    delete current;
                    return;
                }
                previous = current;
                current = current->next;
            }
        }

        void search(int value)
        {
            Node *current = head;
            bool valuePresent = false;

            while(current != NULL)
            {
                if(current->info == value)
                {
                    valuePresent = true;
                }
                current = current->next;
            }

            if(valuePresent)
            {
                cout<<"Value Present!"<<endl;
            }
            else 
            {
                cout<<"There is no such value!"<<endl;
            }
        }

        void Display()
        {
            
            Node *current = head;
            while(current != NULL)
            {
                cout<<current->info<<" ";
                current = current->next;
            }
            cout<<endl;
        }
};

int main()
{
    LinkedList l1;
    int value,option,deletevalue,searchingvalue;
    while(true)
    {
        cout<<"Enter the value  : ";
        cin>>option;
        if(option == 1)
        {
            cout<<"Enter the value you want to add : ";
            cin>>value;
            l1.Adding(value);
        }
        else if(option == 2)
        {
            cout<<"Enter the value you want to delete : ";
            cin>>deletevalue;
            l1.deleting(deletevalue);
        }
        else if(option == 3)
        {
            l1.Display();
        }
        else if(option == 4)
        {
            cout<<"Which value do you want to search : ";
            cin>>searchingvalue;
            l1.search(searchingvalue);
        }
    }
}