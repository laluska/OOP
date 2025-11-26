#ifndef CONTAINER_H
#define CONTAINER_H

#include <cstddef>

class container {
private:
    int* data;
    std::size_t m_size;
    std::size_t m_capacity;

public:
    container(std::size_t initial_capacity = 0);
    container(const container& other);
    container(container&& other) noexcept;
    ~container();

    void push_back(int value);
    std::size_t size() const;
    std::size_t capacity() const;
    int at(std::size_t index) const;
    void clear();
};

container test(container c);

#endif
