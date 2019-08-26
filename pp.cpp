#include <bits/stdc++.h>

typedef long long int lli;

#define pb push_back
#define popb pop_back()
#define pf push_front
#define popf pop_front()
#define si size()
#define be begin()
#define en end()
#define all(v) v.be, v.en
#define le length()
#define mp make_pair
#define mt make_tuple
#define F first
#define S second

#define forz(i, n) for (int i = 0; i < n; i++)
using namespace std;

bool vis[26];
lli ar[26] = {0, };

string itos(string ins){bool check = false;
    string temp = "";
    if(ar[ins[0]-'a'] < 0){check = true;}
    lli dr = abs(ar[ins[0]-'a']);
    while(dr > 0){
        int tmp = dr%10;
        temp.pb(tmp+'0');
        dr/=10;
    }
    if(check){
        temp = '-'+temp;
    }
    return temp;
}

int isoperator(string c)
{
    if (c == "^" || c == "/" || c == "*" || c == "+" || c == "-" || c == "(")
        return 1;
    return 0;
}
int inpre(string c)
{
    if (c == "^")
        return 5;
    if (c == "*" || c == "/")
        return 4;
    if (c == "+" || c == "-")
        return 2;
}

int outpre(string c)
{
    if (c == "^")
        return 6;
    if (c == "*" || c == "/")
        return 3;
    if (c == "+" || c == "-")
        return 1;
}
vector<string> stov(string s)
{
    int n = s.si;
    vector<string> v;
    int flag = 0, f = 0;
    for (int i = 0; i < n; i++)
    {
        f = 0;
        string temp = "";
        if ((s[i] >= '0' && s[i] <= '9'))
        {
            int j = i;
            while (i != s.si && s[i] >= '0' && s[i] <= '9')
            {
                temp += s[i];
                i++;
            }
            i--;
        }
        else
        {
            temp += s[i];
        }
        if (temp == "-")
        {
            if (v.empty())
            {
                v.pb("(");
                v.pb("0");
                flag = 1;
            }
            else
            {
                if (isoperator(v.back()))
                {
                    v.pb("(");
                    v.pb("0");
                    flag = 1;
                }
            }
        }
        if (flag == 1 && temp != "-")
        {
            v.pb(temp);
            v.pb(")");
            flag = 0;
            f = 1;
        }
        if (f != 1)
            v.pb(temp);
    }
    return v;
}
vector<string> post(vector<string> s)
{
    stack<string> st;
    st.push("E");
    int l = s.si;
    vector<string> nv;
    for (int i = 0; i < l; i++)
    {
        if ((s[i][0] >= '0' && s[i][0] <= '9'))
            nv.pb(s[i]);
        else if (s[i] == "(")
            st.push("(");
        else if (s[i] == ")")
        {
            while (st.top() != "E" && st.top() != "(")
            {
                string c = st.top();
                st.pop();
                nv.pb(c);
            }
            if (st.top() == "(")
            {
                string c = st.top();
                st.pop();
            }
        }
        else
        {
            while (st.top() != "E" && outpre(s[i]) < inpre(st.top()))
            {
                string c = st.top();
                st.pop();
                nv.pb(c);
            }
            st.push(s[i]);
        }
    }
    while (st.top() != "E")
    {
        string c = st.top();
        st.pop();
        nv.pb(c);
    }

    return nv;
}
struct node
{
    string s;
    node *lch = NULL, *rch = NULL;
};
node *ctree(vector<string> str)
{

    node *root = NULL;
    vector<node *> stv;
    int i = 0;
    while (i != str.si)
    {
        if (str[i] != "+" && str[i] != "-" && str[i] != "*" && str[i] != "/" && str[i] != "^")
        {
            node *temp = (node *)malloc(sizeof(node));
            temp->s = str[i];
            forz(j, str[i].si)
            {
                if (str[i][j] < '0' || str[i][j] > '9')
                    return NULL;
            }
            stv.pb(temp);
        }
        else
        {
            if (stv.si < 2)
                return NULL;
            node *s1 = stv.back();
            stv.pop_back();
            node *s2 = stv.back();
            stv.pop_back();
            node *temp = (node *)malloc(sizeof(node));
            temp->s = str[i];
            temp->lch = s2;
            temp->rch = s1;
            stv.pb(temp);
        }
        i++;
    }
    if (stv.si != 1)
        return NULL;
    return stv.back();
}
lli value(node *root)
{
    string s = root->s;
    lli ans = 0;
    if (s != "+" && s != "-" && s != "*" && s != "/" && s != "^")
        return stoi(s);
    else
    {
        int lans = value(root->lch), rans = value(root->rch);
        if (s == "+")
            ans = lans + rans;
        else if (s == "-")
            ans = lans - rans;
        else if (s == "*")
            ans = lans * rans;
        else if (s == "/")
            ans = lans / rans;
        else
        {
            //ans = 1;
            //forz(i, rans) ans *= lans;
            ans = (lli)pow(lans, rans);
        }
    }
    return ans;
}

int main()
{
    lli t, n;
    cin >> t;
    while (t--)
    {   
        memset(vis, false, sizeof(vis));
        memset(ar, 0, sizeof(ar));
        cin >> n;
        while (n--)
        {
            string s;
            cin >> s;
            bool cc= false;
            if(s.size() > 1 && s[1] == '='){
                cc =true;
            }
            string st="";
            bool dd = false;
            if(cc){
                vis[s[0]]= true;
                for(lli i = 2; i<s.size(); i++){
                    if(s[i] >= 'a' && s[i] <= 'z'){
                        if(!vis[s[i]]){
                            dd = true;
                            break;
                        }
                        else{string m = "";
                                m.pb(s[i]);
                            string sz = itos(m);
                            for(lli q=0; q<sz.size(); q++){
                                st.pb(sz[q]);
                            }
                        }
                    }
                    else{
                        st.pb(s[i]);
                    }
                }
            }else{
                for(lli i = 0; i<s.size(); i++){
                    if(s[i] >= 'a' && s[i] <= 'z'){
                        if(!vis[s[i]]){
                            dd = true;
                            break;
                        }
                        else{string m = "";
                                m.pb(s[i]);
                            string sz = itos(m);
                            for(lli q=0; q<sz.size(); q++){
                                st.pb(sz[q]);
                            }
                        }
                    }
                    else{
                        st.pb(s[i]);
                    }
                }
            }
            if(dd){cout<<"CANT BE EVALUATED\n";
            continue;}
            vector<string> str = stov(st);
            str = post(str);
            node *root = ctree(str);
            if (root == NULL)
                cout << "CANT BE EVALUATED" << endl;
            else
                if(cc){
                    ar[s[0]-'a'] = value(root);
                }
                else{
                    cout<<value(root)<<endl;
                }
        }
    }
    return 0;
} 
