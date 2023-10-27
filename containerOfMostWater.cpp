#include <iostream>
/*Container of most water
There are n vertical lines drawn such that the two endpoints
of the ith line are (i, 0) and (i, height[i]) creating a
graph of lines. Find the largest container of water
that the lines can hold.*/

struct pair
{
  int leftIndex;
  int rightIndex;
};

// find the two points that create the largest area
struct pair findMaxArea(int heightList[], int length)
{
  struct pair coords;
  struct pair answer;
  int calcArea = -1;
  int maxArea = -1;
  coords.leftIndex = 0;
  coords.rightIndex = length - 1;

  // Algorithm
  while (coords.leftIndex <= coords.rightIndex)
  {
    int containerLength = coords.rightIndex - coords.leftIndex;

    // check which side is shorter and chose that one because of spillover
    //  default to left side if equal
    if (heightList[coords.leftIndex] <= heightList[coords.rightIndex])
    {
      calcArea = containerLength * heightList[coords.leftIndex];
      if (calcArea > maxArea)
      {
        answer = coords;
        maxArea = calcArea;
      }
      coords.leftIndex++;
    }
    else if (heightList[coords.rightIndex] <= heightList[coords.leftIndex])
    {
      calcArea = containerLength * heightList[coords.rightIndex];
      if (calcArea > maxArea)
      {
        answer = coords;
        maxArea = calcArea;
      }
      coords.rightIndex--;
    }
  }
  return answer;
}

int main()
{
  struct pair answer;
  int heightList[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  int length = sizeof(heightList) / sizeof(heightList[0]);

  answer = findMaxArea(heightList, length);
  std::cout << "[" << answer.leftIndex << "," << answer.rightIndex << "]\n";
  return 0;
}