class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int cost = 0;
        sort(costs.begin(), costs.end(), compareDiff);
        
        int n = costs.size();
        
        for(int i = 0; i < n/2; i += 1){
            cost += costs[i][0];
        }
        for(int i = n/2; i < n; i += 1){
            cost += costs[i][1];
        }
        
        return cost;
        
    }
    
    bool static compareDiff(const vector<int> &a, const vector<int> &b){
        if( a[0] - a[1] < b[0] - b[1] ){
            return true;
        }else{
            return false;
        }
    }
};