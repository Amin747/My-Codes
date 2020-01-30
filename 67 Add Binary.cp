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


string addBinary(string a, string b){
    int alen = a.length()-1;
    int blen = b.length()-1;
    int anslen =max(alen, blen);
    string answer(anslen+1,' ');
    int carry = 0;
    if (alen > blen){
        while (blen!=alen){
            b = '0' + b;
            blen++;
        }
    }
    if (blen > alen){
        while (alen!=blen){
            a = '0' + a;
            alen ++;
        }
    }
    while (alen >=0 || blen>=0){
        if (a[alen]-'0'+b[blen]-'0'+carry==2){
            answer[anslen] = '0';
            carry = 1;
            alen--;
            blen--;
            anslen--;
            continue;
        }
        if (a[alen]-'0'+b[blen]-'0'+carry==3){
            answer[anslen] = '1';
            carry = 1;
            alen--;
            blen--;
            anslen--;
            continue;
        }
        if (a[alen]-'0'+b[blen]-'0'+carry==1){
            answer[anslen] = '1';
            carry = 0;
            alen--;
            blen--;
            anslen--;
            continue;
        }
        if (a[alen]-'0'+b[blen]-'0'+carry==0){
            answer[anslen] = '0';
            carry = 0;
            alen--;
            blen--;
            anslen--;
            continue;
        }
    }
    if (alen==-1 && blen==-1 && carry==1){
        answer = '1'+answer;
    }
    return answer;
}



int main(){
    string one =  "1010";
    string two = "1011";
    string answer = addBinary(one, two);
    for (int i=0; i<answer.length(); i++){
        cout << answer[i] << " ";
    }
}
