extern void* D_00388A70;
extern "C" void func_0010A8D8(void* heap, void* p);

class Obj_001DC758 {
public:
    int m0;
    ~Obj_001DC758();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

extern "C" bool func_001DC418();
extern "C" void func_001DC7B0(Obj_001DC758* o);

Obj_001DC758::~Obj_001DC758()
{
    if (!func_001DC418())
        func_001DC7B0(this);
}
