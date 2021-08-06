#include <fftw3.h>
#include "fft.hpp"

#include <vector>

template <typename T,size_t N>
Fft<T,N>::Fft()
{
    plan_to_td = fftw_plan_dft_c2r_1d(N,fd,td,FFTW_ESTIMATE);
    plan_to_fd = fftw_plan_dft_r2c_1d(N,td,fd,FFTW_ESTIMATE);

    // TODO: use std::array
    fd = static_cast<fftw_complex*>( fftw_malloc(sizeof(fftw_complex)*(N/2+1)));
}

template <typename T,size_t N>
Fft<T,N>::~Fft()
{
    fftw_destroy_plan(plan_to_td);
    fftw_destroy_plan(plan_to_fd);
    // TODO: Do we need to call `fftw_free`?
}

template <typename T,size_t N>
const ft_vec<T> Fft<T,N>::to_fd_old(ft_span<T> inp_td)
{
    ft_vec<T> f;
    return f;
}

template <typename T,size_t N>
const fftw_complex* Fft<T,N>::to_fd(std::span<T> inp_td)
{
    td=inp_td.data();
    fftw_plan p {fftw_plan_dft_r2c_1d(N,td,fd,FFTW_ESTIMATE)};
    fftw_execute(p);
    return fd;
}

template class Fft<double,4>;
template class Fft<double,8>;
