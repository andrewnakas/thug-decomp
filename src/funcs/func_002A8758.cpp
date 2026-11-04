extern "C" void func_00105260(void* p, int v);

struct Holder_002A8758 {
    int m0;
    int m4;
    int m8;
};

struct Inst_002A8758 {
    char pad0[0xB0];
    int mB0;
};

extern Holder_002A8758* D_0038C308;
extern Inst_002A8758* D_00392068;

struct Obj_002A8758 {
    bool Start();
};

bool Obj_002A8758::Start() {
    func_00105260(&D_0038C308->m8, D_00392068->mB0);
    return true;
}
