#include <iostream>
#include<algorithm>
#include<math.h>
#include<cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n],count = 0;
	    for(int i = 0; i<n; i++)
	    {
	        cin>>arr[i];

	    }
	    
	    int maxi = *max_element(arr,arr+n);
	    for(int i = 0;i<n;i++)
	    {
	        if(arr[i]==maxi)
	        {
	            count++;
	            
	        }
	    }
	    if(count>=2)
	    {
	        cout<<"fight:("<<"\n";
	    }
	    else
	    {
	        cout<<"peace:)"<<"\n";
	    }
	}
	return 0;
}
