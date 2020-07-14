class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angleOfHour = (hour%12)*5+(5.0/60)*minutes;
        double result = abs((angleOfHour-minutes)*6);
        return result > 180 ? 360-result:result;
    }
};