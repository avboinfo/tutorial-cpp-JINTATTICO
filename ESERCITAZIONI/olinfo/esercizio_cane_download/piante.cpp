#include <vector>
#include <algorithm>

int pollice_verde(int N, std::vector<int> H) {
    std::sort(H.begin(), H.end(), std::greater<int>());

    int count = 0;
    for (int i = 0; i < N - 1; i++) {
        count += (H[i] > H[i + 1]);
    }

    return N - count;
}