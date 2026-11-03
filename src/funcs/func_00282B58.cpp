struct Sub_00282B58 { char pad[0x40]; int m40; char pad1[0xAC - 0x44]; int mAC; };
struct Glob_00282B58 { char pad[0x24]; void* m24; };
extern Glob_00282B58* D_0038FC78;
extern int D_00390EF8;
extern "C" float func_002032A0(unsigned int, int);
extern "C" int func_00263BD8(void*, unsigned int);
extern "C" void func_00263C18(void*, int);
extern "C" int func_001E53A0(unsigned int, int);

struct Obj_00282B58 {
    char pad[0x5B0];
    Sub_00282B58* m_sub;
    float Get();
};

float Obj_00282B58::Get()
{
    float r;
    if (m_sub->m40 || m_sub->mAC) {
        r = func_002032A0(0xFAA40754, 0) / func_002032A0(0x441C38A0, 0);
    } else {
        r = func_002032A0(0xFAA40754, 0) / func_002032A0(0xC31CA696, 0);
    }
    if (func_00263BD8(D_0038FC78->m24, 0x9C8C6DF1)) {
        void* t = D_0038FC78->m24;
        func_00263C18(t, func_001E53A0(0x9C8C6DF1, 0));
        r *= func_002032A0(0x0EC128F0, 0);
        D_00390EF8 = 1;
    }
    return r;
}
