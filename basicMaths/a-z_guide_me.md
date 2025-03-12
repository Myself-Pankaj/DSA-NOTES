# Number Theory Guide

## 1. Digit Counting
- Initialize a counter variable with zero.
- Run a while loop until `n` becomes `0`.
- Inside the loop:
  - Divide `n` by `10`.
  - Increase the counter by `1`.
- Continue until `n` becomes `0`, and the counter will give the total number of digits.

[Code Link](./digitCounting.cpp)

---

## 2. Reverse a Number
- Initialize `num` with zero.
- Run a while loop until `n` becomes `0`.
- Inside the loop:
  - Extract the last digit using `n % 10`.
  - Multiply `num` by `10` and add the last digit.
  - Update `n` by `n / 10`.
- Continue until `n` becomes `0`, and `num` will store the reversed number.

[Code Link](./reverseNumber.cpp)

---

## 3. Check if a Number is Palindrome
- Reverse the number.
- Compare it with the original number.
- If both are equal, it is a palindrome; otherwise, it is not.

[Code Link](./isNumPalindrome.cpp)

---

## 4. GCD (Greatest Common Divisor)
### Brute Force Approach:
- Find the minimum of `n1` and `n2`.
- Run a loop from `1` to `min(n1, n2)`.
- Check if both `n1` and `n2` are divisible by `i`, update `gcd = i`.
- The greatest common factor at the end is the GCD.

### Euclidean Algorithm:
- Run a while loop until `n2` becomes `0`.
- Inside the loop:
  - Compute `remainder = n1 % n2`.
  - Update `n1 = n2`, `n2 = remainder`.
- When `n2` becomes `0`, `n1` is the GCD.

[Code Link](./gcd.cpp)

---

## 5. LCM (Least Common Multiple)
- Use the formula: `LCM(n1, n2) = (n1 * n2) / GCD(n1, n2)`.

[Code Link](./lcm.cpp)

---

## 6. Armstrong Number
- Count the digits to determine the power.
- Extract each digit and raise it to the power.
- Sum the values.
- If the sum equals the original number, it is an Armstrong number.

[Code Link](./amstrong.cpp)

---

## 7. Prime Number Check
- If `n == 1`, it's not prime.
- If `n == 2`, it's prime.
- If `n % 2 == 0` or `n % 3 == 0`, it's not prime.
- Run a loop from `5` to `N` with steps of `+6`.
- If `n` is divisible by any number in this range, it is not prime.
- Otherwise, it is prime.

[Code Link](./amstrong.cpp)

