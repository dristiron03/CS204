 
#include<iostream>
using namespace std;

class dsu
{
    private:
        int *parent_list;
        int *set_size;
    public:
        dsu(int size)
        {
            parent_list=(int *)(malloc((size+1)*sizeof(int)));
            set_size=(int *)(malloc((size+1)*sizeof(int)));
            for(int i=0;i<=size;i++)
                parent_list[i]=i;
            for(int i=0;i<=size;i++)
                set_size[i]=1;
        }
        int find(int node)
        {
            if(node==parent_list[node]) 
                return node;
            else
                return parent_list[node]=find(parent_list[node]);
        }
        bool is_same(int node1,int node2)
        {
            node1=find(node1);
            node2=find(node2);
            if(node1==node2)
                return true;
            else
                return false;
        }
        bool union_(int node1,int node2)
        {
            node1=find(node1);
            node2=find(node2);
            if(node1==node2)
                return false;
            if(set_size[node1]<set_size[node2])
            {
                int temp_node=node1;
                node1=node2;
                node2=temp_node;
            }
            parent_list[node2]=node1;
            set_size[node1]+=set_size[node2];
            return true;
        }
};

int main()
{
    dsu v(5);
    v.union_(1,5);
    v.union_(3,5);
    cout<<v.is_same(3,1)<<endl;
    cout<<v.is_same(3,2)<<endl;
    return 0;
}