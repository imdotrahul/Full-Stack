#include <iostream>
#include<algorithm>
#include<math.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int  Testcase;
	cin>>Testcase;
	while(Testcase--){
	    ll int Nope;
	    cin>> Nope;
	    string sope;
	    cin>>sope;
	    string mom = "mom",dad = "dad";
	    int mope = 0 , dope = 0;
	    for(ll int i = 0;i<Nope;i++){
	        char c = sope[i];
	        if(c==mom[mope]){
	            mope++;
	            if(mope>2){
	                cout<<"Mom"<<"\n";
	                break;
	            }
	        }
	        else if(c == dad[dope]){
	            dope++;
	            if(dope>2){
	                cout<<"Dad"<<"\n";
	                break;
	            }
	        }
	    }
	    if(mope<=2 && dope<=2) 
	    {
	        cout<<"Goo-Goo"<<"\n";
	    }
	}
	return 0;
}
