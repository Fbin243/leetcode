import java.util.Stack;

/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/basic-calculator-ii/
 * Created at: 16/03/2025
 */

class Solution {
	public int calculate(String s) {
		Stack<Integer> st = new Stack<>();
		int num = 0;
		char sign = '+';
		s += '+';
		for (int i = 0; i < s.length(); i++) {
			char ch = s.charAt(i);
			if (Character.isDigit(ch)) {
				num = num * 10 + ch - '0';
			}

			if (!Character.isDigit(ch) && ch != ' ') {
				System.out.println("Num: " + num + '\n');
				if (sign == '+') {
					st.push(num);
				}
				if (sign == '-') {
					st.push(-num);
				}
				if (sign == '*') {
					st.push(st.pop() * num);
				}
				if (sign == '/') {
					st.push(st.pop() / num);
				}
				num = 0;
				sign = ch;
			}
		}

		int res = 0;
		while (!st.empty()) {
			res += st.pop();
		}

		return res;
	}
}
