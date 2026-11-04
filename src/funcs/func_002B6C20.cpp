extern void* D_00388A70;
extern char D_0037A400[];
extern "C" void func_0010A8D8(void* pool, void* p);

struct Obj_002B6C20 {
    int m0;
    int m4;
    int m8;
    void* mC;
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
    ~Obj_002B6C20();
};

Obj_002B6C20::~Obj_002B6C20() {
    mC = D_0037A400;
}
