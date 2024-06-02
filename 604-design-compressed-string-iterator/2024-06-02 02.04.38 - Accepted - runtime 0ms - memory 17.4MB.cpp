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
            int i = _pos;
            bool freqCalculated = false;
            // while (i < _comStrSize && !freqCalculated) {
                // if (isalpha(_comStr[i])) {
                    _lastChar = _comStr[i];
                    ++i;
                // }
                // else {
                    while (i < _comStrSize) {
                        if (isalpha(_comStr[i])) break;
                        num = num * 10 + (_comStr[i] - '0');
                        ++i;
                    }
                    // freqCalculated = true;
                    _lastCharFreq = num;
                // }
            // }
            _pos = i;
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