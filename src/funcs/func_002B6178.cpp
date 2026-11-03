extern void* D_00388A70;
extern char D_00379E70[];
extern "C" void func_0010A8D8(void* pool, void* p);

struct Obj_002B6178 {
    int m0;
    int m4;
    void* m8;
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
    ~Obj_002B6178();
};

Obj_002B6178::~Obj_002B6178() {
    m8 = D_00379E70;
}
