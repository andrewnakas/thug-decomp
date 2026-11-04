extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

// Deleting destructor; vtable D_0035C548 = { header, ~Node114F88, slot 2 }.
// The destructor is declared pure (with a body) so it is not the key method:
// the vtable stays in the asm (slot 2 is the key method, defined elsewhere).
class Node114F88 {
public:
    int m0;
    int m4;
    virtual ~Node114F88() = 0;
    virtual void Run();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Node114F88::~Node114F88()
{
}
