
# Movie Management System — Console-Based Movie and Person Management in C

This C program is a console application designed to manage a collection of movies and associated persons. It allows users to add, delete, search, and display movies and persons dynamically. The data is stored in memory using **dynamic arrays** and handled with modular source and header files for clean architecture and maintainability.

---

## Features

* Add new movies and persons with unique identifiers.
* Delete movies and persons from the system.
* Search for movies or persons by name or other criteria.
* Display lists of all movies and persons.
* Load data from and save data to external text files.
* Interactive console menu to navigate through the system features.
* Modular codebase with separate `.c` and `.h` files.

---

## Project Structure

```
Movie-Management-System/
├── include/
│   └── movie_manager.h          # Header file with data structures and function prototypes
├── src/
│   ├── main.c                   # Entry point with menu and user interaction logic
│   └── movie_manager.c          # Core implementation for managing movies and persons
├── data/
│   ├── Films.txt                # Data file for movies
│   └── Personnes.txt            # Data file for persons  
└── README.md                    # This documentation file
```

---

## How to Compile

From the project root directory, compile the code using the following command:

```bash
gcc src/main.c src/movie_manager.c -Iinclude -o movie_manager
```

Alternatively, if you have a Makefile, simply run:

```bash
make
```

---

## How to Run

After compilation, launch the program from the terminal:

```bash
./movie_manager
```

---

## User Menu

Upon launching, the program displays an interactive menu similar to:

```
------------------------------MENU:--------------------------------------------

		   1. Display the list of movies.
		   2. Display the list of actors and directors.
		   3. Insert a new movie.
		   4. Insert a new actor or director.
		   5. Search for a movie by its identifier.
		   6. Delete the movies file.
		   7. Delete the actors and directors file.
		   8. Exit.

------------------------------------------------------------------------------
Enter your choice:
```

Follow the prompts to perform various operations on movies and persons.

---

## Sample Data Files Format

* **Films.txt**
  Contains movie records, each line representing one movie with fields separated by a delimiter (e.g., comma or tab).

* **Personnes.txt**
  Contains person records, structured similarly to `Films.txt`.

*(Exact format depends on your implementation, please refer to source code comments or sample files.)*

---

## Highlights & Learning Outcomes

* Mastery of **dynamic memory management** in C.
* Use of **modular programming** with separate header and source files.
* Implementation of **file I/O** for persistent data storage.
* Development of a **console-based interactive menu** system.
* Structuring complex data with arrays of structures.
* Practice with **basic CRUD operations** (Create, Read, Update, Delete) in C.

---

## Limitations & Future Improvements

* Add input validation and error handling robustness.
* Implement sorting and filtering options for movies and persons.
* Enhance data persistence with binary file support or databases.
* Add multi-threading for responsiveness (advanced).
* Develop a graphical user interface (GUI) for better usability.
* Include detailed logging for operations.

---

## License

This project is licensed under the MIT License — you are free to use, copy, modify, merge, publish, and distribute the software, provided that the original author is credited and the license notice is included in all copies or substantial portions of the software.

See the [LICENSE](LICENSE) file for full terms.

---

