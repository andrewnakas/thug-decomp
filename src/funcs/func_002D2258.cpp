struct Obj_002D2258 {
    char pad0[0x144];
    int m144;
    int m148;
};

extern void* D_0038EB78;
extern unsigned int D_00392B14;
extern char D_0037BB60[];
extern char D_0037B848[];
extern char D_0037B870[];
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" void* func_00305F28(void* p);
extern "C" void func_001FA348(void* a, void* b);
extern "C" void func_00215DB8(int a, int b);
extern "C" unsigned int func_0010FC30();
extern "C" void func_001F0370(char* s, int a, int b, int c);

void Done_002D2258(void* job, int ok, Obj_002D2258* o)
{
    o->m148 = 0;
    if (ok) {
        void* p = D_0038EB78;
        func_00103F28(D_0037BB60);
        func_001FA348(p, func_00305F28(job));
        func_00215DB8(0, 0);
        o->m144 = 0;
        D_00392B14 = func_0010FC30();
    } else {
        func_00103F28(D_0037B848);
        func_001F0370(D_0037B870, 0, 0, 0);
    }
}
