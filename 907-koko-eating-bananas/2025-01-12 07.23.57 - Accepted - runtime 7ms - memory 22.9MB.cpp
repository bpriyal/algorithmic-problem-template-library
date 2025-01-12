class Solution {
    bool _util(const vector<int>& piles, int h, int k) {
        for (auto pile : piles) {
            int hoursToEatPile = std::ceil(static_cast<double>(pile) / k);
            if (h < hoursToEatPile) return false;
            h -= hoursToEatPile;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int size = piles.size();
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (_util(piles, h, mid)) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};