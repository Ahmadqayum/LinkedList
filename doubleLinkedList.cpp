#include<iostream>
using namespace std;

class Node{
    private:
        int info;
        Node *next;
        Node *previous;
    public:
        Node(int value)
        {
            info = value;
            next = NULL;
            previous = NULL;
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

        void Add(int value)
        {
            Node *newNode = new Node(value);
            if(head == NULL)
            {
                head = newNode;
                return;
            }

            Node *temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->previous = temp;
        }
        
        void Adding(int key, int value)
        {
            Node *newNode = new Node(value);
            Node *temp = head;
            
            while(temp != NULL)
            {
                if(temp->info == key)
                {
                    newNode->next = temp->next;
                    if(temp->next != NULL)
                    {
                        temp->next->previous = newNode;
                    }
                    newNode->previous = temp;
                    temp->next = newNode;
                    return;
                }
                temp = temp->next;
            }
            // If key is not found, just add it to the end of the list
            Add(value);
        }
        
        void Search(int value)
        {
            Node *temp = head;
            while(temp != NULL)
            {
                if(temp->info == value)
                {
                    cout << "Value is present!" << endl;
                    return;
                }
                temp = temp->next;
            }
            cout << "Value is not present!" << endl;
        }
        
        void Delete(int value)
        {
            if(head != NULL && head->info == value)
            {
                Node *temp1 = head;
                head = head->next;
                delete temp1;
                return;
            }
            Node *temp = head;
            while(temp != NULL)
            {
                if(temp->info == value)
                {   
                    if(temp->previous != NULL)
                    {
                        temp->previous->next = temp->next;
                    }
                    if(temp->next != NULL)
                    {
                        temp->next->previous = temp->previous;
                    }
                    delete temp;
                    return;
                }
                temp = temp->next;
            }
        }

        void print()
        {
            Node *temp = head;
            while(temp != NULL)
            {
                cout << temp->info << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};  

int main()
{
    LinkedList l1;
    l1.Add(5);
    l1.Add(3);
    l1.Adding(5,8);
    l1.Adding(3,9);
    l1.Adding(9,10);
    l1.Search(5);
    l1.Delete(5);
    l1.Delete(9);
    l1.print();
}
