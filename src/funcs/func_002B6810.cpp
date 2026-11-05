struct Node_002B6810;
struct Obj_002B6810;

struct Node_002B6810 {
    char pad0[0x18];
    Obj_002B6810* m18;
};

extern "C" void func_002B6B20(void* p);
extern "C" void* func_002B6B48(int size);
extern "C" Node_002B6810* func_002B6250(void* p);
extern "C" void func_002B6B98();

struct Obj_002B6810 {
    char pad0[0x14];
    void* m14;
    Node_002B6810* Make();
};

Node_002B6810* Obj_002B6810::Make()
{
    func_002B6B20(m14);
    Node_002B6810* n = func_002B6250(func_002B6B48(0x1C));
    func_002B6B98();
    n->m18 = this;
    return n;
}
