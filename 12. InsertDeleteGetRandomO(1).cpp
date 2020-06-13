class RandomizedSet {
    private:
        vector<int> A;
        unordered_map<int,int> umap;
        int size = 0;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(umap.find(val) != umap.end()){
            return false;
        }
            
        A.push_back(val);
        umap[val] = size;
        size += 1;
        
        return true;
        
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(umap.find(val) == umap.end()){
            return false;
        }
        
        int ind = umap[val];
        A[ind] = A[size-1];
        umap[A[ind]] = ind;
        A.pop_back();
        
        umap.erase(val);
        size -= 1;

        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        //srand(time(NULL));
        int ind = rand()%size;
        return A[ind];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */