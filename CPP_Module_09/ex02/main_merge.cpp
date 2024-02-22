#include <bits/stdc++.h>
using namespace std;
 
int		jacobsthal(int n)
{
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	else
		return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}
 
// Driven Program
int main()
{
	std::cout << jacobsthal(4) << std::endl;
    return 0;
}