//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int N, int k)
    {
        int sum = 0;
        unordered_map<int, int> mmap;
        int len = 0;

        for(int i = 0; i < N; i++) {
            sum += arr[i];

            if(sum == k) len = max(len, i + 1);

            if(mmap.find(sum - k) != mmap.end()) {
                len = max(len, i - mmap[sum-k]);
            }

            if(mmap.find(sum) == mmap.end())
                mmap[sum] = i;

        }

        return len;


    }

};

//{ Driver Code Starts.

int main() {
	//code

	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];

	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;

	}

	return 0;
}
// } Driver Code Ends