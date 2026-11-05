typedef int qword __attribute__((mode(TI)));

struct Vec_00143EA0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

extern Vec_00143EA0 D_003C3DB0;
extern float D_0038A640;
extern float D_0038A644;
extern float D_0038A648;
extern float D_0038A64C;
extern float D_0038A650;
extern float D_0038A654;

extern "C" void func_00143EA0(const Vec_00143EA0* pos, float range, float b, float c, float d, float e, float f)
{
    D_003C3DB0 = *pos;
    if (range == 0.0f)
        D_0038A640 = 82944.0f;
    else
        D_0038A640 = range * range;
    D_0038A644 = b;
    if (c != 0.0f)
        D_0038A648 = c;
    else
        D_0038A648 = 1.0f;
    if (d != 0.0f)
        D_0038A64C = d;
    else
        D_0038A64C = 4.0f;
    if (e != 0.0f)
        D_0038A650 = e;
    else
        D_0038A650 = -10000.0f;
    if (f != 0.0f)
        D_0038A654 = f;
    else
        D_0038A654 = 0.8f;
}
