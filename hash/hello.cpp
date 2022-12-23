#include <string>
#include <iostream>
#include <string>
#include <fstream>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/md5.h> // MD5
#include <cryptopp/pwdbased.h>
#include <cryptopp/filters.h>

using namespace std;
using namespace CryptoPP; 

int main()
{
	ifstream fs;        //входной поток для чтения файлов
	string str;
	string strs="";
	string file = "file.txt";  // в переменную файла указываем имя файла которое будем открывать для чтения
	fs.open(file);  // открытие файла
	while (!fs.eof()) {  //цикл,пока не достигнет конца файла
		getline(fs, str); //считываем строку
		strs = strs+str;  //в переменную strs добавляем эту строку
	}
	cout << strs;  // выводим на экран
	string hesh;   // оперделяем строку для хранения хэша
	CryptoPP::Weak1::MD5 hashmd4;  //определяем переменную для типа хэша из библиотеки CryptoPP
	CryptoPP::StringSource(strs, true, new CryptoPP::HashFilter(hashmd4,new CryptoPP::HexEncoder(new CryptoPP::StringSink(hesh)))); //вычисление хэша от всех считанных строк с помощью библиотеки
	cout << endl<<hesh; //выводим на экран
}
