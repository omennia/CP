/* 
 * https://www.youtube.com/watch?v=oBt53YbR9Kk&t=11081s
 * All construct memoization (03:04:00) <- timestamp
 */
#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> mapping(string target, vector<vector<string>> suffixes){
    vector<vector<string>> res;
    for(auto elem : suffixes){
        vector<string> vec;
        vec.push_back(target);
        for(auto cur : elem){
            vec.push_back(cur);
        } res.push_back(vec);
    }
    return res;
}

vector<vector<string>> allConstruct(string target, vector<string> wordBank){
    if(target == "") return {{}};
    vector<vector<string>> result;
    for(int i=0; i<(int)wordBank.size(); ++i){
        string prefix = target.substr(0, (int)wordBank[i].size());
        
        if(wordBank[i] == prefix){ // keep going down the tree
            string suffix = target.substr((int)wordBank[i].size(), target.size());
            vector<vector<string>> suffixes = allConstruct(suffix, wordBank);
            vector<vector<string>> the_targets = mapping(prefix, suffixes);
            for(auto elem : the_targets) {
                result.push_back(elem); // append all the vectors inside the targets to "result"
            }
        } 
    } 
    return result;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    // vector<vector<string>> res = allConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd", "ef", "c"});
    vector<vector<string>> res = allConstruct("purple", {"purp", "p", "ur", "le", "purpl"});
    for(auto elem : res){
        for(auto cur : elem) cout << cur << ' ';
        cout << '\n';
    }
}