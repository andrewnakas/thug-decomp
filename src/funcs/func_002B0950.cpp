struct P_002B0950 {
    signed char m0;
};

extern void* D_0038FC78;
extern char D_003794E8[];
extern char D_00379500[];
extern "C" void* func_0022E358(void* g);
extern "C" int func_0024F540(void* p);
extern "C" void func_0024F418(void* p, int n);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" int func_0022DD38(void* g);
extern "C" void func_0022CF78(void* g, int v);

struct Obj_002B0950 {
    P_002B0950* m0;
    bool Set();
};

bool Obj_002B0950::Set()
{
    int n = m0->m0;
    void* g = D_0038FC78;
    if (n > 0 && !func_0024F540(func_0022E358(g))) {
        func_0024F418(func_0022E358(g), n);
        func_001F0370(D_003794E8, 0, 0, 0);
        if (func_0022DD38(g)) {
            func_001F0370(D_00379500, 0, func_0022DD38(g), 0);
            func_0022CF78(g, func_0022DD38(g));
        }
    } else {
        func_0024F418(func_0022E358(g), n);
    }
    return true;
}
