#ifndef D2F48D60_CCE7_4049_8A56_2ADDF140192E
#define D2F48D60_CCE7_4049_8A56_2ADDF140192E

#include <cuda_runtime.h>

#include <cstddef>
#include <cstdint>

#include "cusz/type.h"
#include "kernel/hist.hh"
#include "kernel/histsp.hh"

template <typename T>
uint32_t count_outlier(T* in, size_t inlen, int radius, void* stream);

template <psz_policy policy, typename T>
void hist(
    bool optim, T* whole_numbers, size_t const len, uint32_t* hist,
    size_t const bklen, float* t, cudaStream_t stream)
{
  if (optim)
    psz::histsp<policy, T>(whole_numbers, len, hist, bklen, t, stream);
  else
    psz::histogram<policy, T>(whole_numbers, len, hist, bklen, t, stream);
}

#endif /* D2F48D60_CCE7_4049_8A56_2ADDF140192E */
