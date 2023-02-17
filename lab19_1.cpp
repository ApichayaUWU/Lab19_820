#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string fname, vector<string> &name, vector<int> &score, vector<char> &grade){

    ifstream f(fname);
    int i= 0 ,a ,b ,c ;
    char n[50];
    char text[100];
    char format[] = "%[^:]: %d %d %d";
    while(f.getline(text,100))
    {
        sscanf(text,format,n,&a,&b,&c);
        name.push_back(n) ;
        score.push_back(a+b+c);
        grade.push_back(score2grade(a+b+c));

        i++;
    }
}

void getCommand(string &command, string &key){
    string line;
    cout << "Please input your command: " ;
    getline(cin,line);
    int idx=line.find_first_of(" ");
    command = line.substr(0,idx);
    key = line.substr(idx+1,line.size()-idx-1);
}

void searchName(vector<string> &name, vector<int> &score, vector<char> &grade, string key){
    cout << "---------------------------------" << endl;
    bool _check = false;
    int l = name.size();
    for(int i =0 ; i < l ; i++)
    {
            

        if(key.compare(toUpperStr(name[i]))==0) 
        {
            
            cout << name[i] << "'s score = " << score[i] << endl;
            cout << name[i] << "'s grade = " << grade[i] << endl;
            _check = true;
           

        }
         
    }
    if(_check == false)
         {
            
             cout << "Cannot found." << endl;
             
         }
    cout << "---------------------------------" << endl;
}

void searchGrade(vector<string> &name, vector<int> &score, vector<char> &grade, string key){
    cout << "---------------------------------" << endl;
    bool _check = false;
    int l = name.size();
    string g;
    for(int i =0 ; i < l ; i++)
    {
        g = grade[i];
        if(key == g)
        {
            
            cout << name[i] << " (" << score[i] << ")" <<endl;
            _check = true;

        }
        
    }
    if(_check == false)
         {
            
             cout << "Cannot found." << endl;
             
         }
    cout << "---------------------------------" << endl;
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
