/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/basic-calculator-ii/description/?envType=problem-list-v2&envId=stack
 * Created at: 15/03/2025
 */

 #include <bits/stdc++.h>

 using namespace std;
 
 bool isDigit(char c) { return '0' <= c && c <= '9'; }
 
 int eval(int num1, int num2, char op) {
   if (op == '*') return num1 * num2;
   if (op == '/') return num1 / num2;
   if (op == '+') return num1 + num2;
   return -1;
 }
 
 int calculate(string s) {
   stack<int> nums;
   stack<char> ops;
 
   int n = s.length();
 
   for (int i = 0; i < n; i++) {
     if (s[i] == ' ') continue;
     if (!isDigit(s[i])) {
       ops.push(s[i]);
       continue;
     }
 
     int num = s[i] - '0';
     while (i + 1 < n && isDigit(s[i + 1])) {
       num = num * 10 + s[i + 1] - '0';
       i++;
     }
     nums.push(num);
     if (!ops.empty()) {
       char op = ops.top();
       if (op == '-') {
         nums.pop();
         ops.pop();
         nums.push(-num);
         ops.push('+');
       } else if (op == '*' || op == '/') {
         int num1 = nums.top();
         nums.pop();
         int num2 = nums.top();
         nums.pop();
         nums.push(eval(num2, num1, op));
         ops.pop();
       }
     }
   }
 
   while (!ops.empty()) {
     int num1 = nums.top();
     nums.pop();
     int num2 = nums.top();
     nums.pop();
     nums.push(eval(num2, num1, ops.top()));
     ops.pop();
   }
 
   return nums.top();
 }
 
 int main() {
   string s = " 3+5 / 2 ";
   cout << "Result: " << calculate(s) << endl;
 
   return 0;
 }