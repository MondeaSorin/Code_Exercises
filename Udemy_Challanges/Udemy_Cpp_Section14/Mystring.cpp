#include "Mystring.h"

Mystring::Mystring()
	:str(nullptr)
{
	this->str = new char[1];
	*this->str = '\0';
}

Mystring::Mystring(const char* s)
	:str(nullptr)
{
	if (s != nullptr)
	{
		this->str = new char[strlen(s) + 1];
		strcpy_s(this->str,strlen(s) + 1, s);
	}
	else
	{
		this->str = new char[1];
		*this->str = '\0';
	}
}

Mystring::Mystring(const Mystring& source)
	:str(nullptr)
{
	this->str = new char[strlen(source.str) + 1];
	strcpy_s(this->str, strlen(source.str) + 1, source.str);
}

Mystring::Mystring(Mystring&& source) noexcept
	:str(source.str)
{
	source.str = nullptr;
}

Mystring::~Mystring()
{
	if (this->str != nullptr)
		delete[] this->str;
}

Mystring& Mystring::operator=(const Mystring& rhs)
{
	if (this == &rhs) return *this;

	if (this->str != nullptr)
		delete[] this->str;

	this->str = new char[strlen(rhs.str) + 1];
	strcpy_s(this->str, strlen(rhs.str) + 1, rhs.str);

	return *this;
}

Mystring& Mystring::operator=(Mystring&& rhs) noexcept
{
	if (this == &rhs) return *this;

	if (this->str != nullptr)
		delete[] this->str;

	this->str = rhs.str;
	rhs.str = nullptr;

	return *this;
}

void Mystring::display() const
{
	std::cout << this->str << " : " << get_length() << std::endl;
}

int Mystring::get_length() const { return strlen(this->str); }
const char* Mystring::get_str() const { return this->str;; }

Mystring Mystring::operator-() const
{
	char* new_str = new char[strlen(str) + 1];
	strcpy_s(new_str, strlen(str) + 1, str);

	for (int i = 0; i < strlen(str); i++)
		new_str[i] = std::tolower(new_str[i]);

	Mystring temp(new_str);
	delete[] new_str;

	return temp;
}

Mystring& Mystring::operator++()
{
	for (int i = 0; i < strlen(str); i++)
		this->str[i] = std::toupper(this->str[i]);

	return *this;
}

Mystring Mystring::operator++(int)
{
	Mystring temp(*this);
	Mystring::operator++();
	return temp;
}

bool Mystring::operator==(const Mystring& rhs) const
{
	return !std::strcmp(this->str, rhs.str);
}

bool Mystring::operator!=(const Mystring& rhs) const
{
	return !Mystring::operator==(rhs);
}

bool Mystring::operator<(const Mystring& rhs) const
{
	return std::strcmp(this->str, rhs.str) < 0;
}

bool Mystring::operator>(const Mystring& rhs) const
{
	return std::strcmp(this->str, rhs.str) > 0;
}

Mystring Mystring::operator+(const Mystring& rhs) const
{
	char* buff = new char[strlen(this->str) + strlen(rhs.str) + 1];
	strcpy_s(buff, strlen(this->str) + 1, this->str);
	strcat_s(buff, strlen(this->str) + strlen(rhs.str) + 1, rhs.str);
	
	Mystring temp{ buff };
	delete[] buff;
	
	return temp;
}

Mystring& Mystring::operator+=(const Mystring& rhs)
{
	*this = *this + rhs;
	return *this;
}

Mystring Mystring::operator*(int value) const
{
	if (value <= 0) return *this;

	Mystring temp(*this);
	delete[] temp.str;
	temp.str = new char[strlen(this->str) * value + 1];
	strcpy_s(temp.str, 1, "");

	int counter{ 1 };
	while (value > 0)
	{
		strcat_s(temp.str, strlen(this->str) * counter++ + 1, this->str);
		--value;
	}

	return temp;
}

Mystring& Mystring::operator*=(int value)
{
	*this = *this * value;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Mystring& rhs)
{
	os << rhs.str;
	return os;
}

std::istream& operator>>(std::istream& in, Mystring& rhs)
{
	char buffer[100];
	std::cin.getline(buffer, 100);
	rhs = Mystring(buffer);
	return in;
}