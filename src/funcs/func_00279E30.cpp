struct Car_00279E30 {
    char pad0[0x31C];
    int m31C;
};

struct Obj_00279E30 {
    char pad0[0xC];
    Car_00279E30* mC;
    float Get(int a, int b);
};

extern int D_00392068;
extern "C" int func_002A1A28(int g);
extern "C" float func_002032A0(unsigned int id, int a);

float Obj_00279E30::Get(int a, int b)
{
    float base;
    if (mC->m31C) {
        if (func_002A1A28(D_00392068)) base = func_002032A0(0xF2E35FA3, 1);
        else base = func_002032A0(0xECB41860, 1);
    } else {
        if (func_002A1A28(D_00392068)) base = func_002032A0(0xDBD6D58A, 1);
        else base = func_002032A0(0xC5819249, 1);
    }
    float n = 0.0f;
    if (a) n = 1.0f;
    if (b) n += 1.0f;
    return n * func_002032A0(0xEEF4AFB3, 0) * base + base;
}
