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

    double td[] {1,2,3,-1,0,0,0,0};

    const fftw_complex *fd {ft.to_fd(td)};

    ft.print_vec(fd);
    return 0;
}
