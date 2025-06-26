#include <iostream>
#include <cstring>
using namespace std;

class Vector
{
private:
    char *name;
    int x, y, z;

public:
    // Default constructor with name parameter
    Vector(const char *n)
    {
        int l = strlen(n);
        name = new char[l + 1];
        strcpy(name, n);
        x = 0;
        y = 0;
        z = 0;
    }

    // Parameterized constructor
    Vector(const char *n, int a, int b, int c)
    {
        int l = strlen(n);
        name = new char[l + 1];
        strcpy(name, n);
        x = a;
        y = b;
        z = c;
    }

    // Copy constructor
    Vector(const Vector &other)
    {
        int l = strlen(other.name);
        name = new char[l + 1];
        strcpy(name, other.name);
        x = other.x;
        y = other.y;
        z = other.z;
    }

    // Destructor
    ~Vector()
    {
        delete[] name;
    }

    // Setter methods
    void setX(int a)
    {
        x = a;
    }

    void setY(int b)
    {
        y = b;
    }

    void setZ(int c)
    {
        z = c;
    }

    void setName(const char *n)
    {
        delete[] name;  // Free old memory
        int l = strlen(n);
        name = new char[l + 1];
        strcpy(name, n);
    }

    // Getter methods (const correctness)
    int getX() const
    {
        return x;
    }

    int getY() const
    {
        return y;
    }

    int getZ() const
    {
        return z;
    }

    const char *getName() const
    {
        return name;
    }

    // Assignment operator (improved with proper memory management)
    Vector &operator=(const Vector &rhs)
    {
        if (this != &rhs)
        {
            // Copy vector components
            x = rhs.x;
            y = rhs.y;
            z = rhs.z;
            
            // Handle name copying properly
            delete[] name;
            int l = strlen(rhs.name);
            name = new char[l + 1];
            strcpy(name, rhs.name);
        }
        return *this;
    }

    // Scalar multiplication operator (modifies current object)
    Vector &operator*(int m)
    {
        x *= m;
        y *= m;
        z *= m;
        return *this;
    }
};


// Stream output operator
ostream &operator<<(ostream &output, const Vector &v)
{
    output << v.getName() << ": " << v.getX() << "x" << showpos 
           << v.getY() << "y" << v.getZ() << "z" << noshowpos << endl;
    return output;
}

// Cross product operator
Vector operator^(const Vector &v1, const Vector &v2)
{
    Vector temp("temp");
    temp.setX(v1.getY() * v2.getZ() - v1.getZ() * v2.getY());
    temp.setY(v1.getZ() * v2.getX() - v1.getX() * v2.getZ());
    temp.setZ(v1.getX() * v2.getY() - v1.getY() * v2.getX());
    return temp;
}

// Equality operator (fixed the bug)
bool operator==(const Vector &v1, const Vector &v2)
{
    return (v1.getX() == v2.getX() && 
            v1.getY() == v2.getY() && 
            v1.getZ() == v2.getZ());
}

// Scalar multiplication (scalar * vector)
Vector operator*(int m, const Vector &v)
{
    Vector result(v);  // Use copy constructor
    result.setX(m * result.getX());
    result.setY(m * result.getY());
    result.setZ(m * result.getZ());
    return result;
}

// Component-wise multiplication
Vector operator*(const Vector &v1, const Vector &v2)
{
    Vector temp("temp");
    temp.setX(v1.getX() * v2.getX());
    temp.setY(v1.getY() * v2.getY());
    temp.setZ(v1.getZ() * v2.getZ());
    return temp;
}


int main()
{
    // Initialize vectors
    Vector v1("v1", 1, 2, 3);
    Vector v2("v2", 4, 5, -6);
    Vector v3("Result1");
    Vector v4("Result2", -27, 18, -3);

    // Print initial vectors
    cout << v1;     // Print the components of vector v1
    cout << v2;     // Print the components of vector v2

    // Calculate cross product
    v3 = v1 ^ v2;   // Calculate the cross product of vector v1 and v2
    cout << v3;     // Print the modified components of vector v3 (Name: Result1)

    // Check equality
    if (v3 == v4)
        cout << "Vectors are equal" << endl;
    else
        cout << "Vectors are not equal" << endl;

    // Scalar multiplication (vector * scalar)
    v1 = v1 * 2;    // Multiply each component of vector v1 with the given value
    cout << v1;     // Print the modified components of vector v1

    // Scalar multiplication (scalar * vector)
    v2 = 2 * v2;    // Multiply each component of vector v2 with the given value
    cout << v2;     // Print the modified components of vector v2

    // Component-wise multiplication
    v3 = v1 * v2;   // Multiply each component of vector v1 with corresponding component of v2
    cout << v3;     // Print the modified components of vector v3 (Name: Result1)

    // Check equality again
    if (v3 == v4)
        cout << "Vectors are equal" << endl;
    else
        cout << "Vectors are not equal" << endl;

    return 0;
}

/* Output:
v1: 1x+2y+3z
v2: 4x+5y-6z
Result1: -27x+18y-3z
Vectors are equal
v1: 2x+4y+6z
v2: 8x+10y-12z
Result1: 16x+40y-72z
Vectors are not equal
echo "# CSE108-Object-Oriented-Programming" >> README.md
git init
git add .
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/kabirshahriar468/CSE108-Object-Oriented-Programming.git
git push -u origin main
*/
