#include "Exceptions.h"
const char* bad_range::what() const noexcept
{
	return "ERROR: ����� �� ������� ���������� ������������� �������";
}

const char* bad_lenght::what() const noexcept
{
	return "ERROR: �������� ����� ���������� ������������� �������";
}