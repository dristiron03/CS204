#include<bits/stdc++.h>

using namespace std;

#define lli long long 

struct node{
    lli data;
    node *next;
};




class Queue{
    public:
    void enqueue(lli x)
    {
        node *t=(node *)malloc(sizeof(node));
        //cout<<"XXX";
        // if(t==NULL)
        // {
        //     cout<<"Failed"<<endl; return;
        // }
        
        t->data=x;
        t->next=NULL;
        if(this->start==NULL)
        {
            this->end=t;
            this->start=t;
        }
        else{
        this->end->next=t;
        this->end=t;
        }
        cout<<"Added "<<x<<endl;
    }
    lli dequeue(void)
    {
        node *t=this->start;
        if(!t)
        {
            cout<<"Queue is empty!!"<<endl;
            return 0;
        }
        this->start=t->next;
        lli x=t->data;
        delete t;
        cout<<x<<endl;
        return x;
    }
    void show()
    {
        node *t=this->start;
        while(t!=NULL)
        {
            cout<<t->data<<' ';
            t=t->next;
        }    
        cout<<endl;
    }
    Queue()
    {
        this->end=NULL;
        this->start=NULL;
    }
    private:
    node *start,*end;
};

int main()
{
    Queue Q;
    start:
    cout<<"Enter choice : \n 1. Enqueue \n 2. Dequeue \n 3. Show \n 4. Exit \n";
    lli x;
    lli c;
    cin>>c;
    switch(c)
    {
        case 1: cin>>x;
                Q.enqueue(x);
                break;
        case 2: Q.dequeue();
                break;
        case 3: Q.show();
                break;
        case 4: return 0;
        default: cout<<"Wrong choice!!"<<endl;

    }
    goto start;
    return 0;
}
