class Solution {
    int size;
    vector<vector<int>> dp;
    int util(const vector<vector<int>>& courses,int i,int currentDay) {
        if (i >= size) {
            return 0;
        }
        
        if (dp[i][currentDay] != -1) {
            return dp[i][currentDay];
        }
        
        int temp = INT_MIN;
        // take current course
        if (currentDay+courses[i][0] <= courses[i][1]) {
            temp = max(temp,util(courses,i+1,currentDay+courses[i][0])+1);
        }
        
        // don't take current course
        temp = max(temp,util(courses,i+1,currentDay));
        
        dp[i][currentDay] = temp;
        
        return temp;
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        size = courses.size();
        
        sort(courses.begin(),courses.end(),[](vector<int> &a,vector<int> &b) {
            return a[1] < b[1];
        });
        
        /*dp.resize(size,vector<int>(courses[size-1][1],-1));
        
        return util(courses,0,0);*/
        
        priority_queue<int> pq;
        int currentDay = 0;
        
        for(const vector<int> &course:courses)  {
            pq.push(course[0]);
            currentDay += course[0];
            
            if (currentDay > course[1]) {
                currentDay -= pq.top();
                pq.pop();
            }
        }
        
        return pq.size();
    }
};