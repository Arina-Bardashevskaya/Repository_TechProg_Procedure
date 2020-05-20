#include <fstream>
#include "conteiner.h"
#include "code_atd.h"

using namespace std;

namespace simple_codes {
	void Out(code& s, ofstream& ofst);

	void OutZamena(container& c, ofstream& ofst) {
		ofst << "Only rectangles." << endl;
		for (int i = 0; i < c.len; i++) {
			ofst << i << ": ";
			if (c.cont[i]->k == code::ZAMENA)
				Out(*(c.cont[i]), ofst);
			else
				ofst << endl;
		}
	}
}