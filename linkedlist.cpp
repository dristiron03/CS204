#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
	int y;
	struct node* next;
};

struct node* head = NULL;
int addFirst(int x, int y){
	struct node* b = NULL;
	b = new node();
	b->x = x;
	b->y = y;
	b->next=NULL;
	if(head == NULL){
		head = b;
		return 0;
	}
	else{
		b->next = head;
		head = b;
		return 0;
	}
}

int DelFirst(){
	struct node* b=head;
	if(head == NULL){
		return -1;
	}
	else{
		head = head->next;
		delete b;
		return 0;
	}
}

int Del(int x, int y){
	struct node* b = head;
	struct node* temp = NULL;
	if(b->x && b->y == y){
		head = head->next;
		delete b;
		return 0;
	}
	while((b->x != x || b->y != y) && b != NULL){
		temp = b;
		b= b->next;
	}
	if(b == NULL){
		return -1;
	}
	else{
		temp->next = b->next;
		delete b;
	}
	return 0;
}

int Length(){
	int z =0 ;
	struct node* ptr = head;
	while(ptr != NULL){
		z++;
		ptr=ptr->next;
	}
	return z;
}

bool Search(int x, int y){
	struct node* ptr = head;
	while(ptr != NULL){
		if(ptr->x == x && ptr->y ==y){
			return true;
		}
		ptr=ptr->next;
	}
	return false;
}

void Search(float d){
	struct node* ptr = head;
	while(ptr != NULL){
		int y = ptr->x;
		int z = ptr->y;
		if(sqrt(y*y+z*z) <= d){
			cout<<"("<<y<<","<<z<<")";
		}
		ptr=ptr->next;
	}
	return;
}


int main(){
	long long t;
	cin>>t;
	while(t--){
		long long x;
		cin>>x;
		if(x == 1){
			int y, z;
			cin>>y>>z;
			addFirst(y, z);
		}
		else if(x==2){
			DelFirst();
		}
		else if(x == 3){
			int y, z;
			cin>>y>>z;
			Del(y, z);
		}
		else if(x == 4){
			float d;
			cin>>d;
			Search(d);
			cout<<endl;
		}
		else if(x == 5){
			int y, z;
			cin>>y>>z;
			if(Search(y, z)){
				cout<<"True\n";
			}else{
				cout<<"False\n";
			}
		}
		else if(x==6){
			cout<<Length()<<endl;
		}
	}
}