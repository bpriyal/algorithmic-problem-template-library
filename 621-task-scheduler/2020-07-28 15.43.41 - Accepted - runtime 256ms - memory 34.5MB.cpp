class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        unordered_map<int,int> cache;
        int chunks = 0;
        for(auto &x:tasks) {
            ++cache[x-'A'];
            chunks = max(chunks,cache[x-'A']);
        }
        int slots = (chunks-1)*n;
        //cout<<"slots:"<<slots<<endl;
        int flag = true;
        for(auto &it:cache) {
            if (it.second == chunks && flag) {
                flag = false;
                continue;
            }
            if (!flag || it.second != chunks) {
                slots -= min(chunks-1,it.second);
                //cout<<slots<<endl;
            }
        }
        return slots < 0 ? size:slots+size;
    }
};