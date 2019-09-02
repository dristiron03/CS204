#include <bits/stdc++.h>
typedef long long int ll;
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
#define F first
#define S second
#define forz(i, n) for (int i = 0; i < n; i++)
using namespace std;
unordered_map<string, ll> mm;
unordered_map<string, bool> mm1;
string itos(string ins){bool check = false;
    string temp = "";
    if(mm[ins] < 0){check = true;}
    ll dr = abs(mm[ins]);
    while(dr > 0){
        int tmp = dr%10;
        temp.pb(tmp+'0');
        dr/=10;
    }
    reverse(temp.begin(), temp.end());
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
ll value(node *root)
{
    string s = root->s;
    ll ans = 0;
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
            ans = (ll
        )pow(lans, rans);
        }
    }
    return ans;
}

int main()
{
    ll t, n;
    cin >> t;
    while (t--)
    {   cin >> n;
        while (n--)
        {
            string s;
            cin >> s;
            string vari="";
            bool dd=false;
            for(ll i=0; i<s.size(); i++){
                if(s[i] == '='){dd=true; break;}
                vari.pb(s[i]);
            }
            bool cc=false;
            string st="";
            ll i=vari.size(); 
            //cout<<i<<endl;
            if(dd){i++;}
            else{i=0;}
            while(i<s.size()){
                string temp="";
                if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z'){
                    while(i< s.size() && (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')){
                        temp.pb(s[i]);
                        i++;
                    }
                    if(mm1[temp] == false){
                        cc=true;
                        cout<<"CANT BE EVALUATED\n";
                        break;
                    }
                    temp=itos(temp);
                }
                else{
                    temp.pb(s[i]);
                    i++;
                }
                for(ll j=0; j<temp.size(); j++){
                    st.pb(temp[j]);
                }
            }
            if(cc){continue;}
            //cout<<st<<endl;
            vector<string> str = stov(st);
                str = post(str);
                node *root = ctree(str);
            //if(!dd){cout<<value(root)<<endl;
            //continue;}
            if (root == NULL)
                cout << "CANT BE EVALUATED" << endl;
            else
                if(dd){
                    mm[vari] = value(root);
                    mm1[vari] = true;
                }
                else{
                    cout<<value(root)<<endl;
                }
        }
    }
    return 0;
} 
