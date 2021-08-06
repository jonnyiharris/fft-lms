#include <complex>
#include <iostream>
#include <iomanip>
#include <vector>
#include <fftw3.h>
#include "fft.hpp"

using namespace std;

int main()
{
    const size_t N {8};
    Fft<double,N> ft {};
    Fft<double,N> ft_filter {};

    double td[] {2,0,0,0,0,0,0,0};
    double filter[] {1,2,3,-1,0,0,0,0};

    auto *fd {reinterpret_cast<const complex<double>*>(ft.to_fd(td))};
    auto *fd_filter {reinterpret_cast<const complex<double>*>(ft_filter.to_fd(filter))};

    ft.print_vec(fd);
    ft.print_vec(fd_filter);

    std::array<complex<double>,N> result {};

    size_t i {};
    for ( auto &element : result )
    {
        element = fd[i] * fd_filter[i];
        ++i;
    }

    ft.print_vec(result.data());

    return 0;
}
