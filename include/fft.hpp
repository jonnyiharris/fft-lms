#ifndef FFT_HPP
#define FFT_HPP

#include "ft.hpp"

template <typename T>
class Fft : ft<T>
{
public:
    Fft();
    const ft_vec<T> to_fd(ft_span<T> td) override;
};

#endif // FFT_HPP
