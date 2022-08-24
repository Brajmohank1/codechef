/*
problem link - https://www.codechef.com/submit/SUB12OP




You are given NN integers A_1, A_2, \ldots, A_NA 
1
​
 ,A 
2
​
 ,…,A 
N
​
 .

You can perform the following operation any number of times:

Select any index ii such that 1 \le i \le (N-1)1≤i≤(N−1);
Subtract 11 from A_iA 
i
​
  and 22 from A_{i+1}A 
i+1
​
 .
Find the smallest possible value of |A_1| + |A_2| + \ldots + |A_N|∣A 
1
​
 ∣+∣A 
2
​
 ∣+…+∣A 
N
​
 ∣ you can achieve after performing any number of given operations.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains a single integer NN — the number of integers.
The second line of each test case contains NN integers A_1, A_2, \ldots, A_NA 
1
​
 ,A 
2
​
 ,…,A 
N
​
 .
Output Format
For each test case, output a single integer — the smallest possible value of |A_1| + |A_2| + \ldots + |A_N|∣A 
1
​
 ∣+∣A 
2
​
 ∣+…+∣A 
N
​
 ∣ you can achieve after performing any number of given operations.



*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	// your code goes here
	
	ll t;
	std::cin >> t;
	
	while(t--){
	  ll n;
	  std::cin >> n;
	  
	  std::vector<ll> arr(n) ;
	  
	  for(int i = 0 ; i < n ; i++) cin>>arr[i];
	  
	  for(int i = n - 1 ; i > 0 ; i--){
	      if(arr[i] == 1 && arr[i - 1] <= 0 || arr[i] <= 0) continue;
	      else{
	          int d = arr[i]/2;
	          arr[i] = arr[i] % 2;
	          arr[i - 1] -= d;
	          
	       //   if(arr[i -1] > 0 &&arr[i] == 1){
	       //       arr[i-1] -= 1;
	       //       arr[i] = -1;
	       //   }
	      }
	  }
	  
	  for(int i = n - 1 ; i > 0 ; i--){
	      if(arr[i -1] > 0 &&arr[i] == 1){
	              arr[i-1] -= 1;
	              arr[i] = -1;
	          }
	  }
	  
	  ll ans = 0;
	  for(int i = 0 ; i < n ; i++)
	        ans += abs(arr[i]);
	        
	   std::cout << ans << std::endl;
	   
	}
	return 0;
}
