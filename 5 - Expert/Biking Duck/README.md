# Biking Duck

Gladstone Gander is walking through Duckburg and needs to get to his date with Daisy Duck as soon as possible. If he doesn’t get there in time, Donald might show up and take his place instead.

Duckburg has recently started providing a very eco-friendly way of public transport: bikes. At many bike stations throughout the city, one can pick up a free bike, ride it to another bike station, and drop it there. This gives Gladstone two ways of transportion: on foot or by bike. Biking is faster, of course, but he must pick up and leave the bikes at the designated stations. Gladstone can walk or bike between any two points in a straight line.

Gladstone possesses a map of the (rectangular) center of Duckburg. His current position is on this map and so is the meeting point with Daisy. The map also contains the locations of all bike stations within the boundaries of the map.

There can be way more bike stations though, that are not within the boundaries of the map. Considering his luck, you can assume that the moment Gladstone walks (or bikes) off the map, he encounters a bike station if that suits him well. The bike stations not on the map can be located anywhere outside the map, they do not have to lie on integer coordinates.

That leaves Gladstone with the task of figuring out which route to take. Can you help him out? Given the map and his infinite amount of luck, what is the fastest time to his date with Daisy?

## Input Format

The input consists of:

* one line with two integers _v_<sub>walk</sub> and _v_<sub>bike</sub> (1 ≤ _v_<sub>walk</sub> ≤ _v_<sub>bike</sub> ≤ 1000), the speeds of walking and of biking;
* one line with four integers _x_<sub>1</sub>, _y_<sub>1</sub>, _x_<sub>2</sub> and _y_<sub>2</sub> (-10<sup>6</sup> ≤ _x_<sub>1</sub> < _x_<sub>2</sub> ≤ 10<sup>6</sup>; -10<sup>6</sup> ≤ _y_<sub>1</sub> < _y_<sub>2</sub> ≤ 10<sup>6</sup>), the bounding coordinates of the map of the center of Duckburg;
* one line with one integer _m_ (3 ≤ _m_ ≤ 50), the number of vertices of the outer polygon;
* one line with two integers _x_<sub>G</sub> and _y_<sub>G</sub>, Gladstone’s position;
* one line with two integers _x_<sub>D</sub> and _y_<sub>D</sub>, Daisy’s position;
* one line with one integer _n_ (0 ≤ _n_ ≤ 1000), the number of known bike stations;
* _n_ lines with two integers _x_<sub>station</sub>, _y_<sub>station</sub> each, the coordinates of the known bike stations.

All coordinates are on the map of the center, i.e., _x_<sub>1</sub> ≤ _x_ ≤ _x_<sub>2</sub> and _y_<sub>1</sub> ≤ _y_ ≤ _y_<sub>2</sub>.

## Output Format

Output one line with the shortest possible time for Gladstone to get to Daisy. Your answer should have an absolute or relative error of at most 10<sup>−6</sup>.

## Sample Input 1

    1 8
	0 0 10 10
	5 1
	5 9
	3
	5 8
	2 2
	9 6

## Sample Output 1

    3.000000000

## Sample Input 2

    5 100
	0 -100000 100000 0
	5 -30000
	40000 -5
	0

## Sample Output 2

    501.9987496
