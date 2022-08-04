class MyCalendar {
private:
    map<int,int> mp;
    public:
    vector<vector<int>> ans;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        //STEP 1
        //<key: sum> pair
        mp[start]++;
        mp[end]--;
        int sum=0;
       for(auto it=mp.begin();it!=mp.end();it++){
           sum+=it->second;
           if(sum>1){
               //because we didnt add the event in our log, so reverting changes made in 
               //step1
            mp[start]--;
            mp[end]++;
            return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */