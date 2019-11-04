//Question link = https://www.hackerearth.com/practice/data-structures/trees/binary-and-nary-trees/tutorial/
/*Given a binary tree which has T nodes, you need to find the diameter of that binary tree. The diameter of a tree is the number of nodes on the longest path between two leaves in the tree.

Input:
First line contains two integers, T and X, number of nodes in the tree and value of the root.
Next  lines contain details of nodes.
Each detail of node contains two lines. First lines contains a string and second line contains an integer, which denotes the path of the node and the value of the node respectively.

String consists of only L or R. L denotes left child and R denotes right child. ( Look at the sample explanation for more details )

Output:
Print the diameter of the binary tree.*/


#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vll vector<long long>
struct node{
    int val;
    struct node* left;
    struct node* right;
};
struct node * newnode(int element)
    {
        struct node * temp=(node * )malloc(sizeof(node));
        temp->val=element;
        temp->left=temp->right=NULL;
        return temp;
    }
void create(string s, int val, struct node* src){
    struct node *nd = newnode(val);
    int i=0;
    struct node *top = src;
    while(i< s.size()-1){
        if(s[i] == 'L'){
            top = top->left;
        }
        else if(s[i] == 'R'){
            top=top->right;
        }
        i++;
    }
    if(s[i] == 'L'){
        top->left = nd;
        }
    else if(s[i] == 'R'){
        top->right = nd;
        }
}

int height(struct node *src){
    if(src == NULL){
        return 0;
    }else{
        int ldepth = height(src->left);
        int rdepth = height(src->right);

        if(ldepth > rdepth){
            return (ldepth+1);
        }else{
            return (rdepth+1);
        }
    }
}

int diameter(struct node *src){
    if(src == NULL){
        return 0;
    }
    int rheight = height(src->right);
    int lheight = height(src->left);

    int rdia = diameter(src->left);
    int ldia = diameter(src->right);

    return max(1+lheight+rheight, max(rdia, ldia));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    */
    int t, x;
    cin>>t>>x;
    struct node *cc, *top;
    top = newnode(x);
    vector<pair<string, int > > vv(0);
    REP(i, 0, t-1){
    string st; 
    int a;
    cin>>st>>a;
    vv.pb(make_pair(st, a));
    }
    sort(vv.begin(), vv.end());
    REP(i, 0, t-1){
        cc = top;
        create(vv[i].first, vv[i].second, cc);
    }
    //cc = top;
    cout<<diameter(top);
}
