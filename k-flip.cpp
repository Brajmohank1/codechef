/*

problem link - https://www.codechef.com/submit/KLIP


problem statement :

You are given a binary string S = S_1S_2 \ldots S_NS=S 
1
​
 S 
2
​
 …S 
N
​
  of length NN. You are also given an integer KK. You can do the following operation at most N-K+1N−K+1 times:

First, choose a substring S_iS_{i+1} \ldots S_{i+K-1}S 
i
​
 S 
i+1
​
 …S 
i+K−1
​
  of SS of length exactly KK. This substring shouldn't have been chosen in any of the previous operations. That is, the same starting index of the substring can't be chosen twice.
Then, flip all the characters of the chosen substring (i.e. change every 00 to 11 and vice versa).
Find the lexicographically smallest string possible after the operations if you do them in an optimal way.

Note:

A substring is consecutive elements of a string. For eg. in the string "01011", "101" is a substring, but "111" is not a substring.
A string AA is lexicographically smaller than string BB, if A_i \lt B_iA 
i
​
 <B 
i
​
 , where ii is the first index where AA and BB differ.
Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
The first line of each test case contains two space-separated integers: NN, KK.
The second line of each test case contains the string SS.
Output Format
For each test case, output on a new line the lexicographically smallest string that you can achieve.

Constraints
1 \leq T \leq 1001≤T≤100
1 \leq N \leq 10^51≤N≤10 
5
 
1 \leq K \leq N1≤K≤N
Each element of SS is either 00 or 11
The sum of NN over all test cases won't exceed 3 \times 10^53×10 
5
 .
Subtasks
Subtask 1 (10 points): 1 \leq M \leq 101≤M≤10
Subtask 2 (20 points): The sum of NN across all test cases won't exceed 2020.
Subtask 3 (70 points): No further constraints.
Sample 1:
Input
Output
4
3 2
101
4 2
1011
5 3
01010
5 2
01010
000
0001
00011
00000



*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	// your code goes here
	
	ll t;
	std::cin >> t;
	
	while(t--){
	    ll n,k;
	    cin>>n>>k;
	    
	    string str;
	    std::cin >> str;
	    
	    std::queue<int> q ;
	    
	    for(int i = 0 ; i <= n - k; i++){
	         
	        
	        while(!q.empty() && q.front() <= i -k) q.pop();
	        int s1 = q.size();
	        if(str[i] == '0'  ){
	            
	            if(s1%2 == 1) q.push(i);
	        }
	        else if(str[i] == '1' ){
	            
	            if(s1%2 == 0) q.push(i);
	        }
	    }
	    string res = "";
	    for(int i = 0 ; i <=n-k ; i++){
	        res += '0';
	}
	
	for(int i = n - k + 1 ; i < n ; i++){
	    if(!q.empty() && q.front() < i -k + 1) q.pop();
	    
	    int s1 = q.size();
	    
	    if(str[i] == '1' ){
	        if(s1%2 == 1) res += '0';
	        else  res += '1';
	    }else{
	        if(s1 % 2 == 0) res += '0';
	        else res += '1';
	    }
	    
	}
	
	    
	    std::cout << res << std::endl;
	}
	
	return 0;
}
