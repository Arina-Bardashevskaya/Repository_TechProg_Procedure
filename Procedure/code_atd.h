#ifndef __code_atd__
#define __code_atd__
#include "zamena_atd.h"				
#include "cezar_atd.h"		

namespace simple_codes
{
	struct code
	{
		enum key { ZAMENA, CEZAR };
		key k;
		union {
			zamena r;
			cezar t;
		};
		char message[20];
		char owner[20];

	};
}
#endif