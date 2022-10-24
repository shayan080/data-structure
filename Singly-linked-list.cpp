#include<iostream>
using namespace std;
struct node
{
    node *next; 
    int info;
    int *p;
};
class singly
{
    private:
    node *head , *temp , *temp1;
    public:
    singly()
    {
        temp = head = temp1= NULL;
    }
    
    ~singly()
    {
        delete head,temp,temp1;
    }
   
    void insertion(int key)
    {
        
        if(head == NULL)
        {
            temp1 = new node;
            temp1 -> info = key;
            head = temp1;
            head -> next = NULL;
            temp = head;
            return ;
        }
        //temp = head;

        else 
        {
           
             temp1 = new node;
             temp1 ->info = key;
             temp1 ->next = NULL;
             temp -> next = temp1;
             temp = temp1;
             return;
                                   
        }
        
           
           
    }

    void search(int key)
    {   
        temp = head;
        if(head == NULL)            
        {  
             cout<<"No list exist";
             return;
        }
        else 
        {
             while(temp -> next != NULL)
             {
                  if(temp -> info == key)
                  { 
                       cout<<temp -> info<<"found";
                       return;
                  }
                 
                  temp = temp -> next;
                 
             }
        }

        else 
        {
             cout<<"NOT FOUND ";
             return;
        }
                  
       
    }
    void Remove(int search)
    {
        temp = head;
        if(head == NULL)
        {
            cout<<"Cant delete an empty list ";
        }
        
       
        if(head -> info == search)
        {
             head = head -> next;
             temp1 = temp;
             temp = head;
             temp1 = NULL;
             delete temp1;
                
        }
        else
        {
            while(temp != NULL)
            {

                if(temp ->next ->info == search)
                {
                    temp1 = temp-> next;
                    temp -> next = temp1 -> next;
                    temp1 = NULL;
                    delete temp1;
                }
                temp = temp-> next;
            }
        }
        
    }
    void print()
     {
         temp=head;
         while(temp->next!=NULL) 
         {
         
             cout<<temp->info<<" ";  
             temp=temp->next;
         }
         cout<<temp1->info<<endl;
     }

};

int main()
{
    singly ring;
   ring.insertion(5);
   ring.insertion(6);
   ring.Remove(5);
   ring.Remove(6);
   ring.insertion(8);
   ring.Remove(8);
   ring.print();
    
}