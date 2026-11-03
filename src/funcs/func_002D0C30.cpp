extern int D_00392B14;
extern char D_0037B818[];
extern char D_0037B848[];
extern char D_0037B870[];
extern char D_0037B8A0[];
extern char D_0037B8E0[];
extern char D_0037B900[];
extern "C" unsigned int func_0010FC30();
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" void func_001F0370(char* s, int a, int b, int c);

struct State_002D0C30 {
    char pad0[0x144];
    int m144;
    int m148;
};

struct Obj_002D0C30 {
    void Report(int v, State_002D0C30* st);
};

void Obj_002D0C30::Report(int v, State_002D0C30* st)
{
    int dt = func_0010FC30() - D_00392B14;
    func_00103F28(D_0037B818, func_0010FC30(), dt, v);
    if (st->m148) {
        func_00103F28(D_0037B848);
        func_001F0370(D_0037B870, 0, 0, 0);
        st->m148 = 0;
    } else if (!st->m144) {
        func_00103F28(D_0037B8A0);
        func_001F0370(D_0037B8E0, 0, 0, 0);
    } else {
        func_00103F28(D_0037B900);
    }
    st->m144 = 1;
}
