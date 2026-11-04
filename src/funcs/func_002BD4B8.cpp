struct Node_002BD4B8;

struct Item_002BD4B8 {
    char pad0[0x38];
    virtual void Update();
    virtual ~Item_002BD4B8();
};

struct Mgr_002BD4B8;
struct Obj_002BD4B8;

extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void func_002C3330(Obj_002BD4B8* o);
extern "C" void func_002CC458(void* p);
extern "C" Item_002BD4B8* func_002BC5A0(Node_002BD4B8* n);
extern "C" void func_002C2588(Obj_002BD4B8* o, Item_002BD4B8* it, Node_002BD4B8** head);
extern "C" void func_002C32A0(Obj_002BD4B8* o, int a);
extern "C" void func_002B7CE0(Mgr_002BD4B8* m);
extern "C" void func_002B8FA8(Mgr_002BD4B8* m);
extern "C" void func_002CBE00(void* p, int f);
extern "C" void func_002BC5A8(Node_002BD4B8* n);
extern "C" void func_002C47A8();
extern "C" void func_002C4810();
extern "C" void func_002C4878();

struct Obj_002BD4B8 {
    Mgr_002BD4B8* m0;
    int m4;
    int m8;
    Node_002BD4B8* mC;
    char pad10[0x84 - 0x10];
    Node_002BD4B8* m84;
    char pad88[0x90 - 0x88];
    int m90;
    char pad94[0x3538 - 0x94];
    void** m3538;
    char pad353C[0x6A64 - 0x353C];
    int m6A64;
    char pad6A68[0x6B00 - 0x6A68];
    void* m6B00;
    void Shutdown(int a);
};

void Obj_002BD4B8::Shutdown(int a)
{
    if (!m4) return;
    if (!(m6A64 & 5)) func_002C3330(this);
    func_002CC458(m6B00);
    Node_002BD4B8* n;
    while ((n = m84) != 0) {
        Item_002BD4B8* it = func_002BC5A0(n);
        func_002C2588(this, it, &m84);
        if (it) delete it;
    }
    m90 = 0;
    func_002C32A0(this, a);
    func_002B7CE0(m0);
    func_002B8FA8(m0);
    for (int i = 0; i < 0x3A; i++) {
        if (m3538[i]) func_0010A8D8(D_00388A70, m3538[i]);
    }
    if (m3538) func_0010A8D8(D_00388A70, m3538);
    m3538 = 0;
    m6A64 = (m6A64 & ~1) | 4;
    m4 = 0;
    m8 = 0;
    if (m6B00) func_002CBE00(m6B00, 3);
    m6B00 = 0;
    if (mC) func_002BC5A8(mC);
    mC = 0;
    func_002C47A8();
    func_002C4810();
    func_002C4878();
}
