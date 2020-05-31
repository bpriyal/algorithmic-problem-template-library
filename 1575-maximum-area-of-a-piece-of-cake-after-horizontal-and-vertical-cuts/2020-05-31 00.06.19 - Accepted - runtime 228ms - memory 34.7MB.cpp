class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int sizeh = horizontalCuts.size();
        int sizew = verticalCuts.size();
        vector<int> x1;
        vector<int> x2;
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        x1.push_back(horizontalCuts[0]-0);
        x2.push_back(verticalCuts[0]-0);
        
        for(int i = 1;i<sizeh;++i) {
            cout<<i<<endl;
            x1.push_back(horizontalCuts[i]-horizontalCuts[i-1]);
        }
        for(int i = 1;i<sizew;++i) {
            x2.push_back(verticalCuts[i]-verticalCuts[i-1]);
        }
        
        x1.push_back(h-horizontalCuts[sizeh-1]);
        x2.push_back(w-verticalCuts[sizew-1]);
        
        long int modulo = (pow(10,9) + 7);
        long int a=(*max_element(x1.begin(),x1.end()))%modulo;
        long int b = (*max_element(x2.begin(),x2.end()))%modulo;
        return (a * b)%modulo;
    }
};