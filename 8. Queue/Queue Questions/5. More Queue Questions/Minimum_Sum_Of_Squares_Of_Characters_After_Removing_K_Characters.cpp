#include<bits/stdc++.h>
using namespace std;
/*

Time Complexity = O(n + k * c)
Space Complexity = O(1)

*/
int minSumSquares(string str, int k){
    int minSum = 0;
   // calculating the frequency of every character in a original string.
    vector<int> frequency(26, 0);
    for (int i = 0; i < str.length(); i++)
    {
        frequency[str[i] - 'a']++;
    }

    // now sort the array in decreasing order.
    sort(frequency.begin(), frequency.end(), greater<int>());

    // run a loop k time, and remove character with maximum frequency.
    while(k--){
        // as we know frequency array is sorted in decreasing order, so the character with maximum frequency in always present at index 0.
        frequency[0]--;

        // now again sort the array in decreasing order.
        sort(frequency.begin(), frequency.end(), greater<int>());
    } 

    // calculate minimum sum.
    for (int i = 0; i < frequency.size(); i++)
    {
        minSum += pow(frequency[i],2);
    }

    return minSum;
    
    
}

int main(){
    string str = "aabcbcbcabcc";
    int k = 3;
    cout<<minSumSquares(str, k)<<endl;

}