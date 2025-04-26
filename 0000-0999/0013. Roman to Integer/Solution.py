'''
/**
 * Author: Fbin
 * Link:https://leetcode.com/problems/roman-to-integer/?envType=study-plan-v2&envId=top-interview-150
 * Created at: 26/04/2025
 */
'''

class Solution:
    def intToRoman(self, num: int) -> str:
        value_symbols = [
            (1000, 'M'), (900, 'CM'), (500, 'D'), (400, 'CD'),
            (100, 'C'), (90, 'XC'), (50, 'L'), (40, 'XL'),
            (10, 'X'), (9, 'IX'), (5, 'V'), (4, 'IV'), (1, 'I')
        ]
        res = ""
        for value, symbol in value_symbols:
            count = num // value
            res += symbol * count
            num %= value
        return res