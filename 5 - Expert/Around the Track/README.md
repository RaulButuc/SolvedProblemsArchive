# Around the Track

In order to compare race tracks, we wish to compute their lengths. A racetrack is strictly two-dimensional (no elevation). It is described by two simple polygons, where one is completely contained inside the other. The track is the region between these two polygons. We define the length of the track as the absolute minimum distance that one needs to travel in order to complete a lap. This could involve traveling on the very edge of the track and arbitrarily sharp cornering (see Figure A.1).

![FigA1](https://s3.amazonaws.com/hr-challenge-images/0/1448834023-23201b5337-a0.png "Figure A1")

Figure A.1: Illustration of sample input number 3 together with the shortest route around the track (dashed).

## Input Format

The input consists of:

* one line with one integer _n_ (3 ≤ _n_ ≤ 50), the number of vertices of the inner polygon;
* _n_ lines, the _i_<sup>th</sup> of which contains two integers _x_<sub>i</sub> and _y_<sub>i</sub> (−5000 ≤ _x_<sub>i</sub>, _y_<sub>i</sub> ≤ 5000): the coordinates of the _i_<sup>th</sup> vertex of the inner polygon;
* one line with one integer _m_ (3 ≤ _m_ ≤ 50), the number of vertices of the outer polygon;
* _m_ lines, the _i_<sup>th</sup> of which contains two integers _x_<sub>i</sub> and _y_<sub>i</sub> (−5000 ≤ _x_<sub>i</sub>, _y_<sub>i</sub> ≤ 5000): the coordinates of the _i_<sup>th</sup> vertex of the outer polygon;

For both polygons, the vertices are given in counterclockwise order. The borders of the two polygons do not intersect or touch each other.

## Output Format

Output one line with one floating point number: the length of the race track. Your answer should have an absolute or relative error of at most 10<sup>−6</sup>.

## Sample Input 1

    3
	1 1
	2 1
	1 2
	3
	0 0
	4 0
	0 4

## Sample Output 1

    3.41421356237309

## Sample Input 2

    5
	1 1
	5 1
	5 5
	3 3
	1 5
	4
	0 0
	6 0
	6 6
	0 6

## Sample Output 2

    16

## Sample Input 3

    5
	1 1
	5 1
	5 5
	3 3
	1 5
	5
	0 0
	6 0
	6 6
	3 4
	0 6

## Sample Output 3

    16.4721359549996
