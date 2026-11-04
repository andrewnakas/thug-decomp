struct State_002D96D8 {
    char pad0[8];
    int m8;
};

struct Mgr_002D96D8 {
    char pad0[0xC];
    void* mC;
    State_002D96D8* m10;
};

extern Mgr_002D96D8* D_00392068;
extern char D_00392E80[];
extern char D_0037C810[];
extern "C" int func_002D8158(void* p);
extern "C" void func_002D9550();
extern "C" void func_002F23B8(int a, int b, int c, int d, char* name, void (*cb)(), int e);

bool Cmd_002D96D8()
{
    Mgr_002D96D8* m = D_00392068;
    func_002F23B8(0, func_002D8158(m->mC), 2, 0, D_00392E80, func_002D9550, 0);
    for (int i = 0; i < 12; i++)
        func_002F23B8(0, func_002D8158(m->mC), 2, i + 1, D_0037C810, func_002D9550, 0);
    m->m10->m8 = 5;
    return true;
}
