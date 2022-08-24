/*
problem link - https://www.codechef.com/submit/TREECLR?tab=statement

problem statement - 


Problem
Given a tree containing NN nodes.

Each node can be coloured using exactly one of the CC colours. Find the number of colourings of the tree such that:

All nodes in a path of length at most two have distinct colours.
As the answer can be huge, print it modulo (10 ^ 9 + 7)(10 
9
 +7).

Note:

Two colourings of a tree are different if there exists at least one node having different colours in both the colourings.
A path in a tree is a sequence of (zero or more) connected nodes.
The path length between two nodes is defined as the total number of edges in the shortest path from one node to other.
Input Format
The first line of the input will contain two integers NN and CC, the number of nodes in the tree and the number of colours available respectively.
The next (N - 1)(N−1) lines will describe the given tree. Each line contains two integers UU and VV meaning that there is an edge between node UU and node VV.
Output Format
Output the number of ways to colour the tree satisfying the given condition, modulo 10^9 + 710 
9
 +7.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

	ll ans = 1 , mod = 1e9+7;
	
	 ll n ,c;
	
	void dfs(vector<vector<int>> &tree , ll u , ll p , ll colored){
	    
	   
	    
	     ans = (ans*(c-colored ))%mod;
	      int  color  = 1 +  (p != -1);
	     
	  
	     
	    for(ll i = 0 ; i < tree[u].size() ; i++){
	        
	       //  std::cout << u << " " << ans << std::endl;
	         if(tree[u][i] != p  ){
	             
	               
	         dfs(tree  , tree[u][i] , u ,  color);
	         color++;
	         }
	    }
	}
	 
int main() {
	// your code goes here
	
	ll t = 1;
	 
	
 
	while(t--){
	    
	     
	    
	    cin>>n>>c;
	    vector<vector<int>> tree(n+1);
	    for(int i = 0 ; i < n - 1 ; i++){
	        int u,v;
	        cin>>u>>v;
	        tree[u].push_back(v);
	        tree[v].push_back(u);
	    }
	    
	    dfs(tree , 1, -1 ,0);
	   
	  
	  
	   std::cout << ans%mod << std::endl;
	}
	return 0;
}
