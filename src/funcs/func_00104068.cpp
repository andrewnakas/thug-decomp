/* cflags: -fopt-stack */
#include "game/idstring.h"

extern int D_00388570;
extern "C" void func_00104170(IdString* self, const IdString* o);

IdString::IdString(const IdString& o)
{
    m_str = 0;
    func_00104170(this, &o);
    m_id = D_00388570;
    D_00388570 = D_00388570 + 1;
}
