# String List Generator

A C++ program that generates all possible strings of a given length using characters from a specified set.

## Features

- Generates all possible combinations of strings with a specified length
- Uses a configurable character set
- Outputs results to `output.txt`
- Includes safety checks for large outputs
- Efficient recursive algorithm

## Usage

### Compilation

```bash
make
```

### Running

```bash
make run
```

Or directly:

```bash
./string_generator
```

### Cleaning

```bash
make clean
```

## Configuration

You can modify the program by changing these variables in `main.cpp`:

```cpp
std::string characters = "abc";  // Characters to use
int N = 3;                       // Length of strings to generate
```

## Examples

### Example 1: Using "abc" with length 2
- Characters: "abc"
- Length: 2
- Output: aa, ab, ac, ba, bb, bc, ca, cb, cc

### Example 2: Using "01" with length 3
- Characters: "01"
- Length: 3
- Output: 000, 001, 010, 011, 100, 101, 110, 111

## Output

The program generates a file called `output.txt` containing all possible strings, one per line.

## Performance Notes

- The number of strings generated is `characters.length()^N`
- For large values, the program will warn you before proceeding
- The program uses efficient memory management and streams output directly to file

## Requirements

- C++11 compatible compiler (g++ recommended)
- Make (for easy compilation)
