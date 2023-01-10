class Solution {
public:
    string nextClosestTime(string time) {
        set<int> cache;
        for (char c : time) {
            if (c != ':') cache.emplace(c - '0');
        }
        string result = time;

        for (int i = 4; i >= 0; --i) {
            switch (i) {
                case 4: {
                    auto it = std::upper_bound(cache.begin(), cache.end(), time[i] - '0');
                    if (it != cache.end()) {
                        result[i] = *it + '0';
                        return result;
                    }
                    break;
                }
                case 3: {
                    auto it = std::upper_bound(cache.begin(), cache.end(), time[i] - '0');
                    if (it != cache.end() && *it <= 5) {
                        result[i] = *it + '0';
                        return result;
                    }
                    break;
                }
                case 2: {
                    break;
                }
                case 1: {
                    auto it = std::upper_bound(cache.begin(), cache.end(), time[i] - '0');
                    if (it != cache.end() && ((time[0] == '2' && *it <= 3) || (time[0] == '1' || time[0] == '0'))) {
                        result[i] = *it + '0';
                        return result;
                    }
                    break;
                }
                case 0: {
                    auto it = std::upper_bound(cache.begin(), cache.end(), time[i] - '0');
                    if (it != cache.end() && *it <= 2) {
                        result[i] = *it + '0';
                        return result;
                    }
                    break;
                }
            }
        }

        if (result == time) {
            char c = *cache.begin() + '0';
            result = "";
            result = result + c + c + ':' + c + c;
        }

        return result;
    }
};