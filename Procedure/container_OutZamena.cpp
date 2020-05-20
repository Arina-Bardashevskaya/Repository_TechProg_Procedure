#include <fstream>
#include "conteiner.h"
#include "code_atd.h"

using namespace std;

namespace simple_codes {
	void Out(code& s, ofstream& ofst);
	int MesLength(code& s);

	void OutZamena(container& c, ofstream& ofst) {
		ofst << "Container contains " << c.len
			<< " elements." << endl;
		ofst << "Only zamena's." << endl;
		for (int i = 0; i < c.len; i++) {
			ofst << i << ": ";
			if (c.cont[i]->k == code::ZAMENA)
			{
				Out(*(c.cont[i]), ofst);
				ofst << "   Length = "
					<< MesLength(*(c.cont[i])) << endl;
			}
			else
				ofst << endl;
		}
	}
}