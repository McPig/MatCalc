#ifndef MATCAL_APPLICATION_H
#define MATCAL_APPLICATION_H
/* ------------------------------------------------------------------------------------------------------------------ */

#include "../lib/matrices/Matrix.h"
#include "../lib/operations/Addition.h"
#include "../lib/operations/Subtraction.h"
#include "../lib/operations/Multiplication.h"
#include "../lib/operations/Merge.h"
#include "../lib/operations/Split.h"
#include "../lib/operations/Transposition.h"
#include "../lib/operations/GaussianElimination.h"
#include "../lib/operations/Rank.h"
#include "../lib/operations/Determinant.h"
#include "Table.h"

#include <string>
#include <vector>
#include <map>
#include <utility>
#include <iostream>
#include <sstream>
#include <fstream>
#include <limits>


constexpr char GREETING[] {"Welcome to MatCal! Type \"help\" for more information."};
constexpr char BYE[] {"Farewell!"};
constexpr char NOT_FOUND[] {" not found. List commands with \"help\"."};
constexpr char INVALID_SYN[] {" invalid syntax."};
constexpr char NOT_IN_STORAGE[] {" is not declared."};


/**
 * @brief Main application class. Communicates with user.
 * @tparam T The type of items.
 */
template<typename T>
class Application {
private:
	std::map<std::string, Matrix<T>> m_vars;

public:
	// -----------
	// Constructor
	// -----------
	/**
	 * @brief Default constructor.
	 */
	Application();

	// ------------------
	// Application manage
	// ------------------
	/**
	 * @brief Starts the application.
	 */
	void start();

	/**
	 * @brief Application main loop.
	 */
	void serve();

	/**
	 * @brief clears std::cin.
	 */
	void clearCin() const;

	/**
	 * @brief Reads args as one line.
	 * @return vector of arguments.
	 */
	std::vector<std::string> readArgs() const;

	/**
	 * Prints matrix as table.
	 * @param m The matrix to print.
	 */
	void printMatrix(const Matrix<T> & m) const;

	// ----------------
	// Variables manage
	// ----------------
	/**
	 * @brief Checks if variable is in storage.
	 * @param name The variable name.
	 * @return True if found, false otherwise.
	 */
	bool inStorage(const std::string & name) const;

	/**
	 * @brief Adds var to storage.
	 * @param name The name to add.
	 * @param m The value to add.
	 */
	void addVar(const std::string & name, Matrix<T> & m);

	// ----------------
	// Handling methods
	// ----------------
	/**
	 * @brief Handles help command.
	 */
	void helpHandler() const;

	/**
	 * @brief Handles scan command.
	 */
	void scanHandler();

	/**
	 * @brief Handles print command.
	 */
	void printHandler() const;

	/**
	 * @brief Handles var command.
	 */
	void varHandler();

	/**
	 * @brief Handles assign command.
	 */
	void assignHandler();

	/**
	 * @brief Handles add, subt, mult, merge commands.
	 */
	void operHandler(char op = 'a');

	/**
	 * @brief Handles split command.
	 */
	void splitHandler();

	/**
	 * @brief Handles trans command.
	 */
	void transHandler();

	/**
	 * @brief Handles gem command.
	 */
	void gemHandler() const;

	/**
	 * @brief Handles rank or det commands.
	 */
	void rankDetHandler(bool rank = true) const;
};


#include "Application.cpp"

/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_APPLICATION_H
