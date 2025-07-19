class Solution {
    public int findCircleNum(int[][] isConn) {
        int n = isConn.length;
        Map<Integer, LinkedHashSet<Integer>> cityConns = new HashMap();
        for (int i = 0; i < n; ++i) {
            LinkedHashSet<Integer> connCities = new LinkedHashSet();
            for (int j = 0; j < n; ++j) {
                if (isConn[i][j] == 1) connCities.add(j);
            }
            cityConns.put(i, connCities);
        }
//
        for (int i = 0; i < cityConns.size(); ++i) {
            LinkedHashSet<Integer> checkCityList = cityConns.get(i);
            if(checkCityList != null)
            for (int mergeCity : checkCityList) {
                if (i != mergeCity) {
                    checkCityList.addAll(cityConns.get(mergeCity));
                    cityConns.remove(mergeCity);
                }
            }
        }

        return cityConns.size();
    }
}