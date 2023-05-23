#include <iostream>
#include<stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin>>q;
    stack<string>A;
    stack<string>B;
    while(q!=0)
    {
        int n ;
        cin>>n;
        if(n==1)
        {
            string s;
            cin>>s;
            A.push(s);
        }
        if(n==2)
        {
            int k;
            cin>>k;
            while((A.size()!=0) && k!=0)
            {
                string h = A.top();
                A.pop();
                B.push(h);
                k--;
            }
        }
        if(n==3)
        {
            int l;
            cin>>l;
            while((B.size()!=0) && l!=0)
            {
                string j = B.top();
                B.pop();
                A.push(j);
                l--;
            }
        }
        if(!A.empty())cout<<A.top()<<endl;
        else
        {
            cout<<"Nil"<<endl;
        }
        q--;
    }
	// your code goes here
	return 0;
}