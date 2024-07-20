#include<iostream>
#include<stdlib.h>

using namespace std;

template <class X>
class node
{
public :
    X data;
    node *next, *pre;
};

template <class X>
class list
{
   node<X> *first, *last, *temp, *temp1;

public:
    list();
    ~list();
    void insert_at_beg();
    void insert_in_mid(int);
    void insert_at_end();
    void delete_from_beg();
    void delete_from_mid(int);
    void delete_from_end();
    void search_item(int);
    void count_item();
    void display();
    void reverse_list();
};

//constructor
template <class X>
list<X> :: list()
{
    first=NULL;
    last=NULL;
}

//destructor
template <class X>
list<X> :: ~list()
{
    for(node<X> *p; first!=NULL; )
    {
        p=first->next;
        delete first;
        first=p;
    }
}

template <class X>
void list<X> :: insert_at_beg()
{
    //create new node
    temp=new node<X>;
    cin>>temp->data;
    temp->next=NULL;
    temp->pre=NULL;

    // for first node
    if(first==NULL)
        first=last=temp;

    //for all other nodes
    else
    {
        temp->next=first;
        first=temp;
    }

}

template <class X>
void list<X> :: insert_at_end()
{
    //create new node
    temp=new node<X>;
    cin>>temp->data;
    temp->next=NULL;
    temp->pre=NULL;

    // for first node
    if(first==NULL)
        first=last=temp;

    //insert node in the list
    else
    {
        last->next=temp;
        temp->pre=last;
        last=temp;
    }
}

template <class X>
void list<X> :: insert_in_mid(int pos)
{
    int count=1;

    //create new node
    temp1=new node<X>;
    cin>>temp1->data;

    // for first node
    if(first==NULL)
        first=last=temp;

    else
    {
        //temp traverses to the node after which the user want to inert new node
        temp=first;
        while(count<pos-1)
        {
            temp=temp->next;
            count++;
        }

        //inserting new node
        temp1->next=temp->next;
        temp->next=temp1;
    }

}

template <class X>
void list<X> :: delete_from_beg()
{
    //check if list is empty
    if(first==NULL)
        cout<<"List is empty. Underflow.";

    //list contains only one node
    else if(first==last)
    {
        cout<<"Deleting node with data : "<<first->data;
        temp=first;
        delete temp;
        first=NULL;
        last=NULL;
    }

    //deleting node from the beginning
    else
    {
        temp=first;
        first=first->next;
        first->pre=NULL;
        delete temp;
    }
}

template <class X>
void list<X> :: delete_from_mid(int pos)
{
    int count=1;
    //check if list is empty
    if(first==NULL)
        cout<<"List is empty. Underflow.";

    //deleting node from the middle
    else
    {
        temp=first;
        while(count<pos-1)
        {
            temp=temp->next;
            count++;
        }
        temp1=temp->next;
        temp->next=(temp->next)->next;
        (temp->next)->pre=temp; //links the next node to the previous node of the node to be deleted
        delete temp1;
    }
}

template <class X>
void list<X> :: delete_from_end()
{

    //check if list is empty
    if(first==NULL)
        cout<<"List is empty. Underflow.";

    //list contains only one node
    else if(first==last)
    {
        cout<<"Deleting node with data : "<<first->data;
        temp=first;
        delete temp;
        first=NULL;
        last=NULL;
    }

    //deleting node from end of the list
    else
    {
        temp=last;
        last=last->pre;
        last->next=NULL;
        delete temp;
    }
}

template <class X>
void list<X> :: count_item()
{
    //check if list is empty
    if(first==NULL)
        cout<<"List is empty. Underflow.";

    else
    {
        int counter=0;
        temp=first;

        while(temp!=NULL)
        {
            counter++;
            temp=temp->next;
        }
        cout<<"No. of list items : "<<counter;
    }
}

template <class X>
void list<X> :: search_item(int search)
{
   //check if list is empty
    if(first==NULL)
        cout<<"List is empty. Underflow.";

    else
    {
        temp=first; int counter=0, pos=0;
        while(temp!=NULL)
        {
            pos++;
            if(temp->data==search)
            {
                counter=1;
                cout<<"Item found at position : "<<pos;
                break;
            }
            temp=temp->next;
        }
        if(counter==0)
            cout<<"Item not found in the list.";
    }
}

template <class X>
void list<X> :: display()
{
    temp=first;

    //check if list is empty
    if(first==NULL)
        cout<<"List is empty";

    else
    {
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
}

template <class X>
void list<X> :: reverse_list()
{
    //check if list is empty
    if(first==NULL)
        cout<<"List is empty. Underflow.";

    else
    {
        temp=first;

        while(temp!=NULL)
        {
            temp1=temp->next;
            temp->next=temp->pre;
            temp->pre=temp1;
            temp=temp1;
        }

        temp=last;
        last=first;
        first=temp;
    }
}

int main()
{
   list<int> obj; int ch; char ch1; int pos,search;
   do
    {
        system("cls");
        cout<<"MENU TO PERFORM ACTIONS ON A DOUBLY LINKED LIST USING TEMPLATES.\n";
        cout<<"1. Insert at beginning.\n";
        cout<<"2. Insert in middle.\n";
        cout<<"3. Insert at end.\n";
        cout<<"4. Delete from beginning.\n";
        cout<<"5. Delete from middle.\n";
        cout<<"6. Delete from end.\n";
        cout<<"7. Search in the linked list.\n";
        cout<<"8. Count the no of items in the list.\n";
        cout<<"9. Reverse the linked list.\n";
        cout<<"10. Display the linked list.\n";
        cout<<"Enter choice : ";
        cin>>ch;

        switch(ch) {
            case 1 : cout<<"Input list item : ";
                       obj.insert_at_beg();
                       break;

            case 2 : cout<<"Input the position at which you want to add data : ";
                     cin>>pos;
                     cout<<"Input List Item : ";
                     obj.insert_in_mid(pos);
                     break;

            case 3 : cout<<"Input List Item : ";
                       obj.insert_at_end();
                       break;

            case 4 :  obj.delete_from_beg();
                       cout<<"List after deletion is : ";
                       obj.display();
                       break;

            case 5 : cout<<"Enter the list item no. you want to delete : ";
                       cin>>pos;
                       obj.delete_from_mid(pos);
                       cout<<"List after deletion : ";
                       obj.display();
                       break;

            case 6 : obj.delete_from_end();
                       cout<<"List after deletion : ";
                       obj.display();
                       break;

            case 7 : cout<<"Enter the item data you want to search : ";
                       cin>>search;
                       obj.search_item(search);
                       break;

            case 8 : obj.count_item();
                       break;

            case 9 : obj.reverse_list();
                     cout<<"List after reversing : ";
                     obj.display();
                     break;

            case 10 : cout<<"Linked List : ";
                        obj.display();
                        break;

            default   : cout<<"Invalid input";
        }
    cout<<"\nDo you want to continue: ";
    cin>>ch1;
   }while(ch1=='y');
   return 0;
}
