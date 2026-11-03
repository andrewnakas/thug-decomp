/* cflags: -fopt-stack */
#include "game/idstring.h"

extern "C" void func_00104110(IdString* self, const char* s);

IdString& IdString::operator=(const IdString& o)
{
    func_00104110(this, o.m_str);
    return *this;
}
