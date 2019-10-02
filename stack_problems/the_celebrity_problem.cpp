//Problem-You are in a party of N people, where only one person is known to everyone. 
//Such a person may be present in the party, if yes, (s)he doesn’t know anyone in the party. 
//Your task is to find the stranger (celebrity) in party.
//You will be given a square matrix M[][] where if an element of row i and column j  is
//set to 1 it means ith person knows jth person.
//You need to complete the function getId() which finds the id of the celebrity 
//if present else return -1. The function getId() 
//takes two arguments, the square matrix M and its size N.

//SOLUTION
#include<bits/stdc++.h>
using namespace std;
#define MAX 501
int getId(int M[MAX][MAX],int n);
int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    while(T--)
    {
        int N;
        cin>>N;
        memset(M,0,sizeof M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<getId(M,N)<<endl;
    }
}



int getId(int M[MAX][MAX], int n)
{
    stack<int>s;
    for(int i=0;i<n;i++){
        s.push(i);
    }
    while(s.size()>1){
        int A=s.top();
        s.pop();
        int B=s.top();
        s.pop();
        if(M[A][B]==1){
            s.push(B);
        }
        else{
            s.push(A);
        }
    }
    int C=s.top();
    s.pop();
    for(int i=0;i<n;i++){
        if((M[C][i]==1||M[i][C]==0)&&i!=C){
            return -1;
        }
    }
    
    return C;
    
}
