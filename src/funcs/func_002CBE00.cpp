extern void* D_00388A70;
extern int D_00392940;
extern "C" void func_0010A8D8(void* pool, void* p);

struct Obj_002CBE00;
extern "C" void func_002CC458(Obj_002CBE00* o);

struct Obj_002CBE00 {
    int m0;
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
    ~Obj_002CBE00();
};

Obj_002CBE00::~Obj_002CBE00()
{
    func_002CC458(this);
    D_00392940 = 0;
}
