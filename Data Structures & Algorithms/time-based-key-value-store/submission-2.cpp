class TimeMap {
public:
    map<string, vector<pair<string,int>>> mp;   // key → list of {value, timestamp} pairs

    TimeMap() {}   // nothing to initialize
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});   // append {value, timestamp} to key's history
    }
    
    string get(string key, int timestamp) {
        vector<pair<string,int>> row = mp[key];  // get all {value, timestamp} pairs for key
        string value = "";                        // default: return "" if no valid timestamp found

        for(int i = 0; i < row.size(); i++)
        {
            if(timestamp >= row[i].second)        // current timestamp ≤ requested → valid candidate
            {
                value = row[i].first;             // update value (later pairs may be even closer)
            }
            else
            {
                break;                            // timestamps are sorted → no further valid pairs exist
            }
        }
        return value;                             // return latest value with timestamp ≤ requested
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */