class Solution {
    int gcd(int x,int y) {
        if (y == 0) {
            return x;
        }
        return gcd(y,x%y);
    }
public:
    int largestComponentSize(vector<int>& A) {
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
                        if (!visited[j] && gcd(element,A[j]) > 1) {
                            q.push(A[j]);
                            visited[j] = true;
                        }
                    }
                }
                result = max(compSize,result);
            }
        }
        return result;
    }
};