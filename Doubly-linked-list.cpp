#include<iostream>
using namespace std;
struct node
{
    node *next; 
    node *prev;
    int info;
    int *p;
};
class doubly
{
    private:
    node *head , *temp , *temp1;
    public:
    doubly()
    {
        temp = head = temp1= NULL;
    }
   
    void insertion(int key)
    {
        
        if(head == NULL)
        {
            temp1 = new node;
            temp1 -> info = key;
            head = temp1;
            head -> prev = head -> next = head;
            temp = head;
            //break;
            return ;
        }
        //temp = head;

        else if(temp ->next == head)
        {
           
                temp1 = new node;
                temp1 ->info = key;
                temp1 ->next = temp ->next;
                temp1 ->prev = temp;
                temp -> next = temp1;
                temp = temp1;
                return;
                    
           
                
               
        }
        else
        {  
            while(temp->next != head)
            {
             
                temp1 = new node;
                
                temp1 -> info = key;
                temp1 ->next = temp -> next;
                temp -> next -> prev = temp1;
                temp -> next = temp1;
                temp1 -> prev = temp;          
            
                temp = temp -> next;
                break;
            }
        }
           
           
    }
    void Remove(int search)
    {
        temp = head;
        if(head == NULL)
        {
            cout<<"Cant delete an empty list ";
        }
        
        if(temp -> next == head)
        {
            if(head -> info == search)
            {
                head = head -> next;
                head -> prev = temp -> prev ;
                temp -> prev -> next = head;
                temp = NULL;
                delete temp;
                
            }
            if(temp -> info == search)
            {
                temp1 = temp -> prev;
                temp1 -> next = head;
                head -> prev = temp1;
                temp = NULL;
                delete temp;
            }
        }
        while(temp -> next != head)
        {
            if(temp -> info == search)
            {
                temp1 = temp -> prev;
                temp1 -> next = temp -> next;
                temp -> next -> prev = temp1;
                temp = NULL;
                delete temp;
            }
            temp = temp ->next;
        }        
    }
    void print()
     {
         temp=head;
         while(temp->next!=head) 
         {
         
             cout<<temp->info<<" ";  
             temp=temp->next;
         }
         cout<<temp1->info<<endl;
     }

};

int main()
{
    doubly ring;
   ring.insertion(5);
   ring.insertion(6);
   ring.Remove(5);
   ring.Remove(6);
   ring.insertion(8);
   ring.Remove(8);
   ring.print();
    
}