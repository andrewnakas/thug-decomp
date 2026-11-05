struct P_001344A8 {
    char pad[0x28];
    virtual ~P_001344A8();
};

extern "C" void func_00132A80(void* list);
extern "C" P_001344A8* func_00132A90(void* list, int a);
extern "C" unsigned int func_00135500(P_001344A8* p);
extern "C" void func_00135590(P_001344A8* p, int f);
extern "C" void func_00208BB8(void* g);
extern "C" void func_00134A98(void* list);

struct C_001344A8 {
    char pad[0xD0];
    void* mD0;
    void* mD4;
    void Clear();
};

void C_001344A8::Clear()
{
    if (!mD4)
        return;
    func_00132A80(mD0);
    P_001344A8* p;
    while ((p = func_00132A90(mD0, 0)) != 0) {
        if (func_00135500(p) & 8) {
            func_00135590(p, 0x40);
            delete p;
        }
    }
    func_00208BB8(mD4);
    func_00134A98(mD0);
}
