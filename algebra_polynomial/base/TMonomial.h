#ifndef __TMONOMIAL_H__
#define __TMONOMIAL_H__

#include <iostream>
using namespace std;

//����� ����� (������������ ��������)
class TMonom
{
protected:
	double coeff;      //����������� ������
	int index[3];      //������ ��������(������� �������)
public:
	//�����������
	TMonom(double Mcoeff = 1, int Xindex = 0, int Yindex = 0, int Zindex = 0)
	{
		coeff = Mcoeff;
		index[0] = Xindex;
		index[1] = Yindex;
		index[2] = Zindex;
	}
	//����������� �����������
	TMonom(const TMonom& Mon)
	{
		coeff = Mon.coeff;
		index[0] = Mon.index[0];
		index[1] = Mon.index[1];
		index[2] = Mon.index[2];
	}
	//����������
	~TMonom()
	{
		coeff = 0;
		index[0] = 0;
		index[1] = 0;
		index[2] = 0;
	}
	//���������� �����������
	void SetCoeff(double Mcoeff)
	{
		coeff = Mcoeff;
	}
	//�������� �����������
	double GetCoeff()
	{
		return coeff;
	}
	//�������� ������ X
	int GetIndexX()
	{
		return index[0];
	}
	//�������� ������ Y
	int GetIndexY()
	{
		return index[1];
	}
	//�������� ������ Z
	int GetIndexZ()
	{
		return index[2];
	}
	//�������� ������������
	TMonom& operator=(const TMonom& Mon)
	{
		coeff = Mon.coeff;
		index[0] = Mon.index[0];
		index[1] = Mon.index[1];
		index[2] = Mon.index[2];
		return *this;
	}
	//�������� ��������� (�����)
	bool operator==(const TMonom& Mon)
	{
		if ((coeff == Mon.coeff) && (index[0] == Mon.index[0]) && (index[1] == Mon.index[1]) && (index[2] == Mon.index[2]))
		{
			return true;
		}
		else return false;
	}
	//�������� ��������� (������)
	bool operator<(const TMonom& Mon)
	{
		if ((index[0] < Mon.index[0]) || (index[1] < Mon.index[1]) || (index[2] < Mon.index[2]))
		{
			return true;
		}
		else return false;
	}
	//�������� ��������� (������)
	bool operator>(const TMonom& Mon)
	{
		if ((*this < Mon) || (*this == Mon))
		{
			return false;
		}
		else return true;
	}
	//�������� ��������� (������ ��� �����)
	bool operator<=(const TMonom& Mon)
	{
		if ((*this < Mon) || (*this == Mon))
		{
			return true;
		}
		else return false;
	}
	//�������� ��������� (������ ��� �����)
	bool operator>=(const TMonom& Mon)
	{
		if ((*this > Mon) || (*this == Mon))
		{
			return true;
		}
		else return false;
	}
	//�������� ������
	bool Similar(const TMonom& Mon)
	{
		if ((index[0] == Mon.index[0]) && (index[1] == Mon.index[1]) && (index[2] == Mon.index[2]))
		{
			return true;
		}
		else return false;
	}
	//�������� �������
	TMonom operator+(const TMonom& Mon)
	{
		//�� ������ ����� ��������� � ���� ������ ���� �������� �� �������!!!!
		TMonom res(coeff, index[0], index[1], index[2]);
		res.coeff = res.coeff + Mon.coeff;
		return res;
	}
	//��������� �������
	TMonom operator*(const TMonom& Mon)
	{
		TMonom res(coeff, index[0], index[1], index[2]);
		res.coeff = res.coeff * Mon.coeff;
		res.index[0] = res.index[0] + Mon.index[0];
		res.index[1] = res.index[1] + Mon.index[1];
		res.index[2] = res.index[2] + Mon.index[2];
		return res;
	}
	//��������� �� ���������
	void MiltConst(const double& val)
	{
		coeff = coeff * val;
	}
	//���������� � �����
	double CalcPoint(const double& x, const double& y, const double& z)
	{
		double res = 0;
		res = coeff * pow(x, index[0]) * pow(y, index[1]) * pow(z, index[2]);
		return res;
	}

	//����� ������ (������)
	friend ostream& operator<<(ostream& out, const TMonom& Mon)
	{
		out << Mon.coeff;
		if (Mon.index[0] != 0) { out << "x^" << Mon.index[0]; }
		if (Mon.index[1] != 0) { out << "y^" << Mon.index[1]; }
		if (Mon.index[2] != 0) { out << "z^" << Mon.index[2]; }
		return out;
	}
	//������ �������� � ������� ����� ������������
	friend class TPolinom;
};

#endif