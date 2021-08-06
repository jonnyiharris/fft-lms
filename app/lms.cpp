#include <iostream>
#include <iomanip>
#include <vector>
#include <fftw3.h>
#include "fft.hpp"

using namespace std;

int main()
{
    Fft<double,8> ft {};
//    ft_vec<double> td {1,2,3,0};
//    std::vector<fftw_complex> fd[4];

//    auto fd {ft.to_fd(td)};

    const size_t N {8};
    double td[] {1,2,3,-1};
    fftw_complex *fd;

    fd = static_cast<fftw_complex*>( fftw_malloc(sizeof(fftw_complex)*(N/2+1)));

    fftw_plan plan_to_fd {fftw_plan_dft_r2c_1d(N,td,fd,FFTW_ESTIMATE)};

    fftw_execute(plan_to_fd);
    std::cout << std::setw(16) << "real";
    std::cout << " | ";
    std::cout << std::setw(16) << "imag";
    std::cout << std::endl;

    std::cout << "---------------- | ----------------";
    std::cout << std::endl;

    for (size_t i {}; i < N/2+1; i++)
    {
        std::cout << std::setw(16) << fd[i][0];
    std::cout << " | ";
        std::cout << std::setw(16) << fd[i][1];
        std::cout << std::endl;
    }
    return 0;
}
