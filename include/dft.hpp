#ifndef DFT_HPP
#define DFT_HPP

#include "ft.hpp"

template <typename T>
class Dft : public ft<T>
{
public:
    Dft();
    const ft_vec<T> to_fd_old(ft_span<T> td) override;
private:
    const std::vector<ft_vec<T>> dft_matrix(size_t size);
};

#endif // DFT_HPP
