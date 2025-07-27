#include <immintrin.h>
#include <stdio.h>

int main() {
    float a_vals[8]   = {1, 2, 3, 4, 5, 6, 7, 8};
    float b_vals[8]   = {11, 12, 13, 14, 15, 16, 17, 18};
    float mask_vals[8]= {0, -1, 0, -1, 0, -1, 0, -1}; // 正数选a，负数选b

    __m256 a = _mm256_loadu_ps(a_vals);
    __m256 b = _mm256_loadu_ps(b_vals);
    __m256 mask = _mm256_loadu_ps(mask_vals);

    __m256 result = _mm256_blendv_ps(a, b, mask);

    float out[8];
    _mm256_storeu_ps(out, result);

    for (int i = 0; i < 8; ++i) {
        printf("result[%d] = %f\n", i, out[i]);
    }
    return 0;
}