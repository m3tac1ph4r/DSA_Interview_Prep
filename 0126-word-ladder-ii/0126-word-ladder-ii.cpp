class Solution {
public:
    unordered_map<string,int> mp;
    vector<vector<string>> ans;

    void dfs(string word,string beginWord,vector<string> &vec)
    {
        if(word==beginWord)
        {
            reverse(vec.begin(),vec.end());
            ans.push_back(vec);
            reverse(vec.begin(),vec.end());
            return;
        }
        int level=mp[word];
        int sz=word.size();
        for(int i=0;i<sz;i++)
        {
            char ch=word[i];
            for(char newCh='a';newCh<='z';newCh++)
            {
                word[i]=newCh;
                if(mp.find(word)!=mp.end() and mp[word]+1==level)
                {
                    vec.push_back(word);
                    dfs(word,beginWord,vec);
                    vec.pop_back();
                }
            }
            word[i]=ch;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, 
    vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        int bw_size=beginWord.size();
        queue<string> q;
        q.push(beginWord);
        mp[beginWord]=1;
        st.erase(beginWord);
        while(!q.empty())
        {
            string word=q.front();
            int level=mp[word];
            q.pop();
            if(word==endWord)
                break;
            for(int i=0;i<bw_size;i++)
            {
                char ch=word[i];
                for(char newCh='a';newCh<='z';newCh++)
                {
                    word[i]=newCh;
                    if(st.find(word)!=st.end())
                    {
                        q.push(word);
                        st.erase(word);
                        mp[word]=level+1;
                    }
                }
                word[i]=ch;
            }
        }
        if(mp.find(endWord)!=mp.end())
        {
            vector<string> vec;
            vec.push_back(endWord);
            dfs(endWord,beginWord,vec);
        }

        return ans;
    }
};