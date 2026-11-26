
#include <iostream>
#include <cstring>
#include <chrono>
#include <utility>
using namespace std;
using namespace chrono;

class String
{
private:
    char* data;
    size_t length;

public:
    String(const char* str = "")
    {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }

    // Copy Constructor
    String(const String& other)
    {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    // Move Constructor
    String(String&& other) noexcept
    {
        data = other.data;
        length = other.length;

        other.data = nullptr;
        other.length = 0;
    }

    // Copy Assignment
    String& operator=(const String& other)
    {
        if (this != &other)
        {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    // Move Assignment
    String& operator=(String&& other) noexcept
    {
        if (this != &other)
        {
            delete[] data;
            data = other.data;
            length = other.length;

            other.data = nullptr;
            other.length = 0;
        }
        return *this;
    }

    // Display
    void display()
    {
        if (data != nullptr)
            cout << data << endl;
    }

    ~String()
    {
        delete[] data;
    }
};

// Perfect Forwarding
template <typename T>
void process(T&& value)
{
    cout << "Perfect Forwarding Result: ";
    cout << forward<T>(value) << endl;
}

int main()
{
    String original("Hello World");

    const int n = 100000;

    // Copy Operation Benchmark
    auto start1 = high_resolution_clock::now();

    for (int i = 0; i < n; i++)
    {
        String copy(original);
    }

    auto end1 = high_resolution_clock::now();

    auto copyTime =
        duration_cast<milliseconds>(end1 - start1).count();

    // Move Operation Benchmark
    auto start2 = high_resolution_clock::now();

    for (int i = 0; i < n; i++)
    {
        String temp("Hello World");
        String moved(move(temp));
    }

    auto end2 = high_resolution_clock::now();

    auto moveTime =
        duration_cast<milliseconds>(end2 - start2).count();

    process("Perfect Forwarding Example");

    cout << "Copy Operation Time: "
         << copyTime << " milliseconds" << endl;

    cout << "Move Operation Time: "
         << moveTime << " milliseconds" << endl;

    cout << "Note: The benchmark values will vary depending on the "
         << "processor, compiler, optimization level, and system configuration."
         << endl;

    return 0;
}
