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

/********************* Memory limit exceeds because of target being = 1000000000 *********************/
// class Solution {
//     int beyondReach = std::numeric_limits<int>::max();
//     int numberOfStations;
//     vector<vector<int>> dp;
//     int util(int target, int currentFuel, const vector<vector<int>>& stations, int stationToReach, int currentPosition) {
//         int maxReach = currentPosition + currentFuel;
//         if (maxReach >= target) return 0;
//         // Either stations are exhausted or you can't reach nearest station
//         if (stationToReach >= numberOfStations || maxReach < stations[stationToReach][0]) return beyondReach;

//         if (dp[currentPosition][currentFuel] != -1) return dp[currentPosition][currentFuel];

//         /* make a choice */
//         int fuelToReachNearestStation = stations[stationToReach][0] - currentPosition;
//         // Fuel
//         int withFuel = util(target, currentFuel - fuelToReachNearestStation + stations[stationToReach][1], stations, stationToReach + 1, stations[stationToReach][0]);
//         int stops = withFuel == beyondReach? beyondReach : withFuel + 1;
//         // Don't Fuel
//         stops = min(stops, util(target, currentFuel - fuelToReachNearestStation, stations, stationToReach + 1, stations[stationToReach][0]));
        
//         return dp[currentPosition][currentFuel] = stops;
//     }
// public:
//     int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
//         dp.resize(target + 1, vector<int>(target + 1, -1));
//         numberOfStations = stations.size();
//         int stops = util(target, startFuel, stations, 0, 0);
//         return stops == beyondReach? -1 : stops;
//     }
// };

/********* Still TLE *************/
// class Solution {
//     int beyondReach = std::numeric_limits<int>::max();
//     int numberOfStations;
//     unordered_map<int, unordered_map<int, int>> dp;
//     int util(int target, int currentFuel, const vector<vector<int>>& stations, int stationToReach, int currentPosition) {
//         int maxReach = currentPosition + currentFuel;
//         if (maxReach >= target) return 0;
//         // Either stations are exhausted or you can't reach nearest station
//         if (stationToReach >= numberOfStations || maxReach < stations[stationToReach][0]) return beyondReach;

//         if (auto it = dp.find(currentPosition); it != dp.end()) {
//             if (it->second.find(currentFuel) != it->second.end()) {
//                 // cout<<"returning from dp"<<endl;
//                 return dp[currentPosition][currentFuel];
//             }
//         }

//         /* make a choice */
//         int fuelToReachNearestStation = stations[stationToReach][0] - currentPosition;
//         // Fuel
//         int withFuel = util(target, currentFuel - fuelToReachNearestStation + stations[stationToReach][1], stations, stationToReach + 1, stations[stationToReach][0]);
//         int stops = withFuel == beyondReach? beyondReach : withFuel + 1;
//         // Don't Fuel
//         stops = min(stops, util(target, currentFuel - fuelToReachNearestStation, stations, stationToReach + 1, stations[stationToReach][0]));
        
//         return dp[currentPosition][currentFuel] = stops;
//     }
// public:
//     int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
//         numberOfStations = stations.size();
//         int stops = util(target, startFuel, stations, 0, 0);
//         return stops == beyondReach? -1 : stops;
//     }
// };

class Solution {
public:
    // int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    //     int numberOfStations = stations.size();
    //     // dp[i] = with i stops how far can you reach
    //     vector<long> dp(numberOfStations + 1);
    //     dp[0] = startFuel;

    //     for (int stop = 0; stop < numberOfStations; ++stop) {
    //         for (int j = stop; j >= 0; --j) {
    //             if (dp[j] >= stations[stop][0])
    //                 dp[j + 1] = max(dp[j+ 1], dp[j] + stations[stop][1]);
    //         }
    //     }

    //     for (int stop = 0; stop < dp.size(); ++stop) if (dp[stop] >= target) return stop;
    //     return -1;
    // }

    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int stops = 0;
        int lastStopPosition = 0;
        int remainingFuel = startFuel;
        for (const auto& station : stations) {
            remainingFuel -= (station[0] - lastStopPosition);
            while (!pq.empty() && remainingFuel < 0) {
                auto stationFuel = pq.top();
                pq.pop();
                remainingFuel += stationFuel;
                ++stops;
            }
            
            if (remainingFuel < 0) return -1;
            pq.emplace(station[1]);
            lastStopPosition = station[0];
        }
        while (!pq.empty() && remainingFuel < (target - lastStopPosition)) {
            auto stationFuel = pq.top();
            pq.pop();
            remainingFuel += stationFuel;
            ++stops;
        }
        if (remainingFuel < (target - lastStopPosition)) return -1;
        return stops;
    }
};