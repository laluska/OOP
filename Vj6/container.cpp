#include <iostream>
#include "container.h"

container::container(std::size_t initial_capacity)
    : data(nullptr), m_size(0), m_capacity(initial_capacity)
{
    if (m_capacity > 0) data = new int[m_capacity];
    std::cout << "Konstruktor\n";
}

container::container(const container& other)
    : data(nullptr), m_size(other.m_size), m_capacity(other.m_capacity)
{
    if (m_capacity > 0) {
        data = new int[m_capacity];
        for (std::size_t i = 0; i < m_size; i++) data[i] = other.data[i];
    }
    std::cout << "Copy konstruktor\n";
}

container::container(container&& other) noexcept
    : data(other.data), m_size(other.m_size), m_capacity(other.m_capacity)
{
    other.data = nullptr;
    other.m_size = 0;
    other.m_capacity = 0;
    std::cout << "Move konstruktor\n";
}

container::~container() {
    delete[] data;
    std::cout << "Destruktor\n";
}

void container::push_back(int value) {
    if (m_size == m_capacity) {
        std::size_t newcap = (m_capacity == 0) ? 1 : m_capacity * 2;
        int* newdata = new int[newcap];
        for (std::size_t i = 0; i < m_size; i++) newdata[i] = data[i];
        delete[] data;
        data = newdata;
        m_capacity = newcap;
    }
    data[m_size++] = value;
}

std::size_t container::size() const { return m_size; }
std::size_t container::capacity() const { return m_capacity; }
int container::at(std::size_t index) const { return data[index]; }

void container::clear() {
    m_size = 0;
}

container test(container c) {
    return c;
}

int main() {
    container c1;
    c1.push_back(1);
    c1.push_back(2);
    c1.push_back(3);

    container c2 = c1;

    container c3 = std::move(c1);

    container c4 = test(c2);

    container c5 = test(container());

    for (int i = 0; i < 20; i++) c2.push_back(i);

    for (std::size_t i = 0; i < c2.size(); i++) {
        std::cout << i << ": " << c2.at(i) << "\n";
    }

    return 0;
}

