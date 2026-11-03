extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

struct Owner_0026B4E0 {
    void Clear();
    ~Owner_0026B4E0();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Owner_0026B4E0::~Owner_0026B4E0()
{
    Clear();
}
