/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/basic-calculator-ii/
 * Created at: 17/03/2025
 */

function calculate(s: string): number {
  const stack: number[] = [];
  let num = 0;
  let sign = "+";
  s += "+";

  for (let c of s) {
    if (isDigit(c)) {
      num = num * 10 + Number(c);
    }

    if (!isDigit(c) && c !== " ") {
      if (sign === "+") stack.push(num);
      if (sign === "-") stack.push(-num);
      if (sign === "*") stack.push((stack.pop() || 0) * num);
      if (sign === "/") stack.push(Math.trunc(stack.pop() || 0) / num);

      num = 0;
      sign = c;
    }
  }

  return stack.reduce((acc, val) => acc + val, 0);
}

function isDigit(ch: string): boolean {
  return !isNaN(Number(ch)) && ch.trim() != "";
}

console.log(calculate(" 2+5 / 2 "));
