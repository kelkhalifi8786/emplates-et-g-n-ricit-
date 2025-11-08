#include <iostream>
#include <vector>
#include <concepts>
#include <functional>

template<typename T>
concept Sortable = requires(T a, T b) {
    { a < b } -> std::convertible_to<bool>;
};

struct Asc {
    template<Sortable T>
    bool operator()(const T& a, const T& b) { return a < b; }
};

template<typename T, typename Comp = Asc>
void quickSort(std::vector<T>& vec, Comp comp = Comp{}) {
    if(vec.size() < 2) return;
    T pivot = vec[0];
    std::vector<T> less, greater;
    for(size_t i=1;i<vec.size();i++) {
        if(comp(vec[i],pivot)) less.push_back(vec[i]);
        else greater.push_back(vec[i]);
    }
    quickSort(less, comp);
    quickSort(greater, comp);
    vec.clear();
    vec.insert(vec.end(), less.begin(), less.end());
    vec.push_back(pivot);
    vec.insert(vec.end(), greater.begin(), greater.end());
}

int main() {
    std::vector<int> v{5,3,8,1};
    quickSort(v);
    for(auto x:v) std::cout << x << " ";
}
