#include "conteiner.h"
#include "code_atd.h"	
#include <fstream>

using namespace std;

namespace simple_codes {
	void Init(container& c) { c.len = 0; }
	void Clear(container& c) {
		for (int i = 0; i < c.len; i++) {
			delete c.cont[i];
		}
		c.len = 0;
	}

	code* In(ifstream& ifdt);

	void In(container& c, ifstream& ifst) {
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

	bool Compare(code* first, code* second);

	void Sort(container& c)
	{
		for (int i = 0; i < c.len - 1; i++)
		{
			for (int j = i + 1; j < c.len; j++)
			{
				if (Compare(c.cont[i], c.cont[j]))
				{
					code* tmp = c.cont[i];
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
			ofst << "  Length = "
				<< MesLength(*(c.cont[i])) << endl;
		}
	}
} // end simple_codes namespace