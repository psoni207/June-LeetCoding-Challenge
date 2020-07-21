class Trie{
    public:
    Trie* children[26];
    bool endOfWord;
    
    Trie(): endOfWord(false){
        for(int i = 0; i < 26; i += 1){
            children[i] = NULL;
        }
    }
    
    ~Trie(){
        for(int i = 0; i < 26; i += 1){
            if(children[i]) delete children[i];
        }
    }
    
    void insert(string word){
        Trie* curr = this;
        
        for(char  c: word){
            if(curr->children[c-'a'] == NULL){
                curr->children[c-'a'] = new Trie();
            }
            curr = curr->children[c-'a'];
        }
        curr->endOfWord = true;
    }
};

class Solution {
    private:
    int m, n, total;
    unordered_set<string> res;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        total = words.size();
        
        if(total == 0){
            return {};
        }
        
        Trie trie;
        for(string word: words){
            trie.insert(word);
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                helperSearch(board,i,j,"",&trie);
            }
        }
        
        vector<string> result(res.begin(), res.end());
        return result;
    }
    
    void helperSearch(vector<vector<char> > &board, int i, int j, string pre,Trie* trie){
        char c = board[i][j];
        if(c == '#'){
            return;
        }
        board[i][j] ='#';
        
        Trie* t = trie->children[c-'a'];
        if(t){
            string s = pre + c;
            if(t->endOfWord){
                res.insert(s);
            }
            if(i > 0 ){
                helperSearch(board, i-1, j, s, t);
            }
            if(j > 0 ){
                helperSearch(board, i, j-1, s, t);
            }
            if(i < m-1 ){
                helperSearch(board, i+1, j, s, t);
            }
            if(j < n-1 ){
                helperSearch(board, i, j+1, s, t);
            }
        }
        
        board[i][j] = c;
    }
};