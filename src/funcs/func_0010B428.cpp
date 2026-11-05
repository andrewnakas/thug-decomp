struct Mgr_0010B428 {
    char pad[0xDC];
    int mDC;
};

extern Mgr_0010B428* D_00388A70;
extern char D_00388AB8[];
extern "C" void func_0010A950(Mgr_0010B428* mgr, int v);
extern "C" void func_0010A9B0(Mgr_0010B428* mgr);
extern "C" void* func_001046B0(int size);
extern "C" void* func_0010C190(void* p, int size);

struct Obj_0010B428;
extern "C" void* func_0010AF60(Obj_0010B428* self, void* heap, int a, char* name);

struct Obj_0010B428 {
    char pad[0xF8];
    void* mF8;
    void* mFC;
    void Init();
};

void Obj_0010B428::Init()
{
    if (!mF8) {
        func_0010A950(D_00388A70, D_00388A70->mDC);
        mF8 = func_0010C190(func_001046B0(0x1C), 0x27100);
        mFC = func_0010AF60(this, mF8, 1, D_00388AB8);
        func_0010A9B0(D_00388A70);
    }
}
