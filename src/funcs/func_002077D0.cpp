extern "C" void func_00109018();
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

// Pool-allocated object whose destructor drops a shared reference
// (vtable D_00367308, slot 1 is this deleting destructor). The destructor is
// pure with a body so it is not the key method: the vtable stays in the asm.
class Holder_002077D0 {
public:
    int m0;
    int m4;
    int m8;
    virtual ~Holder_002077D0() = 0;
    virtual void Run();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Holder_002077D0::~Holder_002077D0()
{
    func_00109018();
}
