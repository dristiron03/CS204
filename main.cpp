#include<bits/stdc++.h>
#define pb push_back
#define ss second
#define ff first
using namespace std;
const int N = 165;
map<string,string>name;
map<string,int>grade_values;
struct courses{
    string semester;
    string names;
    int credits;
};
struct grades{
    vector<pair<string,pair<string,string>>>sem;
};
int string_to_int(string s){
    int sum=0;
    for(int i = 0; i<s.size(); i++){
        sum *= 10;
        sum += s[i]-'0';
    }
    return sum;
}
map<string, courses>course_id;
map<string, grades>roll_grades;
int main(){
    fstream fp;
    fp.open("students.csv", ios::in);
    for(int i=0;i<158; i++){
        string s;
        getline(fp,s);
        stringstream temp(s);
        string word;
        vector<string>g;
        while(getline(temp,word,',')){
            g.pb(word);
        }
        name[g[1]]= g[0];
    }
    //string z = "students.csv";
    //const char* c = z.c_str();
    fp.close();
    /*for(auto y:name){
        cout<<y.ff<<" "<<y.ss<<"\n";
    }*/
    grade_values["AA"] = 10;
    grade_values["AS"] = 10;
    grade_values["AB"] = 9;
    grade_values["BB"] = 8;
    grade_values["BC"] = 7;
    grade_values["CC"] = 6;
    grade_values["CD"] = 5;
    grade_values["DD"] = 4;
    grade_values["F"] = 0;
    fp.open("courses.csv", ios::in);
    for(int i=0;i<63; i++){
        string s;
        getline(fp,s);
        stringstream temp(s);
        string word;
        vector<string>g;
        while(getline(temp,word,',')){
            g.pb(word);
        }
        struct courses semi;
        semi.semester = g[0];
        semi.names = g[2];
        semi.credits = string_to_int(g[6]);
        course_id[g[1]] = semi;
    }
    fp.close();
    //for(auto y: course_id){
    //    cout<<y.ff<<" "<<y.ss.semester<<" "<<y.ss.names<<" "<<y.ss.credits<<"\n";
    //}
    
    fp.open("grades.csv", ios::in);
    for(int i=0; i<9954; i++){
        string s;
        getline(fp,s);
        stringstream temp(s);
        string word;
        vector<string>g;
        while(getline(temp,word,',')){
            g.pb(word);
        }
        int dr = g[1].size();
        if(g[1][dr-1] == ' '){
           g[1].erase(dr-1,1);
        }
        string ds = course_id[g[1]].semester;
        roll_grades[g[0]].sem.pb({ds,{g[1],g[2]}});
    }
    fp.close();
    for(auto y:roll_grades){
        sort((y.ss).sem.begin(), (y.ss).sem.end());
    }
   /* for(auto y:roll_grades){
        cout<<y.ff<<"\n";
        for(auto i = 0; i < y.ss.sem.size(); i++){
            //cout<<y.ss.sem[i].ff<<" "<<y.ss.sem[i].ss.ff<<" "<<y.ss.sem[i].ss.ss<<"\n";
            cout<<y.ss.sem[i].ff<<"\n";
        }
    }*/
    for(auto y:name){
        fstream fptr;
        string d = y.ff;
        d+= ".txt";
        float spi[9];
        for(int i=0;i<9;i++){
            spi[i] = 0.0;
        }
        const char *c = d.c_str();
        fptr.open(c, ios::out | ios::app);
        fptr<<"Name: "<<y.ss<<"\n";
        fptr<<"Roll Number: "<<y.ff<<"\n";
        fptr<<"\n";
        fptr<<"Semester I\n";
        fptr<<"Course Number\t\t | Course Name\t\t | C\t\t | Grade\n";
        float sum = 0.0;
        float total_credits = 0.0;
        float sum_ar[9];
        float total_credits_ar[9];
        for(int i=0;i<9;i++){
            sum_ar[i] = 0.0;
            total_credits_ar[i]=0.0;
        }
        for(auto dr: roll_grades){
            if(dr.ff != y.ff){continue;}
            for(auto i=0; i<dr.ss.sem.size(); i++){
                if(dr.ss.sem[i].ff == "1"){
                    fptr<<dr.ss.sem[i].ss.ff<<"\t"<<course_id[dr.ss.sem[i].ss.ff].names<<"\t"<<course_id[dr.ss.sem[i].ss.ff].credits<<"\t"<<dr.ss.sem[i].ss.ss<<"\n";
                    sum += (float)(course_id[dr.ss.sem[i].ss.ff].credits)*(grade_values[dr.ss.sem[i].ss.ss]);
                    total_credits += course_id[dr.ss.sem[i].ss.ff].credits;
                }
            }
        }
        sum_ar[1]=sum;
        total_credits_ar[1]=total_credits;
        spi[1] = sum/total_credits;
        sum = 0.0;
        total_credits = 0.0;
        fptr<<"\n";
        fptr<<"Semester II\n";
        fptr<<"Course Number | Course Name | C | Grade\n";
        for(auto dr: roll_grades[y.ff].sem){
            if(dr.ff == "2"){
                fptr<<dr.ss.ff<<"\t"<<course_id[dr.ss.ff].names<<"\t"<<course_id[dr.ss.ff].credits<<"\t"<<dr.ss.ss<<"\n";
                 sum += (float)(course_id[dr.ss.ff].credits)*(grade_values[dr.ss.ss]);
                total_credits += course_id[dr.ss.ff].credits;
            }
        }
        sum_ar[2]=sum;
        total_credits_ar[2]=total_credits;
        spi[2] = sum/total_credits;
        sum = 0.0;
        total_credits = 0.0;
        fptr<<"\n";
        fptr<<"Semester III\n";
        fptr<<"Course Number | Course Name | C | Grade\n";
        for(auto dr: roll_grades[y.ff].sem){
            if(dr.ff == "3"){
                fptr<<dr.ss.ff<<"\t"<<course_id[dr.ss.ff].names<<"\t"<<course_id[dr.ss.ff].credits<<"\t"<<dr.ss.ss<<"\n";
                 sum += (float)(course_id[dr.ss.ff].credits)*(grade_values[dr.ss.ss]);
                total_credits += course_id[dr.ss.ff].credits;
            }
        }
        sum_ar[3]=sum;
        total_credits_ar[3]=total_credits;
        spi[3] = sum/total_credits;
        sum = 0.0;
        total_credits = 0.0;
        fptr<<"\n";
        fptr<<"Semester IV\n";
        fptr<<"Course Number | Course Name | C | Grade\n";
        for(auto dr: roll_grades[y.ff].sem){
            if(dr.ff == "4"){
                fptr<<dr.ss.ff<<"\t"<<course_id[dr.ss.ff].names<<"\t"<<course_id[dr.ss.ff].credits<<"\t"<<dr.ss.ss<<"\n";
                 sum += (float)(course_id[dr.ss.ff].credits)*(grade_values[dr.ss.ss]);
                total_credits += course_id[dr.ss.ff].credits;
            }
        }
        sum_ar[4]=sum;
        total_credits_ar[4]=total_credits;
        spi[4] = sum/total_credits;
        sum = 0.0;
        total_credits = 0.0;
        fptr<<"\n";
        fptr<<"Semester V\n";
        fptr<<"Course Number | Course Name | C | Grade\n";
        for(auto dr: roll_grades[y.ff].sem){
            if(dr.ff == "5"){
                fptr<<dr.ss.ff<<"\t"<<course_id[dr.ss.ff].names<<"\t"<<course_id[dr.ss.ff].credits<<"\t"<<dr.ss.ss<<"\n";
                 sum += (float)(course_id[dr.ss.ff].credits)*(grade_values[dr.ss.ss]);
                total_credits += course_id[dr.ss.ff].credits;
            }
        }
        sum_ar[5]=sum;
        total_credits_ar[5]=total_credits;
        spi[5] = sum/total_credits;
        sum = 0.0;
        total_credits = 0.0;
        fptr<<"\n";
        fptr<<"Semester VI\n";
        fptr<<"Course Number | Course Name | C | Grade\n";
        for(auto dr: roll_grades[y.ff].sem){
            if(dr.ff == "6"){
                fptr<<dr.ss.ff<<"\t"<<course_id[dr.ss.ff].names<<"\t"<<course_id[dr.ss.ff].credits<<"\t"<<dr.ss.ss<<"\n";
                 sum += (float)(course_id[dr.ss.ff].credits)*(grade_values[dr.ss.ss]);
                total_credits += course_id[dr.ss.ff].credits;
            }
        }
        sum_ar[6]=sum;
        total_credits_ar[6]=total_credits;
        spi[6] = sum/total_credits;
        sum = 0.0;
        total_credits = 0.0;
        fptr<<"\n";
        fptr<<"Semester VII\n";
        fptr<<"Course Number | Course Name | C | Grade\n";
        for(auto dr: roll_grades[y.ff].sem){
            if(dr.ff == "7"){
                fptr<<dr.ss.ff<<"\t"<<course_id[dr.ss.ff].names<<"\t"<<course_id[dr.ss.ff].credits<<"\t"<<dr.ss.ss<<"\n";
                 sum += (float)(course_id[dr.ss.ff].credits)*(grade_values[dr.ss.ss]);
                total_credits += course_id[dr.ss.ff].credits;
            }
        }
        sum_ar[7]=sum;
        total_credits_ar[7]=total_credits;
        spi[7] = sum/total_credits;
        sum = 0.0;
        total_credits = 0.0;
        fptr<<"\n";
        fptr<<"Semester VIII\n";
        fptr<<"Course Number | Course Name | C | Grade\n";
        for(auto dr: roll_grades[y.ff].sem){
            if(dr.ff == "8"){
                fptr<<dr.ss.ff<<"\t"<<course_id[dr.ss.ff].names<<"\t"<<course_id[dr.ss.ff].credits<<"\t"<<dr.ss.ss<<"\n";
                 sum += (float)(course_id[dr.ss.ff].credits)*(grade_values[dr.ss.ss]);
                total_credits += course_id[dr.ss.ff].credits;
            }
        }
        sum_ar[8]=sum;
        total_credits_ar[8]=total_credits;
        spi[8] = sum/total_credits;
        sum = 0.0;
        total_credits = 0.0;
        fptr<<"\n";
        fptr<<"\t\t\tI\tII\tIII\tIV\tV\tVI\tVII\tVIII\n";
        fptr<<"SPI\t"<<spi[1]<<"\t"<<spi[2]<<"\t"<<spi[3]<<"\t"<<spi[4]<<"\t"<<spi[5]<<"\t"<<spi[6]<<"\t"<<spi[7]<<"\t"<<spi[8]<<"\n";
        fptr<<"CPI\t";
        for(int i=1;i<9;i++){
            float t1=0.0, t2=0.0;
            for(int j = 1; j<i+1; j++){
                t1 += sum_ar[j];
                t2+=total_credits_ar[j];
            }
            fptr<<t1/t2<<"\t";
        }
        fptr.close();
    }
}