
#include <iostream>
#include <fstream>
#include <cstring>
#include <memory>
using namespace std;

// Custom Allocator
template <typename T>
class CustomAllocator
{
public:
    using value_type = T;

    CustomAllocator() {}

    template <typename U>
    CustomAllocator(const CustomAllocator<U>&) {}

    T* allocate(size_t n)
    {
        cout << "Allocating memory for "
             << n << " object(s)\n";

        return static_cast<T*>(
            ::operator new(n * sizeof(T))
        );
    }

    void deallocate(T* p, size_t n)
    {
        cout << "Deallocating memory\n";
        ::operator delete(p);
    }
};

// File Record Structure
struct FileRecord
{
    char fileName[50];
    int fileSize;
};

int main()
{
    cout << "MINI FILE SYSTEM SIMULATOR" << endl;

    FileRecord file;

    cout << "Enter File Name: ";
    cin >> file.fileName;

    cout << "Enter File Size (KB): ";
    cin >> file.fileSize;

    ofstream outFile("filesystem.dat", ios::binary | ios::app);

    outFile.write(reinterpret_cast<char*>(&file), sizeof(file));
    outFile.close();

    cout << "File record added successfully." << endl;

    cout << "\n--- File System Records ---" << endl;

    ifstream inFile("filesystem.dat", ios::binary);

    while (inFile.read(reinterpret_cast<char*>(&file), sizeof(file)))
    {
        cout << "File Name : " << file.fileName << endl;
        cout << "File Size : " << file.fileSize << " KB" << endl;
        cout << "--------------------------" << endl;
    }

    inFile.close();

    return 0;
}