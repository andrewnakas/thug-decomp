/* cflags: -fopt-stack */
extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);

struct Obj_00292600 {
    int m0;
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
    ~Obj_00292600();
};

Obj_00292600::~Obj_00292600() {
}
