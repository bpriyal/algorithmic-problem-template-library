class Solution {  
    Map<Integer,Integer> cache = new HashMap<>(){{
        put(0,0);
        put(1,1);
        put(2,1);
    }};
    
    public int fib(int n) {
        if (cache.containsKey(n)) return cache.get(n);
        else if (cache.containsKey(n-1) && cache.containsKey(n-2)) {
            return cache.get(n-1) + cache.get(n-2);
        }
        int save = fib(n-1) + fib(n-2);
        cache.put(n, save);
        return save;
    }
}