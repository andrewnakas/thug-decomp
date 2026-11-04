extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

// Deleting destructor; vtable D_00361AA0 = { header, ~Node1873E0, slot 2 }.
// The destructor is declared pure (with a body) so it is not the key method:
// the vtable stays in the asm (slot 2 is the key method, defined elsewhere).
class Node1873E0 {
public:
    int m0;
    int m4;
    virtual ~Node1873E0() = 0;
    virtual void Run();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Node1873E0::~Node1873E0()
{
}
