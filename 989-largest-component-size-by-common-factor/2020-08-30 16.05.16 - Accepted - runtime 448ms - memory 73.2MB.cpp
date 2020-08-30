class Solution {
    int find (int x,vector<int>& parent){
        if(parent[x]==-1) {
            return x;
        }
        parent[x] = find(parent[x], parent);
        return parent[x];
    }
    
    void Union(int x,int y,vector<int>& parent){
        int a= find(x,parent);
        int b = find(y,parent);
        if(a != b) {
            parent[b] = a;
        }
    }
public:
    int largestComponentSize(vector<int>& A) {
        /* time out
        int size = A.size();
        vector<bool> visited(size,false);
        queue<int> q;
        int result = INT_MIN;
        
        for(int i = 0;i < size;++i) {
            if (!visited[i]) {
                q.push(A[i]);
                visited[i] = true;
                int compSize = 0;
                while(!q.empty()) {
                    //cout<<q.size()<<endl;
                    int element = q.front();
                    q.pop();
                    ++compSize;
                    for(int j = i+1; j < size;++j) {
                        if (!visited[j] && A[j] != element && gcd(element,A[j]) > 1) {
                            q.push(A[j]);
                            visited[j] = true;
                        }
                    }
                }
                result = max(compSize,result);
            }
        }
        return result; */
        
        vector<int> parent(100001, -1);
        for(auto x:A){
            for(int i=2;i<=sqrt(x);++i){
                if(x%i==0){
                    Union(i,x,parent);
                    Union(x,x/i,parent);
                }
            }
        }
        
        int count = 0;
        unordered_map<int, int> cache;
        for(int x:A){
            int a = find(x, parent);
            count = max(count, 1 + cache[a]);
            ++cache[a];
        }
        return count;
    }
};