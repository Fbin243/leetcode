/**
 * Author: Fbin
 * Created at: 13/04/2025
 * Link: https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=study-plan-v2&envId=top-interview-150
 */

class RandomizedSet {
  private map: Map<number, number>;
  private arr: number[];

  constructor() {
    this.map = new Map();
    this.arr = [];
  }

  // To insert an element, we can just check if it exists in the map
  insert(val: number): boolean {
    if (this.map.has(val)) return false;

    this.arr.push(val);
    this.map.set(val, this.arr.length - 1);
    return true;
  }

  // To remove an element, we can swap it with the last element
  remove(val: number): boolean {
    if (!this.map.has(val)) return false;

    const idx = this.map.get(val)!;
    const last = this.arr[this.arr.length - 1];

    // Swap with last and update map
    [this.arr[idx], this.arr[this.arr.length - 1]] = [
      this.arr[this.arr.length - 1],
      this.arr[idx],
    ];
    this.map.set(last, idx);

    // Remove last
    this.arr.pop();
    this.map.delete(val);
    return true;
  }

  // Leverage the fact that arr is a random array
  // to get a random element in O(1)
  getRandom(): number {
    const randIdx = Math.floor(Math.random() * this.arr.length);
    return this.arr[randIdx];
  }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * var obj = new RandomizedSet()
 * var param_1 = obj.insert(val)
 * var param_2 = obj.remove(val)
 * var param_3 = obj.getRandom()
 */
