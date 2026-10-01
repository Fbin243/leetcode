class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push('|');
        for(char a: s) {
            char b = st.top();
            if(isPair(b, a)) st.pop();
            else st.push(a);
        }

        return st.size() == 1;
    }

    bool isPair(char a, char b) {
        if(a == '(' && b == ')') return true; 
        if(a == '[' && b == ']') return true; 
        if(a == '{' && b == '}') return true; 
        return false;
    }
};