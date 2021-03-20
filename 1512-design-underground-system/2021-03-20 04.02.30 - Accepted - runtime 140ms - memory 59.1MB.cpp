class UndergroundSystem {
    unordered_map<int,pair<string,int>> checkInCache;
    unordered_map<string,pair<double,int>> avgTimeCache;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInCache[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string temp = checkInCache[id].first+stationName;
        if (avgTimeCache.find(temp) == avgTimeCache.end()) {
            avgTimeCache[temp] = {t-checkInCache[id].second,1};
            return;
        }
        avgTimeCache[temp].first += t-checkInCache[id].second;
        ++avgTimeCache[temp].second;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string temp = startStation+endStation;
        return avgTimeCache[temp].first/avgTimeCache[temp].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */