#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
//Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
//
//The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
//
//You may assume the integer does not contain any leading zero, except the number 0 itself.
//
//Example 1:
//
//Input: [1,2,3]
//Output: [1,2,4]
//Explanation: The array represents the integer 123.
//Example 2:
//
//Input: [4,3,2,1]
//Output: [4,3,2,2]
//Explanation: The array represents the integer 4321.



vector<int> plusOne(vector<int>& digits){
        int last = digits.size()-1;
        if (digits[last]!=9){
            digits[last]++;
            return digits;
        }
        else {
            digits[last] = 0;
            int carry = 1;
            int prev = last-1;
            while (prev >= -1){
                if (prev == -1 && carry == 1){
                    digits.insert(digits.begin(), 1);
                    return digits;
                }
                if (digits[prev]+carry==10 && prev!=-1){
                    digits[prev] = 0;
                    carry=1;
                }
                else {
                    digits[prev]+=carry;
                    return digits;
                }
                    prev--;
            }
        return digits;
        }
}
int main(){
    vector<int>digits = {8,9,9,9};
    plusOne(digits);
    for (int i=0; i<digits.size(); i++){
        cout << digits[i] << " ";
    }
}
