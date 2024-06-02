class StringIterator {
    string _comStr;
    int _comStrSize;
    int _pos;
    char _lastChar;
    int _lastCharFreq;
public:
    StringIterator(string compressedString) {
        _comStr = compressedString;
        _comStrSize = _comStr.size();
        _pos = 0;
        _lastChar = ' ';
        _lastCharFreq = 0;
    }
    
    char next() {
        if (!hasNext()) return ' ';
        if (_lastCharFreq <= 0) {
            int num = 0;
            _lastChar = _comStr[_pos];
            ++_pos;
            while (_pos < _comStrSize) {
                if (isalpha(_comStr[_pos])) break;
                num = num * 10 + (_comStr[_pos] - '0');
                ++_pos;
            }
            _lastCharFreq = num;
        }
        --_lastCharFreq;
        return _lastChar;
    }
    
    bool hasNext() {
        return _lastCharFreq || _pos < _comStrSize - 1;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */