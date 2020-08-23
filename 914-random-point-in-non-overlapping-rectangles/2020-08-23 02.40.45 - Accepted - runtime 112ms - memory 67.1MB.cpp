class Solution {
    vector <vector <int>> result;
    int index;
    vector <int> next;
    int _xmax;
    int _ymax;
    int _xmin;
    int _ymin;
public:
    Solution(vector<vector<int>>& rects) {
        result = rects;
        index = 0;
        next.emplace_back(result[index][0]);
        next.emplace_back(result[index][1]);
        _xmax = result[index][2];
        _ymax = result[index][3];
        _xmin = result[index][0];
        _ymin = result[index][1];
    }
    
    vector<int> pick() {
        vector <int> temp;
        temp = next;
        next[1] += 1;
        if(next[1] > _ymax)
        {
            next[1] = _ymin;
            next[0] += 1;
        }
        if(next[0] > _xmax)
        {
            index += 1;
            if(index >= result.size())
                index = 0;
            next.clear();
            next.emplace_back(result[index][0]);
            next.emplace_back(result[index][1]);
            _xmax = result[index][2];
            _ymax = result[index][3];
            _xmin = result[index][0];
            _ymin = result[index][1];
        }
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */