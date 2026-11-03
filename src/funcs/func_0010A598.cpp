extern "C" void func_0031BCB0(int);
extern "C" void func_0010A8D8(void*, void*);
extern int D_00393EB0;
extern void* D_00388A70;

class Heap_0010A598 {
public:
    char pad[0x80];
    virtual void V1();
    virtual void V2();
    virtual ~Heap_0010A598();
};

class Region_0010A598 {
public:
    char pad[0x18];
    virtual ~Region_0010A598();
};

struct Mem_0010A598 {
    char pad[0xD4];
    Region_0010A598* m_region;
    Heap_0010A598* m_main;
    Heap_0010A598* m_top;
    ~Mem_0010A598();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Mem_0010A598::~Mem_0010A598()
{
    m_main->~Heap_0010A598();
    m_top->~Heap_0010A598();
    m_region->~Region_0010A598();
    func_0031BCB0(D_00393EB0);
}
