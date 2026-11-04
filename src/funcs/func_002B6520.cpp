extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);

struct Obj_002B6520 {
    int m0;
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
    ~Obj_002B6520();
};

Obj_002B6520::~Obj_002B6520() {
}
