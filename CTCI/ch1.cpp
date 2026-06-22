#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <bitset>

// 1.1 make an algo to find char dups in a string

bool strHasDupes(std::string str){
    std::bitset<256> dupes;
    for (const char& c : str){
        if (dupes[c]) return true;
        dupes[c] = 1;
    }
    return false;
}

// 1.2 check 2 strings to see if one permutes other

bool isPermutation(std::string str1, std::string str2){
    if (str1.size() != str2.size()) return false;
    std::vector<int> cntr1(256);
    for (const char& c : str1)
        ++cntr1[c];
    std::vector<int> cntr2(256);
    for (const char& c : str2)
        ++cntr2[c];
    for(int i{}; i < 256; ++i)
        if (cntr1[i] != cntr2[i]) return false;
    return true; 
}  

// 1.3 replace all spaces in a url with "%20"
// incredibly suboptimal but learnt a lot about string utils

std::string urlIfy(std::string str){
    std::string ret{str};
    size_t sz{};
    while ((sz = ret.find_first_of(' ')) != std::string::npos){
        size_t i{sz};
        while (ret[i] == ' ')
            ++i;
        ret.replace(sz, i - sz, "%20");
    }
    return ret;
}

// 1.4 check palindromes

bool isPalindromePermutation(std::string str){
    std::vector<bool> chars(26); 
    for (const char& c : str)
        if (c > 96 && c < 122) chars[c - 97] = !(chars[c - 97]);
    int count{};
    for (const auto& bit : chars)
        count += bit;
    return count == 1 ? true : false;
}

// 1.5 "one-edit" check on two strs

bool isOneAway(std::string str1, std::string str2){
    size_t sizeDiff{str1.size() - str2.size()};
    int count{};
    // replacement
    if (!sizeDiff){
        for (int i{}; i < str1.size(); ++i){
            if (str1[i] != str2[i]) ++count;
            if (count > 1) return false;
        }
        return true;
    }
    // insertion
    if (sizeDiff == -1){
        for (int i{}, j{}; i < str1.size(); ++i, ++j){
            if (str1[i] != str2[j]){
                ++count;
                ++j;
            }
            if (count > 1) return false;
        }
        return true;
    }
    // removal
    if (sizeDiff == 1){
        for (int i{}, j{}; i < str1.size(); ++i, ++j){
            if (str1[i] != str2[j]){
                ++count;
                ++i;
            }
            if (count > 1) return false;
        }
        return true;
    }
    return false;
}
    
// 1.6 string compression

std::string compressString(std::string str){
    std::string ret{};
    char curr{};
    int count{};    
    for (const char& c : str){
        if (count && c != curr){
            ret.append(1, curr); 
            ret.append(1, (char)('0' + count));
            count = 0;  
        }
        curr = c;
        count++;
    }
    ret.append(1, curr); 
    ret.append(1, (char)('0' + count));
    return str.size() > ret.size() ? ret : str;
}    

// 1.7 matrix rotation
void rotateMat(std::vector<std::vector<int>>& mat){
    size_t n = mat.size();
    // transpose
    for (size_t i{}; i < n; ++i){
        for (size_t j{i + 1}; j < n; ++j){
            std::swap(mat[i][j], mat[j][i]);
        }
    }
    // reverse each row
    for (size_t i{}; i < n; ++i){
        std::reverse(mat[i].begin(), mat[i].end());
    }
}

int main()
{
    using namespace std::literals;

    assert(!strHasDupes("abc"));
    assert(strHasDupes("banana"));
    assert(strHasDupes("1!agba!"));
    std::cout<<"--- 1.1 passed ---\n";
    assert(!isPermutation("abc", "ddd"));
    assert(isPermutation("abc", "bac"));
    assert(!isPermutation("abc", "adfjkh"));
    std::cout<<"--- 1.2 passed ---\n";
    assert(urlIfy("hello world"s) == "hello%20world"s);
    assert(urlIfy("hello world   "s) == "hello%20world%20"s);
    assert(urlIfy("      _hello    world%20"s) == "%20_hello%20world%20"s);
    std::cout<<"--- 1.3 passed ---\n";
    assert(isPalindromePermutation("omm"s));
    assert(!isPalindromePermutation("miles"s));
    assert(isPalindromePermutation("acto tac"s));
    assert(isPalindromePermutation("care rac"s));
    std::cout<<"--- 1.4 passed ---\n";
    assert(isOneAway("pale", "ple"));
    assert(isOneAway("pale", "bale"));
    assert(isOneAway("pale", "pales"));
    assert(!isOneAway("pale", "bake"));
    std::cout<<"--- 1.5 passed ---\n";
    assert(compressString("aaaabbbbbbdcccc"s) == "a4b6d1c4"s);
    assert(compressString("abcd"s) == "abcd"s);
    assert(compressString("aaaabcc"s) == "a4b1c2"s);
    assert(compressString("aaabcc"s) == "aaabcc"s);
    std::cout<<"--- 1.6 passed ---\n";
    std::vector<std::vector<int>> mat{
        {1,2,3,4,5},
        {2,3,4,5,6},
        {3,4,5,6,7},
        {4,5,6,7,8},
        {5,6,7,8,9}
    };
    std::vector<std::vector<int>> testMat{
        {5,4,3,2,1},
        {6,5,4,3,2},
        {7,6,5,4,3},
        {8,7,6,5,4},
        {9,8,7,6,5}
    };
    for (int i{}; i < mat.size(); ++i)
        for (int j{}; j < mat.size(); ++j)
            assert(mat[i][j] == testMat[i][j]); 
    std::cout<<"--- 1.7 passed ---\n";
    


    return 0;
} 
