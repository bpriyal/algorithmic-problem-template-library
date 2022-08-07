class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        int result = 0;
        
        vector<pair<bool, int>> cache(26, {true, 0});
        vector<char> wait(n+1, 'i');
        int index = -1;
        
        for(auto &it : tasks) {
            cache[it - 'A'] = { cache[it - 'A'].first, ++cache[it - 'A'].second };
        }
        
        // cout<<"aaaks"<<endl;
        
        while (size > 0) {
            
            ++result;
            
            index = (index + 1) % (n + 1);
            if (wait[index] != 'i') cache[wait[index] - 'A'].first = true;
            int i;
            for(i = 0; i < 26; ++i) {
                if (cache[i].first && cache[i].second > 0) {
                    wait[index] = i + 'A';
                    --cache[i].second;
                    --size;
                    cache[i].first = false;
                    break;
                }
            }
            if (i == 26) {
                wait[index] = 'i';
            }
        }
        
        return result;
    }
};