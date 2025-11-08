#include <iostream>
#include <array>

template<typename T, size_t N, size_t M>
class Matrice {
private:
    T data[N][M] = {}; // initialisation à 0
public:
    Matrice() = default;
    Matrice(std::initializer_list<std::initializer_list<T>> init) {
        size_t i = 0;
        for (auto row : init) {
            size_t j = 0;
            for (auto val : row) data[i][j++] = val;
            i++;
        }
    }

    T& operator()(size_t i, size_t j) { return data[i][j]; }

    Matrice operator+(const Matrice& other) {
        Matrice res;
        for (size_t i = 0; i < N; ++i)
            for (size_t j = 0; j < M; ++j)
                res.data[i][j] = data[i][j] + other.data[i][j];
        return res;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrice& mat) {
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < M; ++j) os << mat.data[i][j] << " ";
            os << "\n";
        }
        return os;
    }
};
