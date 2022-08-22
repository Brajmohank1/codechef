/*

problem link - https://www.codechef.com/submit/FLIPFAIL

problem statement -

Chef has a binary string SS with him and he wants to modify it using the following two types of operations -

Type 1 : Choose any two indices ii and jj such that 1 \leq i, j \leq |S|1≤i,j≤∣S∣ and swap S_iS 
i
​
  and S_jS 
j
​
 . This operation costs 11 rupee and can be performed any number of times.
Type 2 : Choose any prefix of length ii, where 1 \leq i \leq |S|1≤i≤∣S∣, and reverse this prefix of the binary string. This operation is free of cost and can be performed at most once.
Chef wants to obtain the lexicographically smallest string. Can you help him find the minimum cost to obtain the lexicographically smallest string?

Note:

|S|∣S∣ denotes the length of the string SS.
A string AA is lexicographically smaller than string BB, if A_i \lt B_iA 
i
​
 <B 
i
​
 , where ii is the first index where AA and BB differ.
Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case consists of a single line of input denoting SS, the original string.
Output Format
For each test case, output the minimum cost to obtain the lexicographically minimal string.

 


*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("inp1.in", "r", stdin);
    //freopen("inp1.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
      
      int n = s.size();
      int count0 = 0 , countx0 = 0;
      for(int i = 0 ; i < n ; i++) count0 += (s[i] == '0');
      
      for(int i = 0 ; i < count0 ; i++) countx0 += (s[i] == '0');
      
      int ans = count0 - countx0;
      for(int i = count0 ; i < n ; i++){
          
          countx0 -= (s[i-count0] == '0');
          countx0 += (s[i] == '0');
          
          ans = min(ans , count0 - countx0);
      }
      std::cout << ans << std::endl;
    }
}
  
  
