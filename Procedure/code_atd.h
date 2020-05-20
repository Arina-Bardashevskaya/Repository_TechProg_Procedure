#ifndef __code_atd__
#define __code_atd__
#include "zamena_atd.h"				
#include "cezar_atd.h"	
#include "numeric_atd.h"
namespace simple_codes
{
	const int MAX_STRING_SIZE = 80;
	struct code
	{
		enum key { ZAMENA, CEZAR, NUMERIC };
		key k;
		union 
		{
			zamena r;
			cezar t;
			numeric b;
		};
		char message[MAX_STRING_SIZE];
		char owner[MAX_STRING_SIZE];
	};
} // end simple_codes namespace
#endif