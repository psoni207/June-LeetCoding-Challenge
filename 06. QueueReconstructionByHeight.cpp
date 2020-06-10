class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        vector<vector<int> > res;
        sort(people.begin(),people.end(), compHt);
        
        vector<int> temp;
        for(int i = 0; i < n; i += 1){
            temp = people[i];
            res.insert(res.begin() + temp[1], temp);
        }
        return res;
    }
    
    static bool compHt(const vector<int> &a, const vector<int> &b){
        if(a[0] > b[0] || a[0] == b[0] && a[1] < b[1]){
            return true;
        }else{
            return false;
        }
        
    }
};