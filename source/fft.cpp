#include <fftw3.h>
#include "fft.hpp"

#include <vector>

template <typename T,int N>
Fft<T,N>::Fft()
{
    plan_to_fd = fftw_plan_dft_c2r_1d(N,fd,td,FFTW_ESTIMATE);
    plan_to_td = fftw_plan_dft_r2c_1d(N,td,fd,FFTW_ESTIMATE);

}

template <typename T,int N>
Fft<T,N>::~Fft()
{
    fftw_destroy_plan(plan_to_td);
    fftw_destroy_plan(plan_to_fd);
    // TODO: Do we need to call `fftw_free`?
}

template <typename T,int N>
const ft_vec<T> Fft<T,N>::to_fd_old(ft_span<T> inp_td)
{
    ft_vec<T> f;
    return f;
}

template <typename T,int N>
const fftw_complex* Fft<T,N>::to_fd(std::span<T> inp_td)
{
    td=inp_td.data();
    fftw_execute(plan_to_fd);
    return fd;
}

template class Fft<double,4>;
template class Fft<double,8>;
