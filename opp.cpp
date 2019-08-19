#include <bits/stdc++.h>
#define lli long long int
#define pb push_back
#define vt vector
#define f(x, y, z) for (lli x = y; x < z; x++)
using namespace std;
vector<string> stringTovector(string s)

{
    int n = s.size();
    vector<string> st;
    for(int i = 0; i<n;i++)
        { string temp="";
        if((s[i] >= '0' && s[i] <= '9')) 
        { int j = i;
          for(;(s[j] >= '0' && s[j] <= '9');j++){
                temp+=s[j];}
            i = j-1;
        }
        else 
        {temp+=s[i];
          }st.push_back(temp);}
        return st;
}
int inprec(char input) 
{ 

    switch (input) { 
    case '+': 
    case '-': 
      return 2; 
    case '*': 
    case '%':  
    case '/':  
      return 4;
    case '^':  
        return 5; 
    case '(': 
        return 0; 
    } 
} 



int outprec(char input) 
{ 

    switch (input) 
    { 
    case '+': 
    case '-': 
        return 1; 
    case '*': 
    case '%': 
    case '/': 
        return 3; 
    case '^': 
        return 6; 
    case '(': 
        return 100; 
    } 
} 

vector<string> infixToPostfix(vector<string> s) 
{ 
    stack<string>st; 
    st.push("N"); 
    int l = s.size(); 

    vector<string> ns;

    for(int i = 0; i < l; i++) 

    { 

        if((s[i][0] >= '0' && s[i][0] <= '9')) 

            ns.push_back(s[i]);

        else if(s[i] == "(") 

           st.push("("); 

        else if(s[i] == ")") 

        { 

            while(st.top() != "N" && st.top() != "(") 

            { 

                string c = st.top(); 

                st.pop(); 

                ns.push_back(c);

            } 

            if(st.top() == "(") 

            { 

                string c = st.top(); 

                st.pop(); 

            } 

        } 

        else{ 

            while(st.top() != "N" && outprec(s[i][0]) < inprec((st.top())[0])) 

            { 

                string c = st.top(); 

                st.pop(); 

                ns.push_back(c); 

            } 

            st.push(s[i]); 

        } 

  

    } 

    while(st.top() != "N") 

    { 

        string c = st.top(); 

        st.pop(); 
        ns.push_back(c); 
    } 
    return ns;
} 

struct node
{
  string s;
  node* lch=NULL,*rch=NULL;
};

node* construct_tree(vt <string> postfix)
{
   node *root=NULL;
   vt <node*> stk;
   int i=0;
   while(i!=postfix.size())
   {
     if(postfix[i]!="+" && postfix[i]!="-" && postfix[i]!="*" && postfix[i]!="/" && postfix[i]!="^")
       {
         node *temp=(node *)malloc(sizeof(node));
         temp->s=postfix[i];
         f(j,0,postfix[i].size())
         if(postfix[i][j]<'0' || postfix[i][j]>'9')return NULL;
         stk.pb(temp);
       } 
     else
     {
       if(stk.size()<2)return NULL;
       node *s1=stk.back();
       stk.pop_back();
       node *s2=stk.back();
       stk.pop_back();
       node *temp=(node *)malloc(sizeof(node));
       temp->s=postfix[i];
       temp->lch=s2;
       temp->rch=s1;
       stk.pb(temp); 
     }
     i++;
   }
   if(stk.size()!=1)return NULL;
   return stk.back();
}

lli evaluate(node *root)
{
   string s=root->s;

   lli ans=0;

   if(s!="+" && s!="-" && s!="*" && s!="/" && s!="^")
   {return stoi(s);}
  else{
      int lc=evaluate(root->lch),rc=evaluate(root->rch);
      if(s=="+"){ans=lc+rc;}
      else if(s=="-"){ans=lc-rc;}
      else if(s=="*"){ans=lc*rc;}
      else if(s=="/"){ans=lc/rc;}
      else{ans=1;
        f(i,0,rc){ans*=lc;}
      }
  }
  return ans;
}
int main() 
{ 
  int t;
  cin>>t;
  while(t--)
  {   string s;
      cin>>s;
      vector<string> postfix=stringTovector(s);
      postfix=infixToPostfix(postfix);
      node* root=construct_tree(postfix);
      if(root!=NULL)
      {
      cout<<evaluate(root)<<"\n";
      }
      else{cout<<"CAN'T BE EVALUATED\n";}
    }
  return 0;
}



