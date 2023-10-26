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
        friend class Queue;
};
class Queue
{
    private:
        Node *front;
        Node *rear;
    public:
        Queue(){front = NULL;rear = NULL;}
        void enqueue(int val)
        {
            Node *newNode = new Node(val);
            if(front == nullptr)
            {
                front = rear = newNode;
            }
            else 
            {
                rear->next = newNode;
                rear = newNode;
            }
        }
        void Dequeue()
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
        int FrontElement()
        {
            return front->info;
        }
        
};
int main()
{
    Queue q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    cout<<"Front element is : "<<q1.FrontElement()<<endl;
    q1.Dequeue();
    cout<<"Front Element is : "<<q1.FrontElement()<<endl;
}