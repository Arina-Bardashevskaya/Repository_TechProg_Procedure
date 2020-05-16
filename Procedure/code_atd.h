#ifndef __code_atd__
#define __code_atd__
#include "zamena_atd.h"				
#include "cezar_atd.h"	
#include "numeric_atd.h"

namespace simple_codes
{
	struct code
	{
		enum key { ZAMENA, CEZAR, NUMERIC };
		key k;
		union {
			zamena r;
			cezar t;
			numeric b;
		};
		char message[20];

	};
}
#endif