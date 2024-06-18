# OOP Lab Work

Welcome to the Object-Oriented Programming (OOP) Lab Work repository! This repository contains various lab exercises and examples demonstrating the principles and practices of OOP in C++.

## Repository Structure

The repository is organized into different folders and files, each focusing on specific aspects of OOP. Below is a sample overview of the structure:

``` bash
OOP_LAB/
│   README.md
│
├───.vscode
│    └── settings.json
│
├───Animals
│   ├── details.txt
│   ├── person.cpp
│   └── person.exe
│
└───intro
    ├── hello.cpp
    ├── hello.exe
    ├── random.cpp
    ├── random.exe
    └── random.h
```

## Examples

### Animals Example

This example contains a `Person` class that models a person with properties such as `age`, `height`, and `name`. It demonstrates how to use a constructor to initialize these properties and how to display the person's details.

- **Directory:** `Animals`
- **Files:**
  - `person.cpp`: Contains the implementation of the `Person` class.
  - `person.exe`: The compiled executable of the `person.cpp`.
  - `details.txt`: Additional details or documentation related to the example.
- **Key Concepts:** Class definition, constructors, private properties, public methods, and object instantiation.

### Introductory Examples

This directory contains basic introductory examples to get started with C++ and random number generation.

- **Directory:** `intro`
- **Files:**
  - `hello.cpp`: A simple "Hello, World!" program.
  - `hello.exe`: The compiled executable of the `hello.cpp`.
  - `random.cpp`: A program that demonstrates generating random numbers.
  - `random.exe`: The compiled executable of the `random.cpp`.
  - `random.h`: Header file for the random number generation program.
- **Key Concepts:** Basic C++ syntax, input/output operations, random number generation.

## How to Run the Code

To compile and run the examples, follow the steps below:

1. **Clone the repository:**

   ```bash
   git clone https://github.com/KigoJomo/OOP_Lab.git
   cd OOP_Lab
   ```

2. **Navigate to the desired example directory:**

   ```bash
   cd DogExample
   ```

3. **Compile the C++ code using a C++ compiler:**

   ```bash
   g++ DogExample.cpp -o DogExample
   ```

4. **Run the executable:**

   ```bash
   ./DogExample
   ```

Repeat the steps for other examples by navigating to their respective directories and compiling the code.

## Author

This repository is maintained by [Jomo Kigo](https://github.com/KigoJomo).

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Contributing

Feel free to fork this repository, make improvements, and submit pull requests. Contributions are welcome
