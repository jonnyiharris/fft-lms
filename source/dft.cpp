#include <iostream>
#include <numeric>
#include <cmath>

#include "dft.hpp"

template <typename T>
Dft<T>::Dft()
{}

template <typename T>
const std::vector<ft_vec<T>> Dft<T>::dft_matrix(size_t size)
{
    using namespace std::complex_literals;

    std::vector<ft_vec<T>> matrix {};

    for ( size_t c {}; c < size; ++c )
    {
        ft_vec<T> col {};
        for ( size_t r {}; r < size; ++r )
        {
            T val {2 * M_PI * c * r / size};
            col.push_back(
                        std::cos(val) - 1i * std::sin(val)
            );
        }
        matrix.push_back(col);
    }

    return matrix;
}

template <typename T>
const ft_vec<T> Dft<T>::to_fd(ft_span<T> td)
{
    std::cout << "DFT!" << std::endl;
    ft_vec<T> fd {};

    auto matrix {dft_matrix(td.size())};

    for ( size_t n {}; n < td.size(); ++n)
    {
        std::complex<T> fd_sample {};
        for ( size_t k {}; auto td_sample : td )
        {
            fd_sample += td_sample * matrix[n][k];
            ++k;
        }
        fd.push_back(fd_sample);
    }

    return fd;
}

template class Dft<double>;
