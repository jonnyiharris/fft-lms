#ifndef FT_HPP
#define FT_HPP

#include <vector>
#include <span>
#include <complex>

#include <fftw3.h>

#include <iostream>
#include <iomanip>

template <typename T>
using ft_vec = std::vector<std::complex<T>>;

template <typename T>
using ft_span = std::span<std::complex<T>>;


template <typename T,size_t N>
class ft
{
public:
    const ft_vec<T> virtual to_fd_old(ft_span<T> td) = 0;
    const virtual fftw_complex *to_fd(std::span<T> inp_td) = 0;

    void print_vec(const fftw_complex *fd){
        std::cout << std::setw(16) << "real";
        std::cout << " | ";
        std::cout << std::setw(16) << "imag";
        std::cout << std::endl;

        std::cout << "---------------- | ----------------";
        std::cout << std::endl;

        for (size_t i {}; i < 8/2+1; i++)
        {
            std::cout << std::setw(16) << fd[i][0];
        std::cout << " | ";
            std::cout << std::setw(16) << fd[i][1];
            std::cout << std::endl;
        }
    };
};
#endif // FT_HPP
