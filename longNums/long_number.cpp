#include "long_number.hpp"

using naa::LongNumber;
		
LongNumber::LongNumber() {
	length = 0;
}

LongNumber::LongNumber(const char* const str) {
	this->length = this->get_length(str);


	if (str[0] == '-')
	{
		sign = 1;
		length--;
	}

	numbers = new int[length];
	for (int i = 0; i < length; i++) 
	{
		numbers[i] = str[i+sign] - '0';
	}
}

LongNumber::LongNumber(const LongNumber& x) {
	// TODO
}

LongNumber::LongNumber(LongNumber&& x) {
	// TODO
}

LongNumber::~LongNumber() {
	// TODO

	delete[] numbers;
}

LongNumber& LongNumber::operator = (const char* const str) {
	// TODO
}

LongNumber& LongNumber::operator = (const LongNumber& x) {
	// TODO
}

LongNumber& LongNumber::operator = (LongNumber&& x) {
	// TODO
}
bool LongNumber::operator == (const LongNumber& x) const {
    
    if (this->sign != x.sign){
        return 0;
    }
    if (this->length != x.length){
        return 0;
    }
    if ((this->length == x.length) && this->sign == x.sign){
        bool flag = true;
        for (int i = 0; i < length; i++){
            if (this->numbers[i] != x.numbers[i]){
                flag = false;
                break;
            }
            if (flag == true){
                return 1;
            }else{
                return 0;
            }
        }
    }
}

bool LongNumber::operator != (const LongNumber& x) const {
	return !(*this == x);
}

bool LongNumber::operator > (const LongNumber& x) const {
    if (this->sign < x.sign){
        return 1;
    }else if(this->sign > x.sign){
        return 0;
    }


    if (this->sign == -1){
        if (this->length > x.length){
            return 0;
        }else if(this->length < x.length){
            return 1;
        }else{
            bool flag = true;
            for (int i = 0; i < length; ++i){
                if (this->numbers[i] > x.numbers[i]){
                    flag = false;
                    break;
                }
            }
            if (flag == true){
                return 1;
            }else{
                return 0;
            }
        }
    }


    if (this->length < x.length){
        return 0;
    }else if(this->length > x.length){
        return 1;
    }

    bool flag = true;
    for (int i = 0; i < length; ++i){
        if (this->numbers[i] < x.numbers[i]){
            flag = false;
            break;
        }
    }
    if (flag){
        return 1;
    }else{
        return 0;
    }
    
}

bool LongNumber::operator < (const LongNumber& x) const {
    if (x > *this) return 1;
    if (*this > x) return 0;
}

LongNumber LongNumber::operator + (const LongNumber& x) const {
	if ((this->sign) && (x.sign))
	{
		LongNumber ng{"-1"};
		return (ng * (ng * *this + ng * x));
	} else if (this->sign)
	{
		return( x - *this);
	} else if (x.sign)
	{
		return (*this - x);
	}
	

	int max_length = (x.length >= this->length)? x.length : this->length;
	                        
    
	char* buffer = new char[max_length+1];
	int cf = 0;

	for (int i = 0; i <= max_length; i++){
		if (i < this->length && i < x.length){
			buffer[i] = this->numbers[this->length-1-i]+ x.numbers[x.length-1-i] +cf;

		} else if (i < this->length) {
			buffer[i] = this->numbers[this->length-1-i] + cf;
		} else if (i < x.length) {
			buffer[i] = x.numbers[x.length-1-i] + cf;
		} else if (cf) {

			buffer[i] = cf;
			max_length = i+1;
		}
		


		cf = buffer[i] / 10;
		buffer[i] = (buffer[i] % 10) + '0';


	}

	char* res = new char[max_length + 1];
	for (int i = 0; i < max_length; i++)
	{
		res[i] = buffer[max_length - i -1];

	}
	res[max_length + 1] = '\0';

	LongNumber ans {res};
	delete[] buffer;
	delete[] res;
	return ans;
}

LongNumber LongNumber::operator - (const LongNumber& x) const {
}

LongNumber LongNumber::operator * (const LongNumber& x) const {
	int max_buffer_length = this->length + x.length;
	int* buffer = new int[max_buffer_length]();
	int result_length = 0;
  
	int sign = this->sign ^ x.sign;
  
	for (int i = 0; i < this->length; i++) {
	  for (int j = 0; j < x.length; j++) {
		buffer[i + j] += this->numbers[this->length - 1 - i] * x.numbers[x.length - 1 - j];
		result_length = i + j + 1;
		if (buffer[i + j] >= 10) {
		  buffer[i + j + 1] += buffer[i + j] / 10;
		  buffer[i + j] %= 10;
		  ++result_length;
		}
	  }
	}
  
	if (sign) {
	  result_length++;
	}
	char* res = new char[result_length + 1];
	if (sign) {
	  res[0] = '-';
	  for (int i = 1; i < result_length; i++) {
		res[i] = buffer[result_length - 1 - i] + '0';
	  }
	} else {
	  for (int i = 0; i < result_length; i++) {
		res[i] = buffer[result_length - 1 - i] + '0';
	  }
	}
	res[result_length] = '\0';
  
	LongNumber ans{res};
	delete[] buffer;
	delete[] res;
	return ans;
}
  

LongNumber LongNumber::operator / (const LongNumber& x) const {
	// TODO
}

LongNumber LongNumber::operator % (const LongNumber& x) const {
	// TODO
}

int LongNumber::get_digits_number() const noexcept {
	return (length);
}

int LongNumber::get_rank_number(int rank) const {
	return (numbers[length - rank]);
}

bool LongNumber::is_negative() const noexcept {
	return (this->sign);
}

// ----------------------------------------------------------
// PRIVATE
// ----------------------------------------------------------
int LongNumber::get_length(const char* const str) const noexcept {
	int length = 0;
	while (str[length] != '\0') length++;
	return length;
}

// ----------------------------------------------------------
// FRIENDLY
// ----------------------------------------------------------
namespace naa {
	std::ostream& operator << (std::ostream &os, const LongNumber& x)
	{
		if (x.sign)
		{
			os << '-';
		}
		for (int i = 0; i < x.length; i++)
		{
			os << x.numbers[i];
		}
		return os;
	}
}
