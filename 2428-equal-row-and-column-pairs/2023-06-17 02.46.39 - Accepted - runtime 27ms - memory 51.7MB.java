class Solution {
    public int equalPairs(int[][] grid) {

        int count = 0;

        Map<List<Integer>,Integer> rowToFreq = new HashMap<>();
        for(int i = 0; i < grid[0].length; ++i){
            List<Integer> rKey = new ArrayList<>();
            for(int j = 0; j < grid[0].length; ++j){
                rKey.add(grid[i][j]);
            }
            rowToFreq.put( rKey, rowToFreq.getOrDefault(rKey,0) + 1 );
            // System.out.println(Arrays.asList(r));
            // List<Integer> rKey = Arrays.stream(grid).flatMap(Arrays::stream).collect(Collectors.toList());

            // rKey.addAll(Arrays.asList(r));
            // rowToFreq.put( rKey, rowToFreq.getOrDefault(rKey,0) + 1 );
        }

        for(int j = 0; j < grid[0].length; ++j){
            List<Integer> cKey = new ArrayList<>();
            for(int i = 0; i < grid.length; ++i){
                cKey.add(grid[i][j]);
            }
            if(rowToFreq.containsKey(cKey)){
                count += rowToFreq.get(cKey);
            }
        }

        return count;
    }
}