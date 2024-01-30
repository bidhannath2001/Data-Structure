
/* sum of elements of a certain range, value update*/

/***--- ॐ नमः शिवाय ---***/
 
#include <bits/stdc++.h>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#define read(type) readInt<type>()
#define front(i,a,n) for(ll i=a;i<=n;i++)
#define back(i,a,n) for(ll i=n;i>=a;i--)
#define nL "\n"
#define ll long long int
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<long long>
#define vs vector<string>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
#define mx 100001
int a[mx];
int tree[mx*3];

void init(int node, int b, int e){
    if(b==e){
        tree[node]=a[b];
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node] = tree[left] + tree[right];
}

int query(int node, int b, int e, int i, int j){
    if(i>e || j<b){
        return 0;
    }
    if(b>=i && e<=j){
        return tree[node];
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    int p1 = query(left,b,mid,i,j);
    int p2 = query(right,mid+1,e,i,j);
    return p1+p2;
}

void update(int node, int b, int e, int i, int newValue){
    if(i>e || i<b){
        return;
    }
    if(b>=i && e<=i){
        tree[node]= newValue;
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    update(left,b,mid,i,newValue);
    update(right,mid+1,e,i,newValue);
    tree[node] = tree[left]+tree[right];
}
int main ()
{
    fast;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    init(1,1,n);
    cout<<query(1,1,n,1,3)<<endl;
    update(1,1,n,2,0);
    cout<<query(1,1,n,1,3)<<endl;
    update(1,1,n,2,2);
    cout<<query(1,1,n,2,2)<<endl;
    return 0;
}