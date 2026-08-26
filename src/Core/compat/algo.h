//////////////////////////////////////////////////////////////////////////////
// Filename    : algo.h (compatibility shim)
// Description :
// <algo.h> was the pre-standard SGI STL algorithm header. Forward to the
// standard ones so the eleven files that still include it keep building.
//////////////////////////////////////////////////////////////////////////////

#ifndef __DE_COMPAT_ALGO_H__
#define __DE_COMPAT_ALGO_H__

#include <algorithm>
#include <numeric>
#include <functional>

#endif // __DE_COMPAT_ALGO_H__
