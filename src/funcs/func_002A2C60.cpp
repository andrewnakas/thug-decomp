extern "C" unsigned int func_0010FC30();
extern "C" void func_00105260(void* p, int v);

struct Holder_002A2C60 {
    int m0;
    int m4;
    int m8;
};

extern Holder_002A2C60* D_0038C308;
extern unsigned int D_00394170;

struct Obj_002A2C60 {
    char pad0[0xAC];
    int mAC;
    void Start();
};

void Obj_002A2C60::Start() {
    Holder_002A2C60* h = D_0038C308;
    D_00394170 = func_0010FC30();
    func_00105260(&h->m8, mAC);
}
