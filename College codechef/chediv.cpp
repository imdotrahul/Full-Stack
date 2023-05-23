#include <iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
	int testcases;
	cin>>testcases;
	while(testcases--){
	    
	    int n;
    	cin>>n;
    	int arr[n];
    	int x,y;
    	cin>>x>>y;
    	for(int i = 0; i<n;i++)
    	{
    	    cin>>arr[i];
    	}

    	int count = 0;
    	for(int i =0;i<n;i++)
    	{
    	    if(arr[i]<=x)
    	    {
    	        if(arr[i]%y==0)
    	        {
    	            count++;
    	        }
    	    }
    	    
    	}
    	cout<<count<<"\n";
	}
	return 0;
}
