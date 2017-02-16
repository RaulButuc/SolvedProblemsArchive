# AlgorithmicCrush

You are given a list of size _N_, initialized with zeroes. You have to perform _M_ operations on the list and output the maximum of final values of all the _N_ elements in the list. For every operation, you are given three integers _a_, _b_ and _k_ and you have to add value _k_ to all the elements ranging from index _a_ to _b_ (both inclusive).

## Input Format

First line will contain two integers _N_ and _M_ separated by a single space.
Next _M_ lines will contain three integers _a_, _b_ and _k_ separated by a single space.
Numbers in list are numbered from 1 to _N_.

## Constraints

* 3 <= _N_ <= 10<sup>7</sup>
* 1 <= _M_ <= 2 x 10<sup>5</sup>
* 1 <= _a_ <= _b_ <= _N_
* 0 <= _k_ <= 10<sup>9</sup>

## Output Format

A single line containing maximum value in the updated list.

## Sample Input

    5 3
    1 2 100
    2 5 100
    3 4 100
    
## Sample Output

    200

## Explanation

After first update list will be 100 100 0 0 0.   
After second update list will be 100 200 100 100 100.   
After third update list will be 100 200 200 200 100.   
So the required answer will be 200.
