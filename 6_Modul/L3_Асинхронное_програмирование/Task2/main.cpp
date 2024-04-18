#include <iostream>
#include <future>
#include <thread>
using namespace std;

template<typename Iterator, typename Func>
void parallel_for_each(Iterator first, Iterator last, Func f)
{
    auto curr_size = std::distance(first, last);
   // ptrdiff_t const curr_size = last - first;
    if (!curr_size)
        return;
    if (curr_size == 1)
    {
        f(*first);
        return;
    }
    auto mid = first;
    std::advance(mid, curr_size / 2);
    //Iterator const mid = first + (curr_size / 2);
    std::future<void> ft_res = std::async(std::launch::deferred, parallel_for_each<Iterator, Func>, mid, last, f);
   parallel_for_each(first, mid, f);
   ft_res.get(); 
}

void print(int n) {
    std::cout << n << ' ';
}

int main() {
    std::vector<int> v{ 3, -4, 2, -8, 15, 267 };

    auto lamda_print = [](const int& n) { std::cout << n << ' '; };

    std::cout << "before: ";
    parallel_for_each(v.cbegin(), v.cend(), lamda_print);
    std::cout << '\n';

    // инкремент
    parallel_for_each(v.begin(), v.end(), [](int& n) { n++; });

    std::cout << "after++: ";
    std::for_each(v.cbegin(), v.cend(), print);
    std::cout << '\n';

}

