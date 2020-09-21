#include "../src/AStar.h"
#include <iostream>


char map[20*10+1] = "####################"
                    "#........#.........#"
                    "#..................#"
                    "#........#.........#"
                    "#........#.........#"
                    "#........#.........#"
                    "#........#.........#"
                    "#........#.........#"
                    "#........#.........#"
                    "####################";


struct Point {
  int x, y;
};

int gwx, gwy;
Grid *grid;

void InitializeGrid()
{
  int cols = 20; // width
  int rows = 10; // height
  Grid::movementType movement = Grid::movementType::EIGHT_DIRECTIONS;
// set obstacles
  vector<Node> obstacles;
  for (int j = 0; j < rows; ++j)
    for (int i = 0; i < cols; ++i)
      if (map[j*cols+i] == '#')
        obstacles.push_back(Node(i, j));
// create grid
  grid = new Grid(cols, rows, movement, obstacles);
}

bool pathhaspoint(std::vector<Point> path, int x, int y)
{
  for (auto point : path)
    if (point.x == x && point.y == y)
      return true;
  return false;
}

int main()
{
  std::cout << "hello world" << std::endl;
// convert your map to an astar grid
  InitializeGrid();
// set start pos, end pos
  Node start = Node(1, 1);
  Node goal = Node(18, 8);
// create pathfinder with your grid
  AStar astar(grid);
// get the path
  vector<Node> nodepath = astar.search(start, goal);
// convert the path to your own position representation
  vector<Point> path;
  for (Node node : nodepath)
    path.push_back({node.getX(), node.getY()});
// draw the output to console
  for (int j = 0; j < 10; ++j) {
    for (int i = 0; i < 20; ++i) {
      if (i == start.getX() && j == start.getY())
        std::cout << "S";
      else if (i == goal.getX() && j == goal.getY())
        std::cout << "E";
      else if (pathhaspoint(path, i, j))
        std::cout << "X";
      else
        std::cout << map[j * 20 + i];
    }
    std::cout << std::endl;
  }

  delete grid;
  return 0;
}