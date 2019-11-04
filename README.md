# A* SFML Algorithm
 Simple grid-based pathfinding! Algorithm is implemented using C++17 but graphics is made with help of SFML in 2.5.1 version.
 A* is useful when we need to get a path of an entity to the goal point. Such a situation usually happens in games.
 
 ![Grid screen](https://raw.githubusercontent.com/Whittler23/A-star-algorithm-SFML/master/resources/astarGridScreen.jpg)
 
## Demonstration video

<a href="https://www.youtube.com/watch?v=Y1-zPZfGz_U" target="_blank"><img src="https://img.youtube.com/vi/Y1-zPZfGz_U/0.jpg" 
alt="Program demonstration" width="600" height="350"/></a>

## Tile colors

Every type of tile is represented by specified color:

- ![#00b159](https://placehold.it/15/00b159/000000?text=+) ---> Starting node
- ![#d11141](https://placehold.it/15/d11141/000000?text=+) ---> Targeted node
- ![#00aedb](https://placehold.it/15/00aedb/000000?text=+) ---> Path node
- ![#000000](https://placehold.it/15/000000/000000?text=+) ---> Obstacle node
- ![#ffffff](https://placehold.it/15/ffffff/000000?text=+) ---> Default node

## Usage example

By clicking on the grid with LPM, the user can set targeted ( ![#d11141](https://placehold.it/15/d11141/000000?text=+) ) and starting node ( ![#00b159](https://placehold.it/15/00b159/000000?text=+) ) alternately. If both are set, the user can press "SOLVE" button. After that, the program computes the path which can be seen as cyan tiles ( ![#00aedb](https://placehold.it/15/00aedb/000000?text=+) ). In the top left corner, there's an informational window which displays time which was required to perform the calculation.

By pressing the grid with PPM, the user sets the obstacles ( ![#000000](https://placehold.it/15/000000/000000?text=+) ) for the path.

User can reset obstacles by pressing "RESET OBSTACLES" button.

And reset the path by pressing "RESET" button.

In the bottom right corner there's a switch button which can change between "DIAG ON" and "DIAG OFF" which means diagonal search on the grid.

## Links I used

[AStar Algorithm Explanation Part 1](https://www.youtube.com/watch?v=-L-WgKMFuhE)\
[AStar Wikipedia page](https://en.wikipedia.org/wiki/A*_search_algorithm)\
[A Star (A*) Path Finding C++](https://dev.to/jansonsa/a-star-a-path-finding-c-4a4h)
