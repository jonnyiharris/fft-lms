#include <iostream>
#include <vector>
#include "dft.hpp"

using namespace std;

int main()
{
    Dft<double> dft {};
    ft_vec<double> td {1,2,3,0};
    for ( auto fd_elem : dft.to_fd(td) )
    {
        std::cout << fd_elem << " " << std::endl;
    }
    return 0;
}
