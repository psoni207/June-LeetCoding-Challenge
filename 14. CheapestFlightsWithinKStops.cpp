class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector <pair<int,int> > > adj(n);
        
        //Range Based For loop
        for(vector<int> &flight : flights){
            adj[flight[0]].push_back({flight[1],flight[2]});
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > Q;
        Q.push({0,src,K+1});
        
        while(!Q.empty()){
            vector<int> top = Q.top();
            Q.pop();
            
            int dis = top[0];
            int u = top[1];
            int edge = top[2];
            if(dst == u){
                return dis;
            }
            if(edge > 0){
                for(pair<int,int> &v : adj[u]){
                    Q.push({dis + v.second, v.first, edge-1});
                }
            }
        }
        
        return -1;
    }
};