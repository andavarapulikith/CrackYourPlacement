/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int>list;
    int indi=0;
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(NestedInteger it:nestedList){
            helper(it);
        }
        
    }
    
    int next() {
        return list[indi++];
    }
    
    bool hasNext() {
        return indi<list.size();
    }
   private:
   private:
    void helper(NestedInteger value) {
        if (value.isInteger()) {
            list.push_back(value.getInteger());
        } else {
            for (NestedInteger it : value.getList()) {
                helper(it);
            }
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */