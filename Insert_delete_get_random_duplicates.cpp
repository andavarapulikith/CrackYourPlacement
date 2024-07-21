class RandomizedCollection {
public:
    vector<int> arr;
    unordered_map<int, unordered_set<int>> mpp; 
    RandomizedCollection() {}
    bool insert(int val) {
        arr.push_back(val);
        mpp[val].insert(arr.size()-1);
        return mpp[val].size() <= 1;
    }
    
    bool remove(int val) {
        if(mpp[val].size()==0) 
        return false;
        int indi= *mpp[val].begin();
        mpp[val].erase(indi);
        int last= arr.back();
        swap(arr[indi], arr[arr.size()-1]);
        mpp[last].insert(indi);
        mpp[last].erase(arr.size()-1);
        arr.pop_back();
        return true;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */