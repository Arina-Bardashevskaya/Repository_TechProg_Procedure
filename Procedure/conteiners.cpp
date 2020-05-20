#include "conteiner_atd.h"
#include "code_atd.h"	
#include <fstream>

using namespace std;

namespace simple_codes 
{
	void Init(container& c) 
	{ 
		c.len = 0; 
	}
	void Clear(container& c) 
	{
		for (int i = 0; i < c.len; i++) 
		{
			delete c.cont[i];
		}
		c.len = 0;
	}

	code* In(ifstream& ifdt);

	void In(container& c, ifstream& ifst) 
	{
		while (!ifst.eof())
		{
			if (c.len > 99)
			{
				break;
			}
			else
			{
				if ((c.cont[c.len] = In(ifst)) != 0)
					c.len++;
			}
		}
	}


	void Out(code& s, ofstream& ofst);

	bool Compare(code *first, code *second);

	void Sort(container& c)
	{
		for (int i = 0; i < c.len - 1; i++)
		{
			for (int j = i + 1; j < c.len; j++)
			{
				if (Compare(c.cont[i], c.cont[j]))
				{
					code  *tmp = c.cont[i];
					c.cont[i] = c.cont[j];
					c.cont[j] = tmp;
				}
			}
		}
	}

	void Out(code& s, ofstream& ofst);

	int MesLength(code& s);

	void Out(container& c, ofstream& ofst)
	{
		ofst << "Container contains " << c.len
			<< " elements." << endl;
		for (int i = 0; i < c.len; i++)
		{
			ofst << i << ": ";
			Out(*(c.cont[i]), ofst);
			ofst << "Length = "
				<< MesLength(*(c.cont[i])) << "." << endl;
		}
	}

	void OutZamena(container& c, ofstream& ofst)
	{
		ofst << "Container contains " << c.len
			<< " elements." << endl;
		ofst << "Only zamena's." << endl;
		for (int i = 0; i < c.len; i++)
		{
			ofst << i << ": ";
			if (c.cont[i]->k == code::ZAMENA)
			{
				Out(*(c.cont[i]), ofst);
				ofst << "Length = "
					<< MesLength(*(c.cont[i])) << "." << endl;
			}
			else
				ofst << endl;
		}
	}

	void MultiMethod(container& c, ofstream& ofst)
	{
		ofst << "Multimethod." << endl;
		for (int i = 0; i < c.len - 1; i++)
		{
			for (int j = i + 1; j < c.len; j++)
			{
				switch (c.cont[i]->k) {
				case code::key::ZAMENA:
					switch (c.cont[j]->k) {
					case code::key::ZAMENA:
						ofst << "Zamena and Zamena." << endl;
						break;
					case code::key::CEZAR:
						ofst << "Zamena and Cezar." << endl;
						break;
					case code::key::NUMERIC:
						ofst << "Zamena and Numeric." << endl;
						break;
					default:
						ofst << "Unknown type." << endl;
					}
					break;
				case code::key::CEZAR:
					switch (c.cont[j]->k) {
					case code::key::ZAMENA:
						ofst << "Cezar and Zamena." << endl;
						break;
					case code::key::CEZAR:
						ofst << "Cezar and Cezar." << endl;
						break;
					case code::key::NUMERIC:
						ofst << "Cezar and Numeric." << endl;
						break;
					default:
						ofst << "Unknown type." << endl;
					}
					break;
				case code::key::NUMERIC:
					switch (c.cont[j]->k) {
					case code::key::ZAMENA:
						ofst << "Numeric and Zamena." << endl;
						break;
					case code::key::CEZAR:
						ofst << "Numeric and Cezar." << endl;
						break;
					case code::key::NUMERIC:
						ofst << "Numeric and Numeric." << endl;
						break;
					default:
						ofst << "Unknown type." << endl;
					}
					break;
				default:
					ofst << "Unknown type." << endl;
				}
				Out(*(c.cont[i]), ofst);
				ofst << endl;
				Out(*(c.cont[j]), ofst);
				ofst << endl;
			}
		}
	}
} // end simple_codes namespace