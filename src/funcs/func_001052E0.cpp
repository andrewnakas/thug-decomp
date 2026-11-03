extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

// Deleting destructor (vtable D_0035A9D0); same shape as func_00104D78.
// The destructor is declared pure (with a body) so it is not the key method.
class Iter1052E0 {
public:
    int m0;
    int m4;
    virtual ~Iter1052E0() = 0;
    virtual void Run();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Iter1052E0::~Iter1052E0()
{
}
