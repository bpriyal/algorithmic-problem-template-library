class MyCalendarTwo {
    vector<pair<int, int>> events;
    vector<pair<int, int>> doublyBookedEvents;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for (const auto& event : doublyBookedEvents) {
            if (event.first < end && start < event.second) return false;
        }

        for (const auto& event : events) {
            if (event.first < end && start < event.second) {
                doublyBookedEvents.emplace_back(max(event.first, start), min(event.second, end));
            }
        }
        sort(doublyBookedEvents.begin(), doublyBookedEvents.end());
        events.emplace_back(start, end);
        sort(events.begin(), events.end());
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */