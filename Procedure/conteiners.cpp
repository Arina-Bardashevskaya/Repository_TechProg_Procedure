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

	void MultiMethod(container& c, ofstream& ofst) {
		ofst << "Multimethod." << endl;
		for (int i = 0; i < c.len - 1; i++) {
			for (int j = i + 1; j < c.len; j++) {
				switch (c.cont[i]->k) {
				case code::key::ZAMENA:
					switch (c.cont[j]->k) {
					case code::key::ZAMENA:
						ofst << "Zamena and Zamena." << endl;
						break;
					case code::key::CEZAR:
						ofst << "Zamena and Cezar." << endl;
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
					default:
						ofst << "Unknown type." << endl;
					}
					break;
				default:
					ofst << "Unknown type." << endl;
				}
				Out(*(c.cont[i]), ofst);
				Out(*(c.cont[j]), ofst);
			}
		}
	}
} // end simple_codes namespace
