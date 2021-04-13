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
    int listSize;
    int listPosition;
    vector<NestedInteger> cache;
    
    queue<int> q; 
    
    void util(NestedInteger &list) {
        bool isInt = list.isInteger();
        
        if (!isInt) {
            int size = list.getList().size();
            for(int i = 0;i < size;++i) {
                if (list.getList()[i].isInteger()) {
                    q.push(list.getList()[i].getInteger());
                    //cout<<q.back()<<endl;
                } else {
                    util(list.getList()[i]);
                }
            }
        } else {
            q.push(list.getInteger());
            //cout<<q.back()<<endl;
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        listSize = nestedList.size();
        listPosition = 0;
        cache = nestedList;
    }
    
    int next() {
        int result = q.front();
        q.pop();
        return result;
    }
    
    bool hasNext() {
        while (q.empty()) {
            if (listPosition < listSize) {
                //if (q.empty()) {
                    util(cache[listPosition]);
                    ++listPosition;
                //}
            } else {
                break;
            }
        }
        return !q.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */