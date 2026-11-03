extern void* D_00388A70;
extern char D_0037BD78[];
extern "C" void func_0010A8D8(void* pool, void* p);

struct Obj_002D3F70 {
    int m0;
    int m4;
    void* m8;
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
    ~Obj_002D3F70();
};

Obj_002D3F70::~Obj_002D3F70() {
    m8 = D_0037BD78;
}
