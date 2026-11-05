extern "C" void func_002CC840(int* x, int* z, int rot)
{
    int ox = *x;
    int oz = *z;
    switch (rot) {
    case 0:
        break;
    case 1:
        *x = oz;
        *z = -ox;
        break;
    case 2:
        *x = -ox;
        *z = -oz;
        break;
    case 3:
        *x = -oz;
        *z = ox;
        break;
    }
}
