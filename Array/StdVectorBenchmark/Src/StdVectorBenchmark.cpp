#include <stdlib.h>
#include <cassert>
#include <chrono>
#include <iostream>
#include <memory>
#include <numeric>
#include <vector>

class Timer
{
public:
    Timer()
        : start_(std::chrono::high_resolution_clock::now())
    {
    }

    ~Timer()
    {
        const auto finish = std::chrono::high_resolution_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::microseconds>(finish - start_).count() << " us" << std::endl;
    }

private:
    const std::chrono::high_resolution_clock::time_point start_;
};

template <class T>
class Vector final
{
    T* data_;
    size_t capacity_;
    size_t size_;
public:
    explicit Vector(size_t capacity)
        : data_(static_cast<T*>(malloc(capacity * sizeof(T))))
        , capacity_(capacity)
        , size_(0)
    {
    }

    ~Vector()
    {
        free(data_);
    }

    T* begin() const
    {
        return data_;
    }

    T* end() const
    {
        return data_ + size_;
    }

    void push_back(const T& value)
    {
        if (size_ < capacity_)
        {
            data_[size_++] = value;
        }
        else
        {
            slow_push_back(value);
        }
    }

    void clear() noexcept
    {
        size_ = 0;
    }

private:
    void slow_push_back(const T& value)
    {
        const auto newCapacity = capacity_ * 2;
        data_ = static_cast<T*>(realloc(data_, newCapacity * sizeof(T)));
        if (!data_)
            throw std::bad_alloc();

        capacity_ = newCapacity;
        data_[size_++] = value;
    }
};

template <class Container>
int test(Container& data, size_t n)
{
    const auto Repeats = 5;

    // prevention of optimization
    int64_t result = 0;

    {
        Timer t;
        for (auto r = 0; r < Repeats; ++r)
        {
            // prevention of optimization
            int seed = time(0);

            for (auto i = 0; i < n; ++i)
            {
                data.push_back(i + seed);
            }

            result += std::accumulate(data.begin(), data.end(), 0);

            data.clear();
        }
    }

    return result;
}

int main(int argc, char* argv[])
{
    using T = int32_t;

    const auto n = 64 * 1024 * 1024;

    std::vector<T> v1;
    v1.reserve(n);
    const auto r1 = test(v1, n);

    Vector<T> v2(n);
    const auto r2 = test(v2, n);

    std::cout << r1 + r2 << std::endl;

    return 0;
}