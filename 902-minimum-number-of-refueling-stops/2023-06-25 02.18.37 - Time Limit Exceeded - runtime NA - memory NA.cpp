class Solution {
    int minStops = std::numeric_limits<int>::max();
    int numberOfStations;
    void util(int target, int currentFuel, const vector<vector<int>>& stations, int stationToReach, int currentPosition, int stopsMade) {
        int maxReach = currentPosition + currentFuel;
        if (maxReach >= target) {
            minStops = min(minStops, stopsMade);
            return;
        }
        // Either stations are exhausted or you can't reach nearest station
        if (stationToReach >= numberOfStations || maxReach < stations[stationToReach][0]) return;

        // make a choice
        int fuelToReachNearestStation = stations[stationToReach][0] - currentPosition;

        // Fuel
        util(target, currentFuel - fuelToReachNearestStation + stations[stationToReach][1],
             stations, stationToReach + 1, stations[stationToReach][0], stopsMade + 1);
        
        // Don't Fuel
        util(target, currentFuel - fuelToReachNearestStation, 
             stations, stationToReach + 1, stations[stationToReach][0], stopsMade);
    }
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        numberOfStations = stations.size();
        util(target, startFuel, stations, 0, 0, 0);
        return minStops == std::numeric_limits<int>::max()? -1 : minStops;
    }
};