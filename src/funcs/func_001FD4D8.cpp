extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

// Deleting destructor; vtable D_00366A90 = { header, ~Node104D78_001FD4D8, slot 2 }.
// The destructor is declared pure (with a body) so it is not the key method:
// the vtable stays in the asm (slot 2 is the key method, defined elsewhere).
class Node104D78_001FD4D8 {
public:
    int m0;
    int m4;
    virtual ~Node104D78_001FD4D8() = 0;
    virtual void Run();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Node104D78_001FD4D8::~Node104D78_001FD4D8()
{
}
