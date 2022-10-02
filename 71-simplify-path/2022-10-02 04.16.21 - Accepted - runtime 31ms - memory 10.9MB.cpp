class Solution {
    int size;
//     string getFileOrDirName(string& path, int& i) {
//         if (i >= size) return "";
//         string result = "";
        
//         while (i < size && path[i] != '/') {
//             result += path[t];
//             ++i;
//         }
        
//         return result;
//     }
    // string findSlashes()
public:
    string simplifyPath(string path) {
        path += "/";
        size = path.size();
        stack<string> st;
        int i = 0;
        int first = -1, second = -1;
        
        while (i < size) {
            if (path[i] == '/') {
                if (first == -1) first = i;
                else second = i;
            }
            if (first != -1 && second != -1) {
                string temp = path.substr(first + 1, second - first - 1);
                cout<<temp<<endl;
                
                if (temp == "..") {
                    if (!st.empty()) {
                        st.pop();
                        cout<<"popped"<<endl;
                    }
                }
                else if (!temp.empty() && temp != ".") {
                    st.push(temp);
                    cout<<"pushed"<<endl;
                }
                
                first = second;
                second = -1;
            }
            ++i;
        }
        
        string result = "";
        
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }
        return result.empty()? "/" : result;
    }
};