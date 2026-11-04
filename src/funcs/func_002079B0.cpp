extern "C" void func_001830E8();
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

// Pool-allocated object whose destructor drops a shared reference
// (vtable D_00367278, slot 1 is this deleting destructor). The destructor is
// pure with a body so it is not the key method: the vtable stays in the asm.
class Holder_002079B0 {
public:
    int m0;
    int m4;
    int m8;
    virtual ~Holder_002079B0() = 0;
    virtual void Run();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Holder_002079B0::~Holder_002079B0()
{
    func_001830E8();
}
