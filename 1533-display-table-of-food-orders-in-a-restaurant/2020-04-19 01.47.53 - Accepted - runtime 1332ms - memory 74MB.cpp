class Solution {
public:
    vector<string> food;
    vector<int> table;
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<string,map<string,int>> m;
        int rows=orders.size();
        vector<string> food;
        vector<int> table;
        for(int i=0;i<rows;++i) {
            m[orders[i][1]][orders[i][2]]+=1;
            food.push_back(orders[i][2]);
            table.push_back(stoi(orders[i][1]));
        }
        
        sort(food.begin(),food.end());
        sort(table.begin(),table.end());

        vector<string>::iterator ip;
        ip=unique(food.begin(),food.end());
        food.resize(distance(food.begin(),ip));
        
        vector<int>::iterator ip1;
        ip1=unique(table.begin(),table.end());
        table.resize(distance(table.begin(),ip1));
        
        vector<vector<string>> output(m.size()+1);
        for(int i=0;i<output.size();++i){
            output[i]= vector<string>(food.size()+1);
        }
        output[0][0] = "Table";
        for(int i=1;i<=food.size();i++) {
            output[0][i] =food[i-1];
        }
        
        for(int i=1;i<=table.size();++i) {
            output[i][0] = to_string(table[i-1]);
        }
        
        for (int i=1;i<=table.size();++i){
            for(int j=1;j<=food.size();++j){
                output[i][j] = to_string(m[output[i][0]][output[0][j]]);
            }
        }
        
        return output;
    }
};