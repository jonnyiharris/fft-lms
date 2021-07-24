#include "fft.hpp"

#include <vector>

template <typename T>
Fft<T>::Fft()
{}

// TODO: return a span
template <typename T>
const ft_vec<T> to_fd(ft_span<T> td)
{
    ft_vec<int> fd {};
    return fd;
}

template class Fft<double>;
