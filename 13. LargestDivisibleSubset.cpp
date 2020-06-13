
//O(N^2) Space
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1){
            return nums;
        }
        
        sort(nums.begin(),nums.end());
        
        vector<vector<int> > res(n, vector<int> ());
        int max_len = 1;
        int max_ind = 0;
        
        for(int i = n-1; i >= 0; i--){
            res[i].push_back(nums[i]);
            int j = i + 1;
            int _max_len = 0;
            int _max_ind = i;
            
            while(j < n){
                if(nums[j] % nums[i] == 0 && res[j].size() > _max_len){
                    _max_len = res[j].size();
                    _max_ind = j;
                }
                j += 1;
            }
            if(_max_ind != i){
                res[i].insert(res[i].end(),res[_max_ind].begin(),res[_max_ind].end());
                
                if(_max_len + 1 > max_len){
                    max_len = _max_len + 1;
                    max_ind = i;
                }
                
            }
        }
        
        return res[max_ind];
    }
};

//O(N) Space
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1){
            return nums;
        }
        
        sort(nums.begin(),nums.end());
        
        vector<int> next_ind(n,-1);
        vector<int> sizes(n,1);
        
        int max_len = 1;
        int max_ind = 0;
        
        for(int i = n-1; i >= 0; i--){
            int j = i + 1;
            int _max_len = 0;
            int _max_ind = i;
            
            while(j < n){
                if(nums[j] % nums[i] == 0 && sizes[j] > _max_len){
                    _max_len = sizes[j];
                    _max_ind = j;
                }
                j += 1;
            }
            if(_max_ind != i){
                sizes[i] += sizes[_max_ind];
                next_ind[i] = _max_ind;
                
                if(_max_len + 1 > max_len){
                    max_len = _max_len + 1;
                    max_ind = i;
                }
                
            }
        }
        
        vector<int> res;
        int ind = max_ind;
        while(ind != -1){
            res.push_back(nums[ind]);
            ind = next_ind[ind];
        }
        
        return res;
    }
};




