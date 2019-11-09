//Question Link-> https://www.hackerearth.com/practice/data-structures/queues/basics-of-queues/tutorial/
#include<bits/stdc++.h>
using namespace std;
void enqueue(vector<int>&queue, int element){
    queue.push_back(element);
}
void dequeue(vector<int>&queue){
    queue.erase(queue.begin());
}
int front(vector<int>queue){
    return queue[0];
}
int size(vector<int>queue){
    return queue.size();
}
bool isEmpty(vector<int>queue){
    if(queue.size() == 0){return true;}
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<int>queue;
    while(n--){
        char c;
        cin>>c;
        if(c == 'D'){
            if(!isEmpty(queue)){
                cout<<front(queue)<<" ";
                dequeue(queue);
                cout<<size(queue)<<"\n";
            }
            else{
                cout<<"-1 0\n";
            }
        }else{
            int x;
            cin>>x;
            enqueue(queue, x);
            cout<<size(queue)<<"\n";
        }
    }
}