class Solution {
    int util(int topAsteroid, int newAsteroid, stack<int>& st) {
        cout<<st.size()<<endl;
        if (topAsteroid >= 0 && newAsteroid < 0) {
            if (abs(topAsteroid) > abs(newAsteroid)) {
                
            }
            else if (abs(topAsteroid) < abs(newAsteroid)) {
                st.pop();
                //st.push(newAsteroid);
                if (!st.empty()) {
                    if (util(st.top(), newAsteroid, st) == 0) st.push(newAsteroid);
                }
                return -1;
            } 
            else st.pop();
            
            return 0;
        } else {
            st.push(newAsteroid);
            return 1;
        }
    }
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int size = asteroids.size();
        
        stack<int> st;
        st.push(asteroids[0]);
        
        for(int i = 1; i < size; ++i) {
            if (!st.size()) {
                st.push(asteroids[i]);
                continue;
            }
            
            util(st.top(), asteroids[i], st);
        }
        while (st.size() >= 2) {
            int topAsteroid = st.top();
            st.pop();
            if (util(st.top(), topAsteroid, st)) break;
        }
        
        size = st.size();
        vector<int> result(size);
        
        while (size > 0) {
            result[size - 1] = st.top();
            st.pop();
            --size;
        }
        
        return result;
    }
};