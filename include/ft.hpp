#ifndef FT_HPP
#define FT_HPP

#include <vector>
#include <span>
#include <complex>

template <typename T>
using ft_vec = std::vector<std::complex<T>>;

template <typename T>
using ft_span = std::span<std::complex<T>>;


template <typename T>
class ft
{
public:
    const ft_vec<T> virtual to_fd(ft_span<T> td) = 0;
};
#endif // FT_HPP
