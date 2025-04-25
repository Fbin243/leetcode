/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/decode-string/description/?envType=problem-list-v2&envId=stack
 * Created at: 17/03/2025
 */

function decodeString(s: string): string {
  const stack: Array<string | number> = [];
  let curString = "";
  let num = 0;

  for (const c of s) {
    if (/\d/.test(c)) {
      // Accumulate multi-digit numbers
      num = num * 10 + Number(c);
    } else if (c === "[") {
      // Push the current number and string to the stack
      stack.push(num);
      stack.push(curString);
      num = 0;
      curString = "";
    } else if (c === "]") {
      // Pop the previous string and repeat count
      const prevString = stack.pop() as string;
      const rep = stack.pop() as number;
      curString = prevString + curString.repeat(rep);
    } else {
      curString += c;
    }
  }

  return curString;
}
