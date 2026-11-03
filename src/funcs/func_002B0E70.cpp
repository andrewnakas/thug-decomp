extern void* D_0038FC78;
extern char D_00378DC8[];

struct Data_002B0E70 {
    unsigned int m0;
    signed char m4;
    signed char m5;
    char m6[0x10];
};

struct Mgr_002B0E70 {
    char pad[0x14];
    void* m14;
};

extern "C" int func_00201338(void* a, void* b);
extern "C" int func_002A3B50(Mgr_002B0E70* m);
extern "C" int func_002A1FF0(Mgr_002B0E70* m);
extern "C" int func_002A39F8(Mgr_002B0E70* m);
extern "C" int func_002A1B30(Mgr_002B0E70* m);
extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F938(void* p);
extern "C" int func_001F0D78(char* s);
extern "C" int func_002A8560(Mgr_002B0E70* m);
extern "C" signed char* func_002A2270(Mgr_002B0E70* m);
extern "C" int func_00331950(signed char* a, char* b);

extern "C" int func_002B0E70(Mgr_002B0E70* m, int* reason, Data_002B0E70* d, void* conn)
{
    if (func_00201338(m->m14, conn)) {
        *reason = 4;
        return 0;
    }
    if (d->m4) {
        if (func_002A3B50(m) >= func_002A1FF0(m)) {
            *reason = 5;
            return 0;
        }
    } else {
        if (func_002A39F8(m) >= func_002A1B30(m)) {
            *reason = 0;
            return 0;
        }
    }
    if (d->m0 != 0x30036) {
        *reason = 2;
        return 0;
    }
    if (*(unsigned short*)&d->m4 == 0) {
        if (func_0024F938(func_0022E358(D_0038FC78)) != func_001F0D78(D_00378DC8)) {
            if (!func_002A8560(m)) {
                *reason = 3;
                return 0;
            }
        }
    }
    signed char* pw = func_002A2270(m);
    if (*pw == 0)
        return 1;
    if (!func_00331950(pw, d->m6))
        return 1;
    *reason = 1;
    return 0;
}
