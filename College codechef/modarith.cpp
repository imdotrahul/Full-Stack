
#include <iostream>
#include<algorithm>
#include<math.h>
#define ll long long
#define vi vector
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll int Nope , Mope , Qope , count = 0;
	cin>>Nope>>Mope;
	vi<ll int>vta(Nope,0);
	vi<ll int>mod(Mope,0);
	for(ll int i = 0;i<Nope;i++){
	    cin>>vta[i];
	    mod[vta[i] % Mope]++;
	}
    cin>>Qope;
    while(Qope--){
        ll int type;
        cin>>type;
        if(type == 1){
            ll int i ,val;
            cin>>i>>val;
            mod[vta[i - 1] % Mope]--; 
            vta[i - 1] = val;
            mod[vta[i - 1] % Mope]++;
        }
        else if(type == 2){
            ll int Xope;
            cin>>Xope;
            cout<<mod[Xope]<<"\n";
        }
    }
	return 0;
}
