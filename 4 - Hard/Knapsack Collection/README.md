# Knapsack Collection

Gerald’s job is to welcome the teams for this year’s NWERC at the airport in Linköping. One of his duties is to stand at the luggage carousel and collect all the knapsacks that the teams are bringing. Gerald is a lazy person, so he just stands at the same position of the carousel and waits for bags to pass by so he can pick them up.

The baggage carousel consists of s luggage slots, numbered in ascending order from 0 to _s_ − 1. Since the baggage carousel is cyclic, luggage slots _s_ − 1 and 0 also lie side by side. The carousel turns in such a way that if Gerald stands in front of slot _i_ at some point in time, he will stand in front of slot (_i_ + 1) _mod_ _s_ one time unit later.

In the beginning Gerald prepares a huge baggage cart at some position and stands there to wait for luggage. When a knapsack arrives in front of Gerald, he needs _t_ time units to take it and put it on the baggage cart. After these t time units he is ready to pick up another knapsack. As long as there are remaining knapsacks on the luggage carousel, Gerald always takes the next one to arrive at his position as soon as he is ready after putting away the previous one.

Now Gerald wonders about the effect of his choice of position on the time it will take him to finish this task. It is up to you to help Gerald calculate the minimum, maximum, and average time to pick up all knapsacks, taken over all _s_ possible slots, which can appear in front of Gerald after preparation. Time starts when he has prepared the baggage cart at some slot of the baggage carousel and ends after he has put the last knapsack on the cart.

## Input Format

The input consists of:

* one line with three integers _n_ (1 ≤ _n_ ≤ 2000), _s_ (1 ≤ _s_ ≤ 107) and _t_ (1 ≤ _t_ ≤ 107), where _n_ is the number of knapsacks to pick up, _s_ is the number of slots of the carousel, and _t_ is the number of time units Gerald needs to pick up a knapsack from the carousel and put it on the cart;
* one line with _n_ integers _k_<sub>1</sub>, . . . , _k_<sub>n</sub> (0 ≤ _k_<sub>i</sub> ≤ _s_ − 1 for 1 ≤ _i_ ≤ _n_), the slots of the knapsacks.

There may be several knapsacks stacked on top of each other in the same slot, but Gerald can still only pick up one knapsack at a time.

## Output Format

Output three lines of output containing the minimum, maximum, and average time to pick up all the luggage, over all _s_ positions. The average time should be output as a reduced fraction in the form _p_/_q_.

## Sample Input 1

    7 10 10000000
    0 0 0 0 0 0 1

## Sample Output 1

    70000001
    70000009
    350000027/5

## Sample Input 2

    10 10 3
    0 0 2 2 4 4 6 6 8 8

## Sample Output 2

    39
    40
    79/2

## Sample Input 3

    9 10000000 1
    0 7 2 3 4 5 6 1 8

## Sample Output 3

    9
    10000000
    12500021249991/2500000
