# Cent Savings

To host a regional contest like NWERC a lot of preparation is necessary: organizing rooms and computers, making a good problem set, inviting contestants, designing T-shirts, booking hotel rooms and so on. I am responsible for going shopping in the supermarket.

When I get to the cash register, I put all my n items on the conveyor belt and wait until all the other customers in the queue in front of me are served. While waiting, I realize that this supermarket recently started to round the total price of a purchase to the nearest multiple of 10 cents (with 5 cents being rounded upwards). For example, 94 cents are rounded to 90 cents, while 95 are rounded to 100.

It is possible to divide my purchase into groups and to pay for the parts separately. I managed to find d dividers to divide my purchase in up to d + 1 groups. I wonder where to place the dividers to minimize the total cost of my purchase. As I am running out of time, I do not want to rearrange items on the belt.

## Input Format

The input consists of:

* one line with two integers _n_ (1 ≤ _n_ ≤ 2000) and _d_ (1 ≤ _d_ ≤ 20), the number of items and the number of available dividers;
* one line with _n_ integers _p_<sub>1</sub>, . . . , _p_<sub>n</sub> (0 ≤ _p_<sub>i</sub> ≤ 10<sup>4</sup> for 1 ≤ _i_ ≤ _n_), the prices of the items in cents. The prices are given in the same order as the items appear on the belt.

## Output Format

Output the minimum amount of money needed to buy all the items, using up to _d_ dividers.

## Sample Input 1

    5 1
	13 21 55 60 42

## Sample Output 1

    190

## Sample Input 2

    5 2
	1 1 1 1 1

## Sample Output 2

    0
