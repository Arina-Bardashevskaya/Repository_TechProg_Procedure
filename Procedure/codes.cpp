#include <fstream>
#include "code_atd.h"
using namespace std;

namespace simple_codes {
	void In(zamena& r, ifstream& ist);
	void In(cezar& t, ifstream& ist);

	code* In(ifstream& ifst)
	{
		code* sp;
		int k;
		ifst >> k;
		sp = new code;
		switch (k) {
		case 1:
			sp->k = code::key::ZAMENA;
			In(sp->r, ifst);
			ifst >> sp->message;
			return sp;
		case 2:
			sp->k = code::key::CEZAR;
			In(sp->t, ifst);
			ifst >> sp->message;
			return sp;
		default:
			return 0;
		}
	}
	void Out(zamena& r, ofstream& ofst, char message[20]);
	void Out(cezar& t, ofstream& ofst, char message[20]);
	void Out(code& s, ofstream& ofst) {
		switch (s.k) {
		case code::key::ZAMENA:
			Out(s.r, ofst, s.message);
			break;
		case code::key::CEZAR:
			Out(s.t, ofst, s.message);
			break;
		default:
			ofst << "Incorrect figure!" << endl;
		}
	}
} // end simple_codes namespace