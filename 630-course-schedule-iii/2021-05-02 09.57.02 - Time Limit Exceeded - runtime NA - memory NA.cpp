class Solution {
    int size;
    int util(const vector<vector<int>>& courses,int i,int currentDay) {
        if (i >= size) {
            return 0;
        }
        
        int temp = INT_MIN;
        // take current course
        if (currentDay+courses[i][0] <= courses[i][1]) {
            temp = max(temp,util(courses,i+1,currentDay+courses[i][0])+1);
        }
        
        // don't take current course
        temp = max(temp,util(courses,i+1,currentDay));
        
        return temp;
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](vector<int> &a,vector<int> &b) {
            return a[1] < b[1];
        });
        
        size = courses.size();
        
        return util(courses,0,0);
    }
};