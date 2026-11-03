#include "game/vector.h"

void Vector::Swizzle()
{
    float nx = -x;
    float nz = -z;
    z = y;
    x = nx;
    y = nz;
}
