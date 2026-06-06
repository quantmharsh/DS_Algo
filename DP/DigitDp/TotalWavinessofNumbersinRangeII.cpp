// //Leetcode:3753. Total Waviness of Numbers in Range II
// You are given two integers num1 and num2 representing an inclusive range [num1, num2].

// The waviness of a number is defined as the total count of its peaks and valleys:

// A digit is a peak if it is strictly greater than both of its immediate neighbors.
// A digit is a valley if it is strictly less than both of its immediate neighbors.
// The first and last digits of a number cannot be peaks or valleys.
// Any number with fewer than 3 digits has a waviness of 0.
// Return the total sum of waviness for all numbers in the range [num1, num2].
 

// Example 1:

// Input: num1 = 120, num2 = 130

// Output: 3

// Explanation:

// In the range [120, 130]:

// 120: middle digit 2 is a peak, waviness = 1.
// 121: middle digit 2 is a peak, waviness = 1.
// 130: middle digit 3 is a peak, waviness = 1.
// All other numbers in the range have a waviness of 0.
// Thus, total waviness is 1 + 1 + 1 = 3.

// Example 2:

// Input: num1 = 198, num2 = 202

// Output: 3

// Explanation:

// In the range [198, 202]:

// 198: middle digit 9 is a peak, waviness = 1.
// 201: middle digit 0 is a valley, waviness = 1.
// 202: middle digit 0 is a valley, waviness = 1.
// All other numbers in the range have a waviness of 0.
// Thus, total waviness is 1 + 1 + 1 = 3.

// Example 3:

// Input: num1 = 4848, num2 = 4848

// Output: 2

// Explanation:

// Number 4848: the second digit 8 is a peak, and the third digit 4 is a valley, giving a waviness of 2.

 

// Constraints:

// 1 <= num1 <= num2 <= 1015​​​​​​​

//Approach : Digit DP
//Instead of checking every number individually, we build numbers digit by digit.
//The recursive function returns a pair:
//1. totalNumbers   -> Total valid numbers that can be formed from current state.
//2. totalWaviness  -> Total waviness contributed by all those numbers.
//
// Whenever we form three consecutive digits (prevPrev, prev, currentDigit),
// we can determine whether 'prev' is a peak or valley.
// If it is, then this peak/valley will exist for ALL numbers generated
// from the remaining recursion tree, so we add remainTotalNumbers.
//
// We use memoization only when:
// - tight (isDigitLimit) = false
// - leadingZero = false
// because only then the future depends purely on
// (curr_index, prevPrev, prev).
//
// T.C : O(D * 10 * 10 * 10)
//       D = number of digits (<= 16)
//       Effectively O(1) since max digits are fixed.
//
// S.C : O(D * 10 * 10)
//       For memoization tables.

class Solution {
public:
    typedef long long ll;

    string s;
    int n;

    //Stores:
    //dpTotalNumbers[pos][prevPrev][prev]
    //dpTotalWaviness[pos][prevPrev][prev]
    ll dpTotalNumbers[16][10][10];
    ll dpTotalWaviness[16][10][10];

    pair<ll, ll> solve(int curr_index,
                       int prevprev,
                       int prev,
                       bool isLeadingZero,
                       bool isDigitLimit) {

        //All digits processed.
        //One valid number formed and no extra waviness generated here.
        if (curr_index == n) {
            return {1, 0};
        }

        //Memoization lookup.
        if (!isDigitLimit && !isLeadingZero &&
            prevprev >= 0 && prev >= 0) {

            if (dpTotalNumbers[curr_index][prevprev][prev] != -1) {
                return {
                    dpTotalNumbers[curr_index][prevprev][prev],
                    dpTotalWaviness[curr_index][prevprev][prev]
                };
            }
        }

        //Maximum digit we can place.
        int digitLimit = isDigitLimit ? s[curr_index] - '0' : 9;

        ll totalNumbers = 0;
        ll totalWaiviness = 0;

        //Try placing every possible digit.
        for (int i = 0; i <= digitLimit; i++) {

            int newPrevPrev = prev;

            //Leading zero continues only if current digit is also zero.
            bool newIsLeadingZero = isLeadingZero && (i == 0);

            //Ignore leading zeros while tracking previous digits.
            int newPrev = newIsLeadingZero ? -1 : i;

            //Remain tight only if current chosen digit matches original number.
            bool newIsDigitLimit =
                isDigitLimit && ((s[curr_index] - '0') == i);

            auto [remainingTotalNumbers,
                  remainingTotalWaiviness] =
                solve(curr_index + 1,
                      newPrevPrev,
                      newPrev,
                      newIsLeadingZero,
                      newIsDigitLimit);

            //Once we have three valid digits,
            //check whether middle digit forms peak/valley.
            if (!newIsLeadingZero &&
                prev >= 0 &&
                prevprev >= 0) {

                bool isPeak = (prevprev < prev && prev > i);
                bool isValley = (prevprev > prev && prev < i);

                //Current peak/valley contributes to all future numbers.
                if (isPeak || isValley) {
                    totalWaiviness += remainingTotalNumbers;
                }
            }

            //Accumulate results from child recursion.
            totalNumbers += remainingTotalNumbers;
            totalWaiviness += remainingTotalWaiviness;
        }

        //Store only reusable states.
        if (!isDigitLimit && !isLeadingZero &&
            prevprev >= 0 && prev >= 0) {

            dpTotalNumbers[curr_index][prevprev][prev] =
                totalNumbers;

            dpTotalWaviness[curr_index][prevprev][prev] =
                totalWaiviness;
        }

        return {totalNumbers, totalWaiviness};
    }

    //Returns total waviness for all numbers in range [0...num].
    ll func(ll num) {

        //Numbers with less than 3 digits have waviness 0.
        if (num < 100) {
            return 0;
        }

        s = to_string(num);
        n = s.length();

        memset(dpTotalNumbers, -1, sizeof(dpTotalNumbers));
        memset(dpTotalWaviness, -1, sizeof(dpTotalWaviness));

        auto [totalNumbers, totalWaiviness] =
            solve(0, -1, -1, true, true);

        return totalWaiviness;
    }

    long long totalWaviness(long long num1, long long num2) {

        //Digit DP on range [num1, num2]
        return func(num2) - func(num1 - 1);
    }
};