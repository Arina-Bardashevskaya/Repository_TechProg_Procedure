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
	void Out(container& c, ofstream& ofst)
	{
		ofst << "Container contains " << c.len
			<< " elements." << endl;
		for (int i = 0; i < c.len; i++)
		{
			ofst << i << ": ";
			Out(*(c.cont[i]), ofst);
		}
	}
} // end simple_codes namespace