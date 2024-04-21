#include <iostream>

int countDistinctWaysToClimbStairs(int n) {
  if( n < 0)
    return 0;
  if(n == 0)
    return 1;
  else 
    return countDistinctWaysToClimbStairs(n-1) + countDistinctWaysToClimbStairs(n-2);
}


int main() {
  std::cout << countDistinctWaysToClimbStairs(5) << std::endl;
  return 0;
}