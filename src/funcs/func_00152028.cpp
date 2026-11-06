extern float D_0038C024;
extern unsigned int D_0038C028;

static inline float Min_00152028(float a, float b) { return a < b ? a : b; }
static inline float Max_00152028(float a, float b) { return a > b ? a : b; }

void func_00152028(unsigned int* c)
{
    D_0038C024 = Max_00152028(Min_00152028(((unsigned char*)c)[3] * 0.0078125f, 1.0f), 0.0f);
    D_0038C028 = *c & 0xFFFFFF;
}
