#include <iostream>
#include <cstring>

// to save time, let's lump all the cleaning into one loop
std::string cleanString(std::string &dirty)
{
  std::string clean = "";
  for (int i = 0; i < dirty.length(); i++)
  {
    dirty[i] = tolower(dirty[i]);
    if (isspace(dirty[i]))
      continue;
    else
      clean[i] = dirty[i];
  }
  return clean;
}

// inplace algorithm for determining if a string is a palindrome
bool isPalindrome(std::string pal)
{
  int left, right;
  left = 0;
  right = pal.length() - 1;
  while (left <= right)
  {
    if (pal[left] != pal[right])
    {
      return 0;
    }
    ++left;
    --right;
  }
  return 1;
}

int main()
{
  // create batch of test cases
  std::string test1 = "racecar";
  std::string test2 = "Civic";
  std::string test3 = "Hannah";
  std::string test4 = "Never odd or even";
  std::string test5 = "Mad Adam";

  // clean the string
  test1 = cleanString(test1);
  test2 = cleanString(test2);
  test3 = cleanString(test3);
  test4 = cleanString(test4);
  test5 = cleanString(test5);

  // print the palindrome
  std::cout << isPalindrome(test1) << std::endl;
  std::cout << isPalindrome(test2) << std::endl;
  std::cout << isPalindrome(test3) << std::endl;
  std::cout << isPalindrome(test4) << std::endl;
  std::cout << isPalindrome(test5) << std::endl;

  return 0;
}