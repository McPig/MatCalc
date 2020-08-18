#ifndef MATCAL_APPLICATION_CPP
#define MATCAL_APPLICATION_CPP
/* ------------------------------------------------------------------------------------------------------------------ */

#include "Application.h"


template<typename T>
Application<T>::Application():
	m_vars {}
{}


template<typename T>
void Application<T>::start() {
	std::cout << GREETING << std::endl;
	serve();
}


template<typename T>
void Application<T>::serve() {
	while (true) {
		std::cout << ">>> ";
		std::string cmd {};
		std::cin >> cmd;

		if (cmd == "exit") {
			std::cout << BYE << std::endl;
			return;
		}
		else if (cmd == "help")
			helpHandler();
		else if (cmd == "scan")
			scanHandler();
		else if (cmd == "print")
			printHandler();
		else if (cmd == "var")
			varHandler();
		else if (cmd == "assign")
			assignHandler();
		else if (cmd == "add")
			operHandler();
		else if (cmd == "subt")
			operHandler('s');
		else if (cmd == "mult")
			operHandler('m');
		else if (cmd == "merge")
			operHandler('e');
		else if (cmd == "split")
			splitHandler();
		else if (cmd == "trans")
			transHandler();
		else if (cmd == "gem")
			gemHandler();
		else if (cmd == "rank")
			rankDetHandler();
		else if (cmd == "det")
			rankDetHandler(false);
		else {
			clearCin();
			std::cout << '"' << cmd << '"' << NOT_FOUND << std::endl;
		}
	}
}


template<typename T>
void Application<T>::clearCin() const {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


template<typename T>
std::vector<std::string> Application<T>::readArgs() const {
	std::string tmp {};
	std::getline(std::cin, tmp);
	std::istringstream iss {tmp};

	std::vector<std::string> args;

	while (iss.good()) {
		iss >> tmp;
		if (!tmp.empty())
			args.push_back(tmp);
	}

	return args;
}


template<typename T>
void Application<T>::printMatrix(const Matrix<T> & m) const {
	size_t rows = m.rows_num();
	size_t cols = m.cols_num();

	Table table {rows, cols};
	for (size_t r {0}; r < rows; ++r)
		for (size_t c {0}; c < cols; ++c) {
			std::string t {' ' + std::to_string(m.at(r, c)) + ' '};
			table.SetCell(r, c, Text(t, Text::ALIGN_RIGHT));
		}
	std::cout << table;
}


template<typename T>
bool Application<T>::inStorage(const std::string & name) const {
	auto iter = m_vars.find(name);

	return iter != m_vars.end();
}


template<typename T>
void Application<T>::addVar(const std::string & name, Matrix<T> & m) {
	m_vars[name] = m;
}


template<typename T>
void Application<T>::helpHandler() const {
	std::ifstream ifs("src/app/help.txt");
	std::cout << ifs.rdbuf() << std::endl;
	ifs.close();
	clearCin();
}


template<typename T>
void Application<T>::scanHandler() {
	std::string var {};
	int rows {};
	int cols {};
	std::cin >> var >> rows >> cols;

	if (std::cin.fail() || rows <= 0 || cols <= 0) {
		std::cout << "scan:" << INVALID_SYN << std::endl;
		clearCin();
		return;
	}

	std::cout << "Enter matrix elements:\n";
	std::vector<T> items {};
	for (size_t i {0}; i < (size_t) rows * cols; ++i) {
		T item {};
		std::cin >> item;
		if (std::cin.fail()) {
			std::cout << "scan:" << INVALID_SYN << std::endl;
			clearCin();
			return;
		}
		items.push_back(item);
	}

	clearCin();

	try {
		Matrix<T> m {(size_t ) rows, (size_t) cols, items};
		addVar(var, m);
	}
	catch (std::length_error & ex) {
		std::cout << ex.what() << std::endl;
		return;
	}
}


template<typename T>
void Application<T>::printHandler() const {
	std::string var {};
	std::cin >> var;

	if (std::cin.fail()) {
		std::cout << "print:" << INVALID_SYN << std::endl;
		return;
	}

	clearCin();

	if (!inStorage(var)) {
		std::cout << '"' << var << '"' << NOT_IN_STORAGE << std::endl;
		return;
	}

	printMatrix(m_vars.at(var));
}


template<typename T>
void Application<T>::varHandler() {
	std::string var_a {};
	std::string var_b {};
	std::cin >> var_a >> var_b;

	if (std::cin.fail()) {
		std::cout << "var:" << INVALID_SYN << std::endl;
		clearCin();
		return;
	}

	clearCin();

	if (!inStorage(var_b)) {
		std::cout << '"' << var_b << '"' << NOT_IN_STORAGE << std::endl;
		return;
	}

	addVar(var_a, m_vars.at(var_b));
}


template<typename T>
void Application<T>::assignHandler() {
	std::string var {};
	int rows;
	int cols;
	T value;

	std::cin >> var >> rows >> cols >> value;
	if (std::cin.fail() || rows <= 0 || cols <= 0) {
		std::cout << "init:" << INVALID_SYN << std::endl;
		clearCin();
		return;
	}

	clearCin();

	try {
		Matrix<T> m {(size_t ) rows, (size_t) cols, value};
		addVar(var, m);
	}
	catch (std::exception & ex) {
		std::cout << ex.what() << std::endl;
		return;
	}
}


template<typename T>
void Application<T>::operHandler(char op) {
	auto args = readArgs();

	if (args.size() < 2) {
		if (op == 'a')
			std::cout << "add:";
		else if (op == 's')
			std::cout << "subt:";
		else if (op == 'm')
			std::cout << "mult:";
		else if (op == 'e')
			std::cout << "merge:";
		std::cout << INVALID_SYN << std::endl;
		return;
	}

	bool save {false};
	size_t i = 0;
	for (const auto & arg : args) {
		if ((args.size() == 2 && !inStorage(arg)) || (!inStorage(arg) && i + 1 != args.size())) {
			std::cout << '"' << arg << '"' << NOT_IN_STORAGE << std::endl;
			return;
		}
		++i;
	}

	if (args.size() != 2 && !inStorage(args.at(i - 1)))
		save = true;

	Matrix<T> res {m_vars.at(args.at(0))};
	size_t m {1};

	while (m < (save ? args.size() - 1 : args.size())) {
		try {
			if (op == 'a') {
				Addition<T> a(&res, &m_vars.at(args.at(m)));
				res = a.result();
			}
			else if (op == 's') {
				Subtraction<T> s(&res, &m_vars.at(args.at(m)));
				res = s.result();
			}
			else if (op == 'm') {
				Multiplication<T> mult(&res, &m_vars.at(args.at(m)));
				res = mult.result();
			}
			else if (op == 'e') {
				Merge<T> merge(&res, &m_vars.at(args.at(m)));
				res = merge.result();
			}
		}
		catch (std::exception & ex) {
			std::cout << ex.what() << std::endl;
			return;
		}
		++m;
	}

	if (save)
		addVar(args.at(args.size() - 1), res);
	else
		printMatrix(res);
}


template<typename T>
void Application<T>::splitHandler() {
	std::string line {};
	std::getline(std::cin, line);
	std::istringstream iss {line};

	std::string var {};
	int row = 0, col = 0;
	int n_rows = 1, n_cols = 1;

	iss >> var >> row >> col >> n_rows >> n_cols;
	if (iss.fail() || row <= 0 || col <= 0 || n_rows < 1 || n_cols < 1) {
		std::cout << "split:" << INVALID_SYN << std::endl;
		return;
	}

	if (!inStorage(var)) {
		std::cout << '"' << var << '"' << NOT_IN_STORAGE << std::endl;
		return;
	}

	std::string save;
	iss >> save;
	if (iss.fail())
		save.clear();

	Matrix<T> res;
	try {
		Split<T> split {&m_vars.at(var), (size_t) row, (size_t) col, (size_t) n_rows, (size_t) n_cols};
		res = split.result();
	}
	catch (std::exception & ex) {
		std::cout << ex.what() << std::endl;
		return;
	}

	if (save.empty())
		printMatrix(res);
	else
		addVar(save, res);
}


template<typename T>
void Application<T>::transHandler() {
	std::string line {};
	std::getline(std::cin, line);
	std::istringstream iss {line};

	std::string var {};
	iss >> var;
	if (iss.fail()) {
		std::cout << "trans:" << INVALID_SYN << std::endl;
		return;
	}

	std::string save {};
	iss >> save;
	if (iss.fail())
		save.clear();

	if (!inStorage(var)) {
		std::cout << '"' << var << '"' << NOT_IN_STORAGE << std::endl;
		return;
	}

	Matrix<T> res;
	try {
		Transposition<T> tr(&m_vars.at(var));
		res = tr.result();
	}
	catch (std::exception & ex) {
		std::cout << ex.what() << std::endl;
		return;
	}

	if (save.empty())
		printMatrix(res);
	else
		addVar(save, res);
}


template<typename T>
void Application<T>::gemHandler() const {
	auto args {readArgs()};
	if (args.size() != 2) {
		std::cout << "gem:" << INVALID_SYN << std::endl;
		return;
	}

	for (const auto & arg : args)
		if (!inStorage(arg)) {
			std::cout << '"' << arg << '"' << NOT_IN_STORAGE << std::endl;
			return;
		}

	Matrix<T> res;
	try {
		GaussianElimination<T> gem(&m_vars.at(args.at(0)), &m_vars.at(args.at(1)));
		res = gem.result();
	}
	catch (std::exception & ex) {
		std::cout << ex.what() << std::endl;
		return;
	}

	printMatrix(res);
}


template<typename T>
void Application<T>::rankDetHandler(bool rank) const {
	std::string var {};
	std::cin >> var;
	if (std::cin.fail()) {
		std::cout << (rank ? "rank:" : "det:") << INVALID_SYN << std::endl;
		clearCin();
		return;
	}

	clearCin();

	if (!inStorage(var)) {
		std::cout << '"' << var << '"' << NOT_IN_STORAGE << std::endl;
		return;
	}

	Matrix<T> res;
	try {
		if (rank) {
			Rank<T> r(&m_vars.at(var));
			res = r.result();
		}
		else {
			Determinant<T> r(&m_vars.at(var));
			res = r.result();
		}
	}
	catch (std::exception & ex) {
		std::cout << ex.what() << std::endl;
		return;
	}

	if (rank)
		std::cout << "Rank = ";
	else
		std::cout << "Determinant = ";
	std::cout << res.at(0, 0) << std::endl;
}


/* ------------------------------------------------------------------------------------------------------------------ */
#endif  // MATCAL_APPLICATION_CPP
