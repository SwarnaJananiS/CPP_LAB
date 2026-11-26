
#include <iostream>
using namespace std;

// Template class for distance conversion
template <typename T>
class Distance
{
private:
    T meters;

public:
    constexpr Distance(T m) : meters(m) {}

    constexpr T toMeters() const
    {
        return meters;
    }

    constexpr T toKilometers() const
    {
        return meters / 1000;
    }

    constexpr T toCentimeters() const
    {
        return meters * 100;
    }
};

int main()
{
    Distance<double> d(5000);

    cout << "Distance in Meters: "
         << d.toMeters() << " m" << endl;

    cout << "Distance in Kilometers: "
         << d.toKilometers() << " km" << endl;

    cout << "Distance in Centimeters: "
         << d.toCentimeters() << " cm" << endl;

    return 0;
}
