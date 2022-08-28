//
// Created by PayThePizzo on 8/27/2022.
//

#include "iostream"
#include "string"
#include <bits/stdc++.h>

using namespace std;

// Function to print a substring
// str[low..high]
void printSubStr(
        string str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        cout << str[i];
}

// This function prints the
// longest palindrome substring
// It also returns the length of
// the longest palindrome
int longestPalSubstr(string str)
{
    // get length of input string
    int n = str.size();

    // table[i][j] will be false if substring
    // str[i..j] is not palindrome.
    // Else table[i][j] will be true
    bool table[n][n];

    memset(table, 0, sizeof(table));

    // All substrings of length 1
    // are palindromes
    int maxLength = 1;

    for (int i = 0; i < n; ++i)
        table[i][i] = true;

    // check for sub-string of length 2.
    int start = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (str[i] == str[i + 1]) {
            table[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    // Check for lengths greater than 2.
    // k is length of substring
    for (int k = 3; k <= n; ++k) {
        // Fix the starting index
        for (int i = 0; i < n - k + 1; ++i) {
            // Get the ending index of substring from
            // starting index i and length k
            int j = i + k - 1;

            // checking for sub-string from ith index to
            // jth index iff str[i+1] to str[j-1] is a
            // palindrome
            if (table[i + 1][j - 1] && str[i] == str[j]) {
                table[i][j] = true;

                if (k > maxLength) {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }

    cout << "Longest palindrome substring is: ";
    printSubStr(str, start, start + maxLength - 1);

    // return length of LPS
    return maxLength;
}



int max_lps_aux(string const str, int i, int j, int maxlength, int **len){
    if((*(*len+i)+j)==0){
    //Not Already computed
        if(str[i]==str[j]){

        }else{

        }
        (*(*len+i)+j) =
        return
    }else{
        return (*(*len+i)+j);
    }
}

int longest_palindrome_substring_td(std::string const str){
    //Array initialization O(n^2)
    if(str.size()>=0){

        int table[str.size()][str.size()];
        for(int i = 0; i<str.size(); i++){
            for(int j = 0; j<str.size(); i++){
                if(i==j){
                    table[i][j] = 1;
                    max_length = table[i][j];
                }else if(str[i]==str[i+1]){
                    table[i][j] = 2;
                    max_length = table[i][j];
                }else{
                    table[i][j] = 0;
                }
            }
        }

        return max_lps_aux(str, 0, str.size(), max_length, &table[0][0]);
    }
    return 0;
}


int main(){
    string str = "forgeeksskeegfor";
    cout << "\nLength is: "
         << longestPalSubstr(str);
    return 0;
}