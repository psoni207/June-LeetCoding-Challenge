class Solution {
    private:
    int n, sum = 0;
    vector<int> A;
public:
    Solution(vector<int>& w) {
        n = w.size();
        for(int i = 0; i < n; i += 1){
            sum += w[i];
            A.push_back(sum);
        }
    }
    
    int pickIndex() {
        int wIndex = rand()%sum;
        return binarySearch(wIndex + 1);
        
    }
    
    int binarySearch(int val){
        int low = 0;
        int high = n - 1;
        while(low < high){
            int mid = low + (high - low)/2;
            if(A[mid] < val){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        return low;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */