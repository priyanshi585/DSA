#include<iostream>
#include<stack>
using namespace std;

bool findRedundantBrackets(string &str){
    stack<char> s;
    for(int i=0;i<str.length();i++){  
        char ch = str[i];
        
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            s.push(ch);
        }  
        else{
            if(ch == ')' ){
              bool isRedundant = true;
              while(s.top() != '(' ){
                char top = s.top();

                if(top == '+' || top == '-' || top == '*' || top == '/' ){
                    isRedundant = false;
                }
                s.pop();
              }
              s.pop();
              if(isRedundant == true){
                return true;
              }
            }
        }
    }
    return false;
}

int main()
{
    string str = "(a+(b*c))" ;
    if(findRedundantBrackets(str)){
        cout<<"String has Redundant Brackets."<<endl;
    }
    else{
        cout<<"String has NO redundant brackets."<<endl;
    }
    return 0;
}
