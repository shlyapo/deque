#pragma once
//Vector.h
#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

using namespace std;

class Vector
{
private:
	int* mas;
	int* mas2;
public:
	int size;
	int back, index, element, index2, element2, find_index;
	int j;
	Vector(int size)
	{
		this->size = size;
		this->mas = new int[size];
		for (int i = 0; i < size; i++)
			mas[i] = i;
	}
	void SetVector()
	{
		cout << "Введите элементы" << endl;
		for (int i = 0; i < size; i++)
			cin >> mas[i];
	}
	void change_length() /*j- параметр изменения длины*/
	{
		if (j > 0)
		{
			this->mas2 = new int[size + j];
			for (int i = 0; i < size + j; i++)
				mas2[i] = mas[i];
		}
		else
		{
			this->mas2 = new int[size - j];
			for (int i = 0; i < size - j; i++)
				mas2[i] = mas[i];
		}
	}
	void push_back(int back)
	{
		cout << "Введите элементы, которые нужно вставить" << endl;
		for (int j = 0; j > 0; j++)
			cin >> back;
		this->back = back;
		change_length();
		mas2[size] = back;
		for (int i = 0; i < size + j; i++)
			cout << mas2[i] << endl;
	}
	void insert_index(int index, int element)
	{
		this->index = index;
		this->element = element;
		if (index > size)
			cout << "Incorrect value" << endl;
		else
		{
			int j = 1;
			change_length();
			for (int i = size; i > 0; i--)
			{
				if (i > index)
					mas2[i] = mas2[i - 1];
				else if (i == index)
					mas2[index] = element;
				else mas2[i] = mas2[i];
			}
			for (int i = 0; i < size + j; i++)
				cout << mas2[i] << endl;
		}
	}
	int delete_index(int index2)
	{
		cout << "Введите индекс" << endl;
		cin >> index2;
		this->index2 = index2;
		if (index2 > size)
		{
			cout << "Incorrect value" << endl;
		}
		else
		{
			int j = -1;
			change_length();
			for (int i = 0; i < size - 1; i++)
			{
				if (i < index2)
					mas2[i] = mas2[i];
				else
					mas2[i] = mas2[i + 1];
			}
			for (int i = 0; i < size - j; i++)
				cout << mas[i] << endl;
		}
	}
	void clear()
	{
		delete[] mas;
		cout << " Массив удалён";
	}
	void delete_back()
	{
		int j = -1;
		change_length();
		for (int i = 0; i < size - j; i++)
			cout << mas2[i] << endl;
	}
	void find_element()
	{
		cout << "Введите элемент" << endl;
		cin >> element2;
		for (int i = 0; i < size; i++)
		{
			if (mas[i] == element2)
				find_index = i;
			else find_index = -1;
		}
		cout << find_index << endl;
	}
	Vector(const Vector& other)
	{
		this->size = other.size;
		this->mas = new int[size];
		for (int i = 0; i < this->size; i++)
			this->mas[i] = other.mas[i];
	}
	Vector& operator=(Vector& other)
	{
		delete[] this->mas;
		this->size = other.size;
		this->mas = new int[this->size];

		for (int i = 0; i < this->size; i++)
			this->mas[i] = other.mas[i];
		return *this;
	}
	~Vector()
	{
		delete[] mas;
		delete[] mas2;
	}
};
#endif
