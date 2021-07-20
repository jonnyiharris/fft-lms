#ifndef FFT_HPP
#define FFT_HPP

#include "ft.hpp"

template <typename T>
class Fft : ft<T>
{
public:
    Fft();
    std::vector<T> to_fd() override;
};

#endif // FFT_HPP
