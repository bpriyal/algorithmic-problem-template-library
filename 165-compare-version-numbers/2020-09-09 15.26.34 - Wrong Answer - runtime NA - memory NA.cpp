class Solution {
public:
    int compareVersion(string version1, string version2) {
        int size = max(version1.size(),version2.size());
        //cout<<size<<endl;
        int size1 = version1.size();
        int size2 = version2.size();
        vector<char> v1,v2;
        for(int i=0;i<size;++i) {
            if (i < size1 && version1[i]=='.') {
                //printf("%c\n",version1[i]);
                v1.push_back(version1[i-1]);
            } else if (i > size1) {
                v1.push_back('0');
            } else if (i == size1-1) {
                v1.push_back(version1[i]);
            }
            
            if (i < size2 && version2[i]=='.') {
                v2.push_back(version2[i-1]);
            } else if (i >= size2) {
                v2.push_back('0');
            } else if (i == size2-1) {
                v2.push_back(version2[i]);
            }
        }
        //cout<<v1.size()<<endl;
        for(int i=0;i<v1.size();++i) {
            //printf("%c||%c\n",v1[i],v2[i]);
            if (v1[i] > v2[i]) {
                return 1;
            } else if (v1[i] < v2[i]) {
                return -1;
            }
        }
        return 0;
    }
};