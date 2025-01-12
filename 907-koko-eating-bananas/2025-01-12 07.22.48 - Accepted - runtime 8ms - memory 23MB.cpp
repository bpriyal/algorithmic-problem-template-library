class Solution {
    bool _util(const vector<int>& piles, int h, int k) {
        // cout << "mid" << k << endl;
        for (auto pile : piles) {
            int hoursToEatPile = std::ceil(static_cast<double>(pile) / k);
            if (h < hoursToEatPile) return false;
            h -= hoursToEatPile;
            // cout << "h: " << h << endl;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int size = piles.size();
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int k;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (_util(piles, h, mid)) {
                k = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        // cout << l << "," <<r <<endl;
        return k;
    }
};