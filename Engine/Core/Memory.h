#pragma once

#define _CRTDBG_MAP_ALLOX
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK  , __FILE__ , __LINE__)

#else
	#define new new
#endif

namespace neu
{
	void InitializeMemory();
}