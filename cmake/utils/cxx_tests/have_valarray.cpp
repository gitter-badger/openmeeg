// DESCRIPTION
//
//   Test to check whether the C++ compiler has valarray<T>.
//   In sync with AC_CXX_HAVE_VALARRAY (2008-04-12).
//
// COPYLEFT
//
//   Copyright (c) 2009 Theo Papadopoulo <Theodore.Papadopoulo@inria.fr>
//   Copyright (c) 2008 Todd Veldhuizen
//   Copyright (c) 2008 Luc Maisonobe <luc@spaceroots.org>
//
//   Copying and distribution of this file, with or without modification, are
//   permitted in any medium without royalty provided the copyright notice
//   and this notice are preserved.

#include <valarray>
#ifdef HAVE_NAMESPACES
using namespace std;
#endif

int main() {
    valarray<float> x(100);
    return 0;
}
