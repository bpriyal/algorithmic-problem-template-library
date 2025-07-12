class SmallestInfiniteSet {
    SortedSet<Integer> addedBack;
    int count;

    public SmallestInfiniteSet() {
        addedBack = new TreeSet();
        count = 1;
    }
    
    public int popSmallest() {
        if (addedBack.isEmpty()) return count++;
        if (addedBack.first() < count) {
            int i = addedBack.first();
            addedBack.remove(i);
            return i;
        } else {
            return count++;
        }
    }
    
    public void addBack(int num) {
        if (num < count) addedBack.add(num);
    }
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet obj = new SmallestInfiniteSet();
 * int param_1 = obj.popSmallest();
 * obj.addBack(num);
 */