class Solution {
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer,Integer> map = new HashMap<> ();
        int t = 0;
        map.put(0,1);
        for (int i = 0; i < nums.length; ++i) {
            t += nums[i];
            map.put(t,map.getOrDefault(t,0)+1);
        }
        System.out.println(map);
        int total = 0;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            System.out.println((entry.getKey() - k));
            if (map.containsKey(entry.getKey() - k)) {
                // total += map.get(entry.getKey() - k);
                total += entry.getValue();
            }
        }

        return total;
        
    }
}