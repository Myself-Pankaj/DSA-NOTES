#include<bits/stdc++.h>
using namespace std;

class wordLadder
{
private:
    /* data */
    
public:
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,0});
        st.erase(beginWord);

        while (!q.empty())
        {
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            if(word == endWord) return level;
            int len = word.length();
            for (int i = 0; i < len; i++)
            {
                char og = word[i];
                for (char ch = 'a'; ch <='z'; ch++)
                {
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word,level+1});
                    }
                }
                word[i] = og;
            }
            
        }
        return 0;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>>res;
        queue<pair<vector<string>,int>>q;
        unordered_set<string>st(wordList.begin(),wordList.end());
        q.push({{beginWord},1});
        st.erase(beginWord);int ctr = 1;
        vector<string> deleteword;
        int lastlevel = -1;
        while(!q.empty()){
            vector<string> local = q.front().first;
            string word = q.front().first.back();
            int level = q.front().second;
            
            
            q.pop();
            if(word == endWord){
                res.push_back(local);
                lastlevel = level;
            }
            if(level != ctr){
                ctr++;
                int size = deleteword.size();
                for (const auto& w : deleteword) {
                    st.erase(w);
                }
                deleteword.clear();
                if(ctr == lastlevel+1) break;
            }
            int len = word.length();
            for (int i = 0; i < len; i++)
            {
                char og = word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i] = ch;
                    if(st.find(word)!= st.end()){
                            vector<string> temp = local;
                            temp.push_back(word);
                            deleteword.push_back(word);
                            q.push({temp, level + 1});
                    }
                }
                word[i] = og;
            }
            
        }
       
        return res;
    }
};


