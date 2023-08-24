#include "merge_insertion_sort.hpp"

#include <algorithm>
#include <ctime>

static std::vector<int> generate_random_vec(std::size_t size) {

    std::srand(std::time(0));

    std::vector<int> randomVector;

    for (std::size_t i = 0; i < size; ++i) {
        randomVector.push_back(std::rand() % 3000);
    }
    return randomVector;
}

int main(void) {

    std::vector<int> vector = generate_random_vec(3000);
    std::vector<int> vec_copy = vector;

    clock_t start = clock();
    std::vector<int> sorted_vector = sort_vec(vector);
    clock_t end = clock();

    container_is_sorted(sorted_vector);

    double elapsed_time_vec =
        static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Vector of " << sorted_vector.size()
                << " elements was sorted in " << elapsed_time_vec << " µs"
                << " (c++98 - Merge Insertion Sort)" << std::endl;

    start = clock();
    std::sort(vec_copy.begin(), vec_copy.end());
    end = clock();

    double elapsed_time_builtin_vec =
        static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Vector of " << sorted_vector.size()
                << " elements was sorted in " << elapsed_time_builtin_vec << " µs"
                << " (c++98 - Builtin std::sort())" << std::endl;

    return 0;
}
