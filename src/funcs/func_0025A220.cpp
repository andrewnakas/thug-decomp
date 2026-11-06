/* sym: __13Elem_0025A220 = 0x00259C98 */
struct Heap_0025A220 {
    char pad[0xDC];
    void* mDC;
};

extern Heap_0025A220* D_00388A70;

extern "C" void func_0010A950(Heap_0025A220* heap, void* ctx);
extern "C" void* func_0010A638(Heap_0025A220* heap, unsigned int size, int a, int b);
extern "C" void func_0010A9B0(Heap_0025A220* heap);

struct Elem_0025A220 {
    char m_data[0x258];
    Elem_0025A220();
    ~Elem_0025A220();
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct Owner_0025A220 {
    Elem_0025A220* m_elems;
    void Alloc();
};

void Owner_0025A220::Alloc()
{
    func_0010A950(D_00388A70, D_00388A70->mDC);
    m_elems = new Elem_0025A220[300];
    func_0010A9B0(D_00388A70);
}
