#include<iostream>
#include<stack>
using namespace std;

bool isValidParenthesis(string str){
    stack<char> s;

    for(int i=0;i<str.length();i++){
        char ch = str[i] ;

        //if opening brackets then push:
        if(ch == '(' || ch == '[' || ch == '{'){
            s.push(ch);
        }
        //closing brackets then check top and pop
        else{
            if(!s.empty()){  //when stack is not empty.
                char top = s.top();
                if( (ch ==')' && top == '(') || (ch =='}' && top == '{') || (ch ==']' && top == '[') ){
                    s.pop();
                }else{
                    return false;
                }
            }
            //is stack is empty..
            else{
               return false;
            }
        }
    }

    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    string str ="[({})]";
    if(isValidParenthesis(str)){
        cout<<"Balanced Parenthesis."<<endl;
    }
    else{
        cout<<"Unbalanced Parenthesis."<<endl;
    }
    return 0;
}
