#include "game/idstring.h"

extern int D_00388570;
extern "C" IdString* func_00104110(IdString* self, const char* s);

IdString::IdString(const char* s)
{
    m_str = 0;
    m_id = D_00388570;
    D_00388570 = D_00388570 + 1;
    func_00104110(this, s);
}
