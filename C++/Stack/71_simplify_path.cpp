/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/simplify-path/description/?envType=problem-list-v2&envId=stack
 * Created at: 11/03/2025
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * Approach 1: Stack (My approach)
 * I just iterate over the array and try to check case by case.
 * If the letter is period, it has two cases:
 * - Current dir: "./"
 * - Parent dir: "../"
 * If the letter is slash, we omit the redundant consecutive slashes
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

string simplifyPath1(string path) {
    stack<char> st;
    int n = path.length();
    if (path[n - 1] != '/') {
        n++;
        path += '/';
    }

    for (int i = 0; i < n; i++) {
        if (i != 0 && st.empty()) {
            st.push('/');
        }
        if (!st.empty()) {
            char top = st.top();
            // Period
            if (path[i] == '.' && top == '/') {
                if (i < n - 1 && path[i + 1] == '/') {
                    st.pop();
                    continue;
                } else if (i < n - 2 && path[i + 1] == '.' &&
                           path[i + 2] == '/') {
                    st.pop();
                    i += 2;
                    while (!st.empty() && st.top() != '/') st.pop();
                    continue;
                }
            }

            // Slash
            if (path[i] == '/') {
                while (!st.empty() && st.top() == '/') st.pop();
            }
        }
        st.push(path[i]);
    }

    string res;
    while (!st.empty()) {
        res = st.top() + res;
        st.pop();
    }

    if (res.length() > 1 && res[res.length() - 1] == '/') {
        res.pop_back();
    }

    return res;
}

/**
 * Approach 2: Stack (In the clever way, split by "/")
 * Split the array by "/" and then check for each strings. We omit it if it's
 * empty or "." (current dir) and pop the stack if it's ".." (parent dir).
 * Otherwise, we keep putting the string into the stack.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

string simplifyPath2(string path) {
    stack<string> st;
    stringstream ss(path);
    string dir;
    while (getline(ss, dir, '/')) {
        if (dir.empty() || dir == ".")
            continue;
        else if (dir == "..") {
            if (!st.empty()) st.pop();
        } else
            st.push(dir);
    }
    string res;
    while (!st.empty()) {
        res = "/" + st.top() + res;
        st.pop();
    }

    return res.empty() ? "/" : res;
}

int main() {
    string path = "/.../a/../b/c/../d/./";
    cout << simplifyPath1(path);
    cout << simplifyPath2(path);
    return 0;
}