
/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/min-stack/?envType=problem-list-v2&envId=stack
 * Created at: 15/03/2025
 */

import java.util.Stack;

/**
 * Approach: Use two stacks to implement MinStack
 * I use array to store the value of stack and a int variable to store the top
 * pointer. Beside that, I also use another array to keep track the indices of
 * min values in stack.
 *
 * Time complexity: O(1)
 * Space complexity: O(n)
 */

class MinStack {
	Stack<Integer> st, minSt;

	public MinStack() {
		st = new Stack<>();
		minSt = new Stack<>();
	}

	public void push(int val) {
		st.push(val);
		if (minSt.empty()) {
			minSt.push(val);
		} else {
			minSt.push(Math.min(st.peek(), minSt.peek()));
		}
	}

	public void pop() {
		st.pop();
		minSt.pop();
	}

	public int top() {
		return st.peek();
	}

	public int getMin() {
		return minSt.peek();
	}
}

class main {
	public static void main(String[] args) {
		MinStack st = new MinStack();
		st.push(-2);
		st.push(0);
		st.push(-3);
		System.out.println("Min: " + st.getMin());
		st.pop();
		System.out.println("Top: " + st.top());
		System.out.println("Min: " + st.getMin());
	}
}
