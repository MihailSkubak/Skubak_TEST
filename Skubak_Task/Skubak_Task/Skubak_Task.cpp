// Skubak_Task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>//библиотека для работы с файлами
using namespace std;
class TaskA {
public:
	// метод проверяется какое сочетание символов повторяется и сколько раз
	int count_new(string input_text, char a, char b) {
		int result = 0;

		for (int i = 0; i < input_text.length(); i++) {
			if (i != input_text.length() - 1) {
				if (input_text[i] == a && input_text[i + 1] == b) {
					result = result + 1;
				}
			}
		}
		return result;
	}
};

class TaskB {
public:
	//Метод делает замену символов с запятой на точку и возвращает значение в переменную input_text2 
	string Repl(string input_text2) {
		string s = ",";
		string d = ".";
		for (int i = 0; i < input_text2.length(); i++) {
			if (input_text2[i] == ',') {//проверка на запятую
				input_text2.replace(input_text2.find(s), s.length(), d);// замена символов
			}
		}
		return input_text2;
	}
};
class TaskC {
public:
	string it3;
	//Метод ищет в переменной input_text3 цифры и записывает значение в переменную it3
	string numbers(string input_text3) {
		for (int i = 0; i < input_text3.length(); i++) {
			if (input_text3[i] > '0' && input_text3[i] <= '9') {
				it3 = it3 + input_text3[i];
			}
		}
		return it3;
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	string input_text;
	ifstream file("example.txt");//Открывает файл для чтения
	getline(file, input_text, '\0');//заполняет переменную input_text значениями с файла
	file.close();//закрывает файл для чтения
	string text = "";
	int result = 0;
	TaskA c_s;//обьявляет обьект класса
	TaskB r;
	TaskC n;

	for (int i = 0; i < input_text.length(); i++) {
		if (i != input_text.length() - 1) {
			//Пропускает пробелы и переносы строк
			if (input_text[i] != ' ' && input_text[i + 1] != ' ' && input_text[i] != '\n'  && input_text[i + 1] != '\n') {
				//задает значение в класс TaskA в метод count_new
				int count_sym = c_s.count_new(input_text, input_text[i], input_text[i + 1]);

				if (count_sym == result) {//в случае если некоторые сочетание символов повторяется одинаковое кол-во раз, то записываются оба варианта
					int a = 0;
					for (int j = 0; j < text.length(); j++) {
						if (text[j] == input_text[i] && text[j + 1] == input_text[i + 1]) {
							a = 1;
						}
					}
					if (a == 0) {
						text = text + " " + string(1, input_text[i]) + string(1, input_text[i + 1]);
					}
				}
				if (count_sym > result) {//записывает какое сочетание символов появляется чаще всего
					result = count_sym;
					text = string(1, input_text[i]) + string(1, input_text[i + 1]);
				}
			}
		}
	}
	ofstream file2("example_out.txt");//Открывает файл для записи
	file2 << "Аргумент А:" << endl << "Символ: " << text << " повторяется " << result << " раз(а)" << endl;//Записывает в файл символы которые больше всего повторяются
	file2 << "Аргумент В:" << endl << r.Repl(input_text) << endl;//Записывает в файл все символы после замены с запятой на точку
	file2 << "Аргумент C:" << endl << n.numbers(input_text) << endl;//Записывает в файл все цифры
	file2.close();//закрывает файл для записи
	cout << "Текст был записан в файл example_out.txt" << endl;
	system("pause");
	return 0;
}
