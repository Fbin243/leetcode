/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/roman-to-integer/?envType=study-plan-v2&envId=top-interview-150
 * Created at: 26/04/2025
 */

function intToRoman(num: number): string {
  const valueSymbols: [number, string][] = [
    [1000, "M"],
    [900, "CM"],
    [500, "D"],
    [400, "CD"],
    [100, "C"],
    [90, "XC"],
    [50, "L"],
    [40, "XL"],
    [10, "X"],
    [9, "IX"],
    [5, "V"],
    [4, "IV"],
    [1, "I"],
  ];
  let res = "";

  for (const [value, symbol] of valueSymbols) {
    while (num >= value) {
      num -= value;
      res += symbol;
    }
  }

  return res;
}
