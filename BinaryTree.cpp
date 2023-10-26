#include<iostream>
using namespace std;

class Node
{
    private:
        int info;
        Node *left,*right;
    public:
        Node(int val)
        {
            info = val;
            left = right = NULL;
        }
        friend class BinaryTree;
};

class BinaryTree
{
    private:
        Node *root;
    public:
        BinaryTree(){root = NULL;}

        Node *insert(Node *temp,int val)
        {
            if(temp == NULL)
            {
                Node *newNode = new Node(val);
                temp = newNode;
                return temp;
            }
            if(val < temp->info)
            {
               temp->left = insert(temp->left,val); 
            }
            else if(val > temp->info)
            {
                temp->right = insert(temp->right,val);
            }
            return temp;
        }
        void insert(int val)
        {
            root = insert(root,val);
        }
        void inorderTraversal(Node *temp)
        {
            if(temp == NULL)
            {
                return;
            }
            inorderTraversal(temp->left);
            cout<<temp->info<<" ";
            inorderTraversal(temp->right);
        }
        bool SearchElement(Node *temp,int val)
        {
            if(temp == NULL)
            {
                return false;
            }
            if(temp->info == val)
            {
                return true;
            }
            if(val > temp->info)
            {
                return SearchElement(temp->right,val);
            }
            else if(val < temp->info)
            {
                return SearchElement(temp->left,val);
            }
        }
        bool Element(int val)
        {
            return SearchElement(root,val);
        }

        void inorderTraversal()
        {
            inorderTraversal(root);
            cout<<endl;
        }
};
int main()
{
    BinaryTree t1;
    int option;
    int number,searchingElement;
    while(true)
    {
        cout<<"Enter the option : ";
        cin>>option;
        if(option == 1)
        {
            cout<<"Enter a number : ";
            cin>>number;
            t1.insert(number);
        }
        else if(option == 2)
        {
            t1.inorderTraversal();
        }
        else if(option == 3)
        {
            cout<<"Search element : ";
            cin>>searchingElement;
            if(t1.Element(searchingElement))
            {
                cout<<searchingElement<<" has been found!"<<endl;
            }
            else if(!t1.Element(searchingElement))
            {
                cout<<"There is no such element!"<<endl;
            }
        }
    }
}