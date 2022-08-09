class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<int,long long int> m;
        sort(arr.begin(),arr.end());
        //initially filling all map valuyes with 1 as each element can be part of
        //final output
        for(int i=0;i<arr.size();i++){
            m.insert({arr[i],1});
        }
        //i starts from 1 as min number cannot generate any trres other than itself
        for(int i=1;i<arr.size();i++){
            auto it3= m.find(arr[i]);
            long long int count=0;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    auto it= m.find(arr[i]/arr[j]);
                    auto it2= m.find(arr[j]);
                    if(it!=m.end()){
                        count+=(it->second)*(it2->second);    
                    }
                }
            }
            it3->second+=count;
        }
        long long int sum=0;
        for(auto temp: m){
            sum+=temp.second;
        }
        return sum%(1000000007);
    }
};