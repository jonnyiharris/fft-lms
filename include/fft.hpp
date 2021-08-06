#ifndef FFT_HPP
#define FFT_HPP

#include <fftw3.h>
#include "ft.hpp"

template <typename T,int N>
class Fft : ft<T>
{
public:
    Fft();
    ~Fft();
    const ft_vec<T> to_fd_old(ft_span<T> inp_td) override;
    const fftw_complex *to_fd(std::span<T> inp_td) override;
private:
    fftw_plan plan_to_fd;
    fftw_plan plan_to_td;
    double *td;
    fftw_complex *fd;
};

#endif // FFT_HPP
