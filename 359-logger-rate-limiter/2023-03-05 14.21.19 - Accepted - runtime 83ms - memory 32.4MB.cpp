class Logger {
    unordered_map<string, int> loggerCache;
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (auto it = loggerCache.find(message); it != loggerCache.end()) {
            if (timestamp - it->second >= 10) {
                it->second = timestamp;
                return true;
            }
            return false;
        } else {
            loggerCache.emplace(message, timestamp);
            return true;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */