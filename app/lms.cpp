#include <iostream>
#include <iomanip>
#include <vector>
#include "dft.hpp"

using namespace std;

int main()
{
    Dft<double> ft {};
    ft_vec<double> td {1,2,3,0};

    auto fd {ft.to_fd(td)};

    ft.print_vec(fd);
    return 0;
}
