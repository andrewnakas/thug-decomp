extern void* D_00388A70;
extern char D_00378BD8[];
extern "C" void func_0010A8D8(void* pool, void* p);

struct Obj_002AB868 {
    int m0;
    int m4;
    void* m8;
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
    ~Obj_002AB868();
};

Obj_002AB868::~Obj_002AB868() {
    m8 = D_00378BD8;
}
