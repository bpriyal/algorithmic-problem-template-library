class Solution {
    public List<List<Integer>> generate(int numRows) {
        // int i = 0;
        List<List<Integer>> triangle = new ArrayList<List<Integer>>();
        triangle.add(new ArrayList<>(){{add(1);}});   
        if(numRows == 1){
            return triangle;
        }
        triangle.add(new ArrayList<>(){{add(1);add(1);}});
        if(numRows == 2){
            return triangle;
        }

        int noOfValsInRow = 3;
        for(int i = 2; i < numRows; ++i, ++noOfValsInRow){
            List<Integer> row = new ArrayList<>(){{add(1);}};
            for(int j = 1; j < noOfValsInRow - 1; ++j){
                int first = triangle.get(i-1).get(j-1);
                int second = triangle.get(i-1).get(j);
                row.add(first + second);
            }
            row.add(1);
            triangle.add(row);
        }

        // for(List<Integer> l : triangle){
        //     for(Integer i : l){
        //         System.out.println(i);
        //     }
        // }
        return triangle;
    }
}