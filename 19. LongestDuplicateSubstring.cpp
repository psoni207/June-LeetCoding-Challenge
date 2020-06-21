class Solution {
    private:
    int prime = 10000001;
    vector<int> power;
     
    
public:
    string longestDupSubstring(string S) {
        int n = S.length();
        power = vector<int>(n);
        
        power[0] = 1;
        for(int i = 1; i < n; i += 1){
            power[i] = (power[i-1] * 26) % prime;
        }
        
        int low = 0;
        int high = n - 1;
        string res = "";
        
        while(low <= high){
            int mid = low + (high-low)/2;
            string curr = rabinKarp(S,mid);
            
            if(curr.length() > res.length()){
                res = curr;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        
        return res;
        
    }
    
    string rabinKarp(string &S, int len){
        if(len == 0){
            return "";
        }
        
        int n = S.length();
        int curr = 0;
        unordered_map<int,vector<int> > hash;
        
        for(int i = 0; i < len; i += 1){
            curr = (curr*26 + (S[i]-'a')) % prime;
        }
        
        hash[curr] = {0};
        for(int i = len; i < n; i += 1){
            curr = ( (curr - power[len-1]*(S[i-len]-'a')) % prime + prime ) % prime;
            curr = (curr*26 + (S[i]-'a') ) % prime;
            
            if(hash.find(curr) == hash.end()){
                hash[curr] = {i-len+1};
            }else{
                for(int index : hash[curr]){
                    string str = S.substr(i-len+1,len);
                    if(S.substr(index,len) == str){
                        return S.substr(index,len);
                    }
                }
                hash[curr].push_back({i-len+1});
            }
        }
        
        return "";
    }
    
   
};