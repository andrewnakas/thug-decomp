struct Info_002AF728 {
    int m0;
    int m4;
    int m8;
    char mC[0x1C - 0xC];
    char m1C[4];
};

extern "C" void func_002A7B50(void* p, int a, int b, char* c, char* d, int e, int f, int g, int h);

struct Obj_002AF728 {
    Info_002AF728* m0;
    char pad4[0x1C - 4];
    void* m1C;
    bool Run();
};

bool Obj_002AF728::Run()
{
    Info_002AF728* i = m0;
    func_002A7B50(m1C, 0, i->m4, i->mC, i->m1C, 0, 0, 0, i->m8);
    return true;
}
