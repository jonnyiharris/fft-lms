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


template <typename T>
class ft
{
public:
    const ft_vec<T> virtual to_fd_old(ft_span<T> td) = 0;
    const virtual fftw_complex *to_fd(std::span<T> inp_td) = 0;

    void print_vec(ft_span<T> span){
        std::cout << std::setw(16) << "real";
        std::cout << " | ";
        std::cout << std::setw(16) << "imag";
        std::cout << std::endl;

        std::cout << "---------------- | ----------------";
        std::cout << std::endl;

        for ( auto fd_elem : span )
        {
            std::cout << std::setw(16) << fd_elem.real();
        std::cout << " | ";
            std::cout << std::setw(16) << fd_elem.imag();
            std::cout << std::endl;
        }
    };
};
#endif // FT_HPP
