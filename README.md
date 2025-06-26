# CSE108 - Object-Oriented Programming Language Sessional

## 📚 Course Overview
This repository contains all coursework, assignments, and practice exercises for CSE108 - Object-Oriented Programming Language Sessional. The course covers fundamental and advanced concepts of object-oriented programming using C++ and Java.

## 🗂️ Repository Structure

### 📁 01_Practice_Exercises
Collection of practice problems and exercises to reinforce OOP concepts.

#### C++ Practice Problems
- **C++ Problem B2.docx** - Problem statement for advanced C++ exercises
- **C++_Practice_1.pdf** - First set of C++ practice problems

#### 🔗 Inheritance and Template
- **Practice B1&B2/** - Advanced inheritance and template exercises
  - `Practice1.cpp` - Basic inheritance implementation
  - `Practice2.cpp` - Template class implementation
- **PracticeA1&A2/** - Fundamental inheritance concepts
  - `Practice1.cpp` - Single inheritance examples
  - `Practice2.cpp` - Multiple inheritance examples

#### ⚡ Operator Overloading
- **b1&b2.txt** - Problem statements for operator overloading
- **file1.txt** - Additional practice problems

#### 📍 Pointer Practice
Comprehensive pointer exercises (C/C++):
- `pointer1.c` to `pointer19.c` - Progressive pointer exercises
- `pointer14.cpp` - C++ specific pointer implementation
- `README.txt` - Instructions and explanations for pointer exercises

#### 📖 Week4 Practice
BookShop management system implementations:
- `Book.cpp` - Book class implementation
- `BookShop.cpp` - Basic bookshop functionality
- `BookShop_1.cpp` - Enhanced bookshop with inventory
- `BookShop_2.cpp` - Advanced bookshop with customer management
- `CSE108_Practice_Week4.pdf` - Week 4 practice problems

### 📁 02_Offline_Assignments
Major assignments and projects for the course.

#### 🎯 Offline Assignment 1
- `Offline_1.pdf` - Assignment specifications
- `offline1.cpp` - Solution implementation

#### 🎯 Offline Assignment 2
BookShop system development:
- `CSE108_Offline 2_Instructions.pdf` - Detailed assignment instructions
- `Book.cpp` - Book class with advanced features
- `BookShop.cpp` - Core bookshop implementation
- `BookShop_1.cpp` - Version 1 with basic features
- `BookShop_2.cpp` - Version 2 with enhanced features

#### 🎯 Offline Assignment 3
Vector mathematics implementation:
- `2005114.cpp` - Student submission (Vector class)
- `spec.cpp` - Specification and test cases
- `2005107.cpp` - **Enhanced Vector class with operator overloading**

#### 🎯 Offline Assignment 4
Java-based banking system:
- **Java_Offline_1/**
  - `Account.java` - Bank account class
  - `Branch.java` - Bank branch management
  - `TestMain.java` - Main testing class

### 📁 03_Practice_Java
Java programming practice exercises and projects.

#### ☕ Java Practice Sessions
- **Java_Practice_1/** - Basic Java OOP
  - `Author.java` - Author class implementation
  - `Book.java` - Book class in Java
  - `TestMain.java` - Test driver

- **Java_Practice_1_B/** - Invoice system
  - `Customer.java` - Customer management
  - `Invoice.java` - Invoice processing
  - `TestMain.java` - System testing

- **Java_Practice_2/** - Employee management
  - `Department.java` - Department class
  - `Employee.java` - Employee class
  - `TestMain.java` - Management system testing

- **B2_Practice1_submission/** - Advanced Java concepts
  - `Customer.java` - Enhanced customer class
  - `Invoice.java` - Advanced invoice system
  - `Merchant.java` - Merchant management
  - `TestMain.java` - Comprehensive testing

## 🚀 Key Projects

### Vector Mathematics System (Offline 3)
**File**: `02_Offline_Assignments/Offline_3/2005107.cpp`

A comprehensive C++ implementation of 3D vector mathematics featuring:

#### Features
- ✅ **Dynamic Memory Management** - Proper allocation/deallocation for vector names
- ✅ **Operator Overloading** - Complete set of mathematical operators
- ✅ **Cross Product Calculation** - 3D vector cross product implementation
- ✅ **Component-wise Operations** - Element-by-element vector operations
- ✅ **Scalar Multiplication** - Both `vector * scalar` and `scalar * vector`
- ✅ **Stream Output** - Formatted vector display with mathematical notation

#### Supported Operations
```cpp
Vector v1("v1", 1, 2, 3);
Vector v2("v2", 4, 5, -6);

// Cross product
Vector v3 = v1 ^ v2;

// Equality comparison
if (v1 == v2) { /* ... */ }

// Scalar multiplication
v1 = v1 * 2;        // vector * scalar
v2 = 2 * v2;        // scalar * vector

// Component-wise multiplication
Vector v4 = v1 * v2;
```

#### Output Format
```
v1: 1x+2y+3z
v2: 4x+5y-6z
Result1: -27x+18y-3z
```

### Banking System (Offline 4)
**Location**: `02_Offline_Assignments/Offline_4/Java_Offline_1/`

Java-based banking system with:
- Account management
- Branch operations
- Transaction processing

## 🛠️ Technologies Used

### Programming Languages
- **C++** - Core OOP concepts, memory management, operator overloading
- **Java** - Advanced OOP features, design patterns, collections

### Key Concepts Covered
- **Object-Oriented Programming**
  - Encapsulation
  - Inheritance
  - Polymorphism
  - Abstraction

- **C++ Specific**
  - Pointers and Dynamic Memory
  - Operator Overloading
  - Template Programming
  - Copy Constructors & Assignment Operators

- **Java Specific**
  - Exception Handling
  - Collections Framework
  - Interface Implementation
  - Package Management

## 📋 Prerequisites

### For C++ Projects
- GCC compiler (g++) or Visual Studio
- Basic understanding of C++ syntax
- Knowledge of memory management

### For Java Projects
- JDK 8 or higher
- IDE (Eclipse, IntelliJ IDEA, or VS Code)
- Understanding of Java fundamentals

## 🚀 How to Run

### C++ Projects
```bash
# Compile any C++ file
g++ -o program filename.cpp

# Run the executable
./program  # Linux/Mac
program.exe  # Windows
```

### Java Projects
```bash
# Compile Java files
javac *.java

# Run main class
java TestMain
```

## 📁 Project Highlights

1. **Vector Mathematics** - Complete 3D vector implementation with mathematical operations
2. **BookShop System** - Progressive development from basic to advanced features
3. **Banking System** - Professional Java application with multiple classes
4. **Pointer Mastery** - Comprehensive pointer exercises for memory management
5. **Template Programming** - Generic programming concepts and implementation

## 🎯 Learning Outcomes

After completing this coursework, students will have mastered:

- **Core OOP Principles** - Deep understanding of object-oriented design
- **Memory Management** - Proper handling of dynamic memory in C++
- **Operator Overloading** - Creating intuitive interfaces for custom classes
- **Generic Programming** - Template usage and design patterns
- **Java Enterprise Concepts** - Professional Java application development
- **Problem Solving** - Algorithmic thinking and code optimization

## 📝 Notes

- All assignments include comprehensive test cases
- Code follows modern C++/Java best practices
- Memory management is properly handled in all C++ implementations
- Java projects demonstrate proper OOP design patterns

## 🤝 Contributing

This is an academic repository. For educational purposes only.

## 📄 License

This project is part of academic coursework and is intended for educational use only.

---

**Course**: CSE108 - Object-Oriented Programming Language Sessional  
**Institution**: BUET 
**Semester**: Level-1 Term-2  
**Student ID**: 2005114
