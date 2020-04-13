class Solution {
public:
    
    long int findMaxLength(vector<int>& nums) {
        long int numssize = nums.size();
        if (numssize == 0) return 0;
        long int sumleft[nums.size()];
        sumleft[0] = ((nums[0]==0) ? -1 : 1);
        long int maxsize=sumleft[0];
        long int minsize=sumleft[0];
        cout<<sumleft[0]<<endl;
        for (long int i=1;i<numssize;++i){
            sumleft[i]=sumleft[i-1]+ ((nums[i]==0) ? -1 : 1);
            if (sumleft[i] > maxsize) {
                maxsize =sumleft[i];
            }
            if (sumleft[i] < minsize) {
                minsize = sumleft[i];
            }
            cout<<sumleft[i]<<endl;
        }
        
        long int hashmap[maxsize-minsize+1];
        for (long int i=0; i<maxsize-minsize+1; i++){ 
            hashmap[i] = -1; 
        }
        long int maxx = 0;
        
        for(long int i=0;i<numssize;++i){
            if(sumleft[i]==0){
                maxx =i+1;
            }
            
            if (hashmap[sumleft[i]-minsize]==-1){
                hashmap[sumleft[i]-minsize]=i;
            } else {
                if ((i-hashmap[sumleft[i]-minsize])>maxx){
                    cout<<"here"<<endl;
                    maxx = i - hashmap[sumleft[i] - minsize];
                }
            }
        }
        return maxx;
    }
};