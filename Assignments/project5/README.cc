# HugeNumber Project
## Author: Hoang Nguyen

### Input validation rules
* I chose to throw an exception because it is much simpler, because I can just use the throw keyword and the type of exceptions provided by the C++ standard library. It would be two lines statements if I have to print an error then terminate.

### My internal representation
* The digits are store in a std::vector<int>. The most significant digit is store at the leftmost (at index 0), and you will read it from left to right.

### How sign is stored
* The sign is store as a boolean (bool isNegative). If isNegative = true, it mean the HugeNumber is negative and vice versa.

### How addition/subtraction/multiplication are implemented
For arithmetic, I created 3 private helper functions to be reused in addition and subtraction.
They are compareMagnitude, addMagnitude, and subtractMagnitude. They represent when the sign are
ignored, just like doing arithmetic on absolute values.

* CompareMagnitude
  * I implemented similar to strcmp
  * if less than 0, it mean a < b
  * if greater than 0, it mean a > b
  * if equals 0, it mean a == b
  * How I implemented is to compare their sizes. If sizes equals, compare each digit of the numbers at the same indices.
* AdditionMagnitude:
  * Because I stored most significant digit on the left, I have to traverse the digits from right to left (start at size() -1).
  * When we add, the sum = top + bottom + carry
  * The digit to store = sum % 10
  * The carry is = sum / 10
  * We will perform this until either of the number indices is less than 0 (note that: if one of the number's index reached < 0 before the other number, we just set it to zero)
  * At the end make sure to check if carry != 0 and push that carry value as digit
  * Because I pushed the least significant number (right to left), I reversed the vector so it behave like how I designed it.

* SubtractionMagnitude:
  * We will assume the "operator-" will always check and make sure the lhs is larger and rhs is smaller (using the compareMagnitude), before calling this function.
  * The top value will always larger, and bottom value will always be smaller
  * Similar to addition start from right and then traverse to left
  * Because top is always larger, we will traverse until index of top < 0 (note if bottom digits ran out, we use zero)
    * Ex: 911 - 11 = 911 - 011
  * I have an integer variable called "borrow", it value is either 0 (no borrow) or 1 (borrow)
  * First find the diff = top - bottom - borrow
    * if diff is not negative, then digit = diff, borrow = 0
    * if diff is negative, then digit = diff + 10, borrow = 1
  * After we done, reverse and then normalize it.

#### Addition
* There are 2 cases for addition:
1) Case 1: Both numbers have the same sign 
   * In this case, the result is the sum of absolute value of a and b (|a| + |b|). For the sign, because they have the same sign, we can just return either of their sign.
2) Case 2: Different signs 
   * In this case, I realized that the result is the difference between the absolute value of larger and absolute value of smaller (|larger| - |smaller|. Larger mean the absolute value is larger, Smaller mean the absolute value is smaller. This is why I created the "compareMagnitude" to get the larger and smaller values. The result will be |larger| - |smaller|, and the sign is the sign of the larger (using compareMagnitude)

#### Subtraction
* I realized that subtraction (a - b) is just addition with the second value sign flipped (a - flipped sign b)
* Ex: 
  * 99 - 98 = 99 + (-98)
  * 99 - (-98) = 99 + 98
* What I did was flipped the sign of b (b.isNegative = !b.isNegative) and then reuses the operator+ I implemented above.

#### Multiplication
* Multiply each digit of bottom number with every digits of top number to get a partial result
* Multiplication is similar to addition
  * product = a[i] * b[i] + carry
  * digit = product % 10
  * carry = product / 10
* With the exception is that each time we shift to the left to process the next digit of bottom number, we have to add N 0s based on the index of the digit
  * Ex: let say bottom number is 111 * 123
  * for digit 3, zero push_back(0) for its partial
  * for digit 2, one push_back(0) for its partial
  * for digit 1, two push_back(0) for its partial 
  * so on...
* Each time we get the value of partial we add it to total, total = total + partial (remember to reverse partial first because we push right most element into array first).
* So at the final total is the product result
* The sign of the product is that: same signs = positive, different signs = negative, I used the XOR (operator^) for this.
* Then normalized and done!
