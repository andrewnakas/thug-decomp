struct Skater_002167D0 {
    char pad[0x31C];
    int m31C;
};

extern void* D_0038FC78;
extern char D_00370B68[];

extern "C" Skater_002167D0* func_0022DE70(void*, unsigned int);
extern "C" void func_00103F28(char*, int);
extern "C" void* func_0022E358(void*);
extern "C" int func_0024F780(void*);
extern "C" int func_0013B0E0();
extern "C" void func_0013B330(int);
extern "C" void* func_00203360(Skater_002167D0*);
extern "C" void func_0023AB50(void*);

bool func_002167D0()
{
    void* mgr = D_0038FC78;
    unsigned int i;
    Skater_002167D0* s;
    for (i = 0; i < 8; i++) {
        s = func_0022DE70(mgr, i);
        if (s && s->m31C)
            func_00103F28(D_00370B68, 0x2B55);
    }
    int a = func_0024F780(func_0022E358(mgr));
    int b = func_0013B0E0();
    if (!((a == 1 && b == 2) || (a == 2 && b == 1)))
        func_0013B330(a);
    for (i = 0; i < 8; i++) {
        s = func_0022DE70(mgr, i);
        if (s && s->m31C)
            func_0023AB50(func_00203360(s));
    }
    return true;
}
