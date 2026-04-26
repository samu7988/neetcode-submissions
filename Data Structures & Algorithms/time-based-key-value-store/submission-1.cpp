class TimeMap {
public:
    map<string,vector<pair<string,int>>>mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string,int>> row = mp[key];
        string value =""; 

        for(int i = 0 ; i < row.size(); i++)
        {

            if(timestamp >= row[i].second )
            {
                value = row[i].first;
                
            }
            else
            {
               break;
            }
        }
        return value;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */