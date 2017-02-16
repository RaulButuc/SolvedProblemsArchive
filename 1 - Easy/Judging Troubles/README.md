# Judging Troubles

The NWERC organisers have decided that they want to improve the automatic grading of the submissions for the contest, so they now use two systems: DOMjudge and Kattis. Each submission is judged by both systems and the grading results are compared to make sure that the systems agree. However, something went wrong in setting up the connection between the systems, and now the jury only knows all results of both systems, but not which result belongs to which submission! You are therefore asked to help them figure out how many results could have been consistent.

## Input Format

The input consists of:

* one line with one integer _n_ (1 ≤ n ≤ 10<sup>5</sup>), the number of submissions;
* _n_ lines, each with a result of the judging by DOMjudge, in arbitrary order;
* _n_ lines, each with a result of the judging by Kattis, in arbitrary order.
Each result is a string of length between 5 and 15 characters (inclusive) consisting of lowercase letters.

## Output Format

Output one line with the maximum number of judging results that could have been the same for both systems.

## Sample Input

    5
    correct
    wronganswer
    correct
    correct
    timelimit
    wronganswer
    correct
    timelimit
    correct
    timelimit
    
## Sample Output

    4
