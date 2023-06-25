/********************* First Version, no memoization, TLE *********************/
// class Solution {
//     int beyondReach = std::numeric_limits<int>::max();
//     int numberOfStations;
//     int util(int target, int currentFuel, const vector<vector<int>>& stations, int stationToReach, int currentPosition) {
//         int maxReach = currentPosition + currentFuel;
//         if (maxReach >= target) return 0;
//         // Either stations are exhausted or you can't reach nearest station
//         if (stationToReach >= numberOfStations || maxReach < stations[stationToReach][0]) return beyondReach;

//         /* make a choice */
//         int fuelToReachNearestStation = stations[stationToReach][0] - currentPosition;
//         // Fuel
//         int withFuel = util(target, currentFuel - fuelToReachNearestStation + stations[stationToReach][1], stations, stationToReach + 1, stations[stationToReach][0]);
//         int stops = withFuel == beyondReach? beyondReach : withFuel + 1;
//         // Don't Fuel
//         stops = min(stops, util(target, currentFuel - fuelToReachNearestStation, stations, stationToReach + 1, stations[stationToReach][0]));
        
//         return stops;
//     }
// public:
//     int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
//         numberOfStations = stations.size();
//         int stops = util(target, startFuel, stations, 0, 0);
//         return stops == beyondReach? -1 : stops;
//     }
// };

class Solution {
    int beyondReach = std::numeric_limits<int>::max();
    int numberOfStations;
    vector<vector<int>> dp;
    int util(int target, int currentFuel, const vector<vector<int>>& stations, int stationToReach, int currentPosition) {
        int maxReach = currentPosition + currentFuel;
        if (maxReach >= target) return 0;
        // Either stations are exhausted or you can't reach nearest station
        if (stationToReach >= numberOfStations || maxReach < stations[stationToReach][0]) return beyondReach;

        if (dp[currentPosition][currentFuel] != -1) return dp[currentPosition][currentFuel];

        /* make a choice */
        int fuelToReachNearestStation = stations[stationToReach][0] - currentPosition;
        // Fuel
        int withFuel = util(target, currentFuel - fuelToReachNearestStation + stations[stationToReach][1], stations, stationToReach + 1, stations[stationToReach][0]);
        int stops = withFuel == beyondReach? beyondReach : withFuel + 1;
        // Don't Fuel
        stops = min(stops, util(target, currentFuel - fuelToReachNearestStation, stations, stationToReach + 1, stations[stationToReach][0]));
        
        return dp[currentPosition][currentFuel] = stops;
    }
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        dp.resize(target + 1, vector<int>(target + 1, -1));
        numberOfStations = stations.size();
        int stops = util(target, startFuel, stations, 0, 0);
        return stops == beyondReach? -1 : stops;
    }
};