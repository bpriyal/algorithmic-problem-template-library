class Solution {
public:
    int compareVersion(string version1, string version2) {
        int size1 = version1.size();
        int size2 = version2.size();
        
        vector<int> v1,v2;
        
        int in = 0;
        for(int i = 0;i<size1;++i) {
            if (version1[i]=='.' ) {
                //cout<<version1.substr(in,i-in)<<endl;
                v1.push_back(stoi(version1.substr(in,i-in)));
                in = i+1;
            } else if (i == size1-1) {
                v1.push_back(stoi(version1.substr(in)));
            }
        }
        in = 0;
        for(int i = 0;i<size2;++i) {
            if (version2[i]=='.') {
                v2.push_back(stoi(version2.substr(in,i-in).c_str()));
                in = i+1;
            } else if (i == size2-1) {
                v2.push_back(stoi(version2.substr(in)));
            }
        }
        
        
        for(int i=0;i<v1.size();++i) {
            //printf("%d||%d\n",v1[i],v2[i]);
            if (v1[i] > v2[i]) {
                return 1;
            } else if (v1[i] < v2[i]) {
                return -1;
            }
        }
        return 0;
    }
};