#include <fstream>
#include "code_atd.h"
#include "conteiner.h"
using namespace std;

namespace simple_codes {
	int MesLength(code& s);

	bool Compare(code* first, code* second) {
		return MesLength(*first) < MesLength(*second);
	}
}