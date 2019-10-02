//Program to evaluate postfix expression
#include<bits/stdc++.h>
using namespace std;
int isOperator(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/')
       return 1;
    else
       return 0;
}
int main() {
	int T;//Number of expressions you want to evaluate
	int R=0,result;
	cin>>T;
	for(int i=0;i<T;i++){
	    string s;
	    cin>>s;
	    vector<char>sp;
	    for(int j=0;s[j]!='\0';j++){
	    	
	        if(isOperator(s[j])){
	           int r=(int)sp.back();
	           sp.pop_back();
	           int l=(int)sp.back();
	           sp.pop_back();
	           switch(s[j]){
	               case '+':R=l+r;
				        break;
	               case '-':R=l-r;
				   break;
	               case '*':R=l*r;
				   break;
	               case '/':R=l/r;
				   break;
	               
	           }
	           sp.push_back(R);
	           
	        }
	        else{
	            sp.push_back(s[j]-'0');
	        }
	    }
	    result=sp.back();
	    cout<<result<<"\n";
	}
	return 0;
}

//example 
//Input:
//2
//231*+9-
//123+*8-
//Output:
//-4
//-3
