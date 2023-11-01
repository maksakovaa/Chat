#include "Exceptions.h"
const char* bad_range::what() const noexcept
{
	return "ERROR: Выход за пределы двумерного динамического массива";
}

const char* bad_lenght::what() const noexcept
{
	return "ERROR: Неверная длина двумерного динамического массива";
}