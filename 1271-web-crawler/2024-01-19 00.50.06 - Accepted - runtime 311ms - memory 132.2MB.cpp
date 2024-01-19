/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
    string _getHostName(string startUrl_) {
        int pos = min(startUrl_.size(), startUrl_.find('/', 7));
        return startUrl_.substr(7, pos - 7);
    }
    void _crawl(string startUrl_, HtmlParser htmlParser_, std::unordered_set<string>& crawledUrls_) {
        crawledUrls_.emplace(startUrl_);
        string hostName = _getHostName(startUrl_);
        for (const auto& url : htmlParser_.getUrls(startUrl_)) {            
            if (_getHostName(url) == hostName && !crawledUrls_.count(url))
                _crawl(url, htmlParser_, crawledUrls_);
        }
    }
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        unordered_set<string> crawledUrls;
        _crawl(startUrl, htmlParser, crawledUrls);
        vector<string> vec(crawledUrls.begin(), crawledUrls.end());
        return vec;
    }
};