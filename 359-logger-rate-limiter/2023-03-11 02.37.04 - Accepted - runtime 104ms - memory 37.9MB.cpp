class Logger {
    unordered_map<string, int> currentCache; // stores logs for 10 seconds since init time
    unordered_map<string, int> prevCache; // stores logs for 10 seconds before init time
    int initTime; // resets every 10 seconds
public:
    Logger() {
        initTime = 0;
    }
    // Doesn't take care of memory
    // bool shouldPrintMessage(int timestamp, string message) {
    //     if (auto it = loggerCache.find(message); it != loggerCache.end()) {
    //         if (timestamp - it->second >= 10) {
    //             it->second = timestamp;
    //             return true;
    //         }
    //         return false;
    //     } else {
    //         loggerCache.emplace(message, timestamp);
    //         return true;
    //     }
    // }

    bool shouldPrintMessage(int timestamp, string message) {
        if (timestamp >= initTime + 10) {
            prevCache.clear();
            prevCache = currentCache;
            currentCache.clear();
            initTime = timestamp;
        }

        if (currentCache.find(message) != currentCache.end()) return false;
        if (prevCache.find(message) != prevCache.end() && prevCache[message] + 10 > timestamp) return false;

        currentCache.emplace(message, timestamp);
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */