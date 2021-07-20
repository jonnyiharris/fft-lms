#ifndef DFT_HPP
#define DFT_HPP

#include "ft.hpp"

template <typename T>
class Dft : ft<T>
{
public:
    Dft();
    const ft_vec<T> to_fd(ft_span<T> td) override;
private:
    const std::vector<ft_vec<T>> dft_matrix(size_t size);
};

#endif // DFT_HPP
