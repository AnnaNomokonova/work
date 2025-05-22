#pragma once

#include <iostream>

namespace naa {
	class LongNumber {
        private:
			int* numbers;  // Динамический массив цифр числа
			int length;    // Количество цифр в числе
			int sign;      // Знак числа (-1, 0, +1)
		
		public:
            LongNumber();                           // Конструктор по умолчанию
            LongNumber(const char* const str);      // Конструктор из строки (например, "12345")
            LongNumber(const LongNumber& x);        // Конструктор копирования
            LongNumber(LongNumber&& x);             // Конструктор перемещения

            ~LongNumber();                          // Деструктор
			
			LongNumber& operator = (const char* const str);  // Присваивание из строки
            LongNumber& operator = (const LongNumber& x);    // Присваивание копированием
            LongNumber& operator = (LongNumber&& x);         // Присваивание перемещением
			
			bool operator == (const LongNumber& x) const;
			bool operator != (const LongNumber& x) const;
			bool operator > (const LongNumber& x) const;
			bool operator < (const LongNumber& x) const;
			
			LongNumber operator + (const LongNumber& x) const;
			LongNumber operator - (const LongNumber& x) const;
			LongNumber operator * (const LongNumber& x) const;
			LongNumber operator / (const LongNumber& x) const;
			LongNumber operator % (const LongNumber& x) const;
			
			int get_digits_number() const noexcept;          // Возвращает количество цифр
            int get_rank_number(const int rank) const;       // Возвращает цифру в заданном разряде
            bool is_negative() const noexcept;               // Проверяет, отрицательное ли число
			
			friend std::ostream& operator << (std::ostream &os, const LongNumber& x);       // Позволяет выводить число в поток
			
		private:
			int get_length(const char* const str) const noexcept;   // Вспомогательная функция для вычисления длины строкового представления числа
	};
}
