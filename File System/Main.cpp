#include <iostream>
#include <string>
#include <fstream> // Подключение библиотеки, содержащей в себе объекты и классы для работы с файловой системой устройства 


bool statistic(std::string str);

int main() {
	setlocale(0, "");
	int n;
	std::string path = "file.txt";


	// Класс Ofstream для записи в файл
	
	std::ofstream out; // Объявление объекта записи в файл
	out.open(path, std::ios::app); // открытие файла. Создает файл, если его не существует

	if (out.is_open()) { // Проверка открытия файла 
		std::cout << "Файли открыт для записи!\n";
		std::string str;
		std::cout << "Введите строку -> ";
		std::getline(std::cin, str);
		out << str << '\n'; // Добавление записи в файл

	}
	else {
		std::cout << "Ошибка открытия файла!\n";
		//Возможные причины ошибки при открытии файла для записи:
		// 1. Некорректный путь к файлу
		// 2. Нет доступа к файлу
		// 3. Файл открыт другим обЪектом или программой. 
	}
	out.close(); //Закрытие файла 
	
	

	// Класс ifstream для чтения из файла
	
	std::ifstream in;
	in.open(path);
	if (in.is_open()) {
		std::cout << "Файл открытю Содержимое файла:\n";
		std::string file;

		//Посимвольное считывание 
		//char sym;
		//while (in.get(sym)) {
			//file += sym;
		//}
		//std::cout << file << std::endl;

		// Пословное считывание 
		//while(!in.eof()) {
		//	std::string word;
			//in >> word;
			//file += word + '\n';
		//}
		//std::cout << file << std::endl;
		
		//Построчное считывание 
		std::string str;
		while (std::getline(in, str)) {
			file += str + '\n';
		}
		std::cout << file << std::endl;
	}
	else {
		std::cout << "Ошибка открытия файла!";
		//Возможные причины ошибки при открытии файла для чтения
		// 1. Неправельный путь к файлу 
		// 2. Файла не существует 
		// 3. Нет доступа к файлу  
	}
	in.close();
	


	// Удаление файла 
	
	//remove(path.c_str()); // неудобно
	if (remove(path.c_str()) == 0)
		std::cout << "Файл удален.\n";
	else {
		std::cout << "Ошибка удаления файла!\n";
		// Возможные ошибки при удаления файла
		// 1. Нет доступа к файлу 
		// 2. Файла не существует 
		// 3. Файл открыт другим объектом или приложением 
		// 4. Неправильный путь к файлу
	}
	


	// Задача 1. Статистика в файле 

	std::cout << "Задача 1.\nВведите строку -> ";
	std::string str1;
	std::getline(std::cin, str1);

	if (statistic(str1))
		std::cout << "Запись добавлена\n";
	else
		std::cout << "Ошибка добавления записи!\n";
	







	return 0;
}


bool statistic(std::string str) {
	static std::ofstream out;
	out.open("stats.txt", std::ios::app);

	if (out.is_open()) {
		out << str << ' ' << str.length() << '\n';
		out.close();
		return true;
	}

	return false;
}