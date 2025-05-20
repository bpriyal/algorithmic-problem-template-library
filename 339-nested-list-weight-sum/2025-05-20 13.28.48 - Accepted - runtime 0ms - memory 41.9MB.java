/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
class Solution {
    int TOTAL = 0;
    public int depthSum(List<NestedInteger> nestedList) {
        for (NestedInteger element : nestedList) {
            nested (element, 1);
        }
        return TOTAL;
    }

    void nested(NestedInteger element, int depth) {
        if (element.isInteger()) {
            TOTAL += depth * element.getInteger();
            return;
        }
        depth++;
        List<NestedInteger> listInside = element.getList();
        for (NestedInteger ni : listInside) {
            nested(ni, depth);
        }
    }
}