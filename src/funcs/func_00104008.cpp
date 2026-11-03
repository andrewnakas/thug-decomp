#include "game/idstring.h"

extern int D_00388570;

IdString::IdString()
{
    m_str = 0;
    m_id = D_00388570;
    D_00388570 = D_00388570 + 1;
}
