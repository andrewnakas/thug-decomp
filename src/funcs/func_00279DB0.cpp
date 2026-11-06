extern "C" float func_002032A0(unsigned int name, int a);
extern "C" float func_001E5318(unsigned int name, int a);

struct Info_00279DB0 {
    char pad[0x31C];
    int m31C;
};

struct Obj_00279DB0 {
    char pad[0xC];
    Info_00279DB0* mC;
    float GetSpeed(int boost);
};

float Obj_00279DB0::GetSpeed(int boost)
{
    float v;
    if (mC->m31C)
        v = func_002032A0(0x0D24273B, 1);
    else
        v = func_002032A0(0x25F78481, 1);
    return boost ? func_001E5318(0x0A49FF23, 0) * v + v : v;
}
