#include <iostream>
#include<algorithm>
#include<math.h>
#define ll long long
using namespace std;


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll int Testcase = 0;
	cin>>Testcase;
	while(Testcase--){
	    ll int Nope , Qope;
	    cin>>Nope>>Qope;
	    ll int summ = 0 , mmodee = -1 , occur = 0 , neam;
	    vector<ll int> visit(1e5 + 1,0);
	    for(ll int i = 0;i<Nope;i++){
	        ll int temperary ;
	        cin>>temperary;
	        summ += temperary;
	        visit[temperary]++;
	        if(visit[temperary] > occur){
	            mmodee = temperary;
	            occur = visit[temperary];
	        }
	        else if(visit[temperary] == occur){
	            mmodee = min(mmodee,temperary);
	        }
	    }
	    neam = summ / Nope;
	    while(Qope--){
	        ll int type;
	        cin>>type;
	        if(type == 1){
	            ll int X;
	            cin>>X;
	            summ += X;
	            Nope++;
	            neam = summ / Nope; 
	            visit[X]++;
    	        if(visit[X] > occur){
    	            mmodee = X;
    	            occur = visit[X];
    	        }
    	        else if(visit[X] == occur){
    	            mmodee = min(mmodee,X);
    	        }
	        }
	        else if(type == 2){
                cout<<neam<<endl;	            
	        }
	        else if(type == 3){
	            cout<<mmodee<<endl;
	        }
	    }
	}
	return 0;
}
