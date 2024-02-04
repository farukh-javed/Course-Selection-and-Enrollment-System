# Course Enrollment System

This is a simple command-line application for managing student enrollments in courses.

## Features

- Enroll students in courses
- Drop students from courses
- Display enrolled students
- Update the section of a student for an enrolled course
- Display the total number of students enrolled in a particular course
- Display courses not enrolled by any student
- Display the student with the minimum number of registered courses

## How to Use

1. Compile the code using a C++ compiler (e.g., g++).
   ```bash
   g++ main.cpp -o enrollment_system
   ```

2. Run the compiled executable.
   ```bash
   ./enrollment_system
   ```

3. Follow the on-screen instructions to perform various actions.

## Files

- `main.cpp`: Main source code file.
- `courses.txt`: File containing information about available courses.
- `README.md`: Documentation about the project.

## Course Information File (courses.txt)

The `courses.txt` file contains information about courses. Each line in the file represents a course and includes the course code, credit hours, and title.

Example:
```
CSE101 3 Introduction to Computer Science
MATH201 4 Calculus I
PHYS202 4 Physics for Scientists and Engineers
CHEM101 3 General Chemistry
ENG102 3 English Composition II
```

Feel free to modify the content of `courses.txt` to match your specific courses.

## Contributing

If you have suggestions or find issues, please open an issue or create a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
```