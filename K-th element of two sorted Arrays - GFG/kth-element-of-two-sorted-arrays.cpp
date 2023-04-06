//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int v1[], int v2[], int n, int m, int k){
        int t=0;
        int i=0,j=0;
      while(i<n && j<m){
        if(v1[i]<v2[j]){
            t++;
            i++;
            if(t==k) return v1[i-1];
        }
        else{
          t++;
          j++;
          if(t==k) return v2[j-1];
        }
      }
    
        while(i<n){
           t++;
           i++;
           if(t==k) return v1[i-1];
        }

        while(j<m){
              t++;
              j++;
              if(t==k) return v2[j-1];
        }
        return 0;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends