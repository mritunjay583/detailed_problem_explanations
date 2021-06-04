
// https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/uniformity-794d7bdc/
#include <bits/stdc++.h>
using namespace std;

int solve(char s[],int n,int k){
    int l = 0;
    int r = -1;
    int ans = 0;
    vector<int> temp(3);
    int cnt_a=0,cnt_b=0,cnt_c=0;
    while(l<n){
        while(r<n-1){
            r++;

            if(s[r]=='a')cnt_a++;
            else if(s[r]=='b')cnt_b++;
            else cnt_c++;

            temp[0]=cnt_a;
            temp[1]=cnt_b;
            temp[2]=cnt_c;
            sort(temp.begin(),temp.end());
            int reqiuredChange = temp[0]+temp[1];
            if(reqiuredChange>k){
                break;
            }
            ans=max(ans,cnt_a+cnt_b+cnt_c);
        }
        if(s[l]=='a')cnt_a--;
        else if(s[l]=='b')cnt_b--;
        else cnt_c--;
        l++;
    }
    return ans;
}

int main() {
    int n,k;
    cin>>n>>k;
    char s[n];
    cin>>s;
    cout<<solve(s,n,k);
	return 0;
}