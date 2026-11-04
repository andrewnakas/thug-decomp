extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

struct Owner_002683E8 {
    void Clear();
    ~Owner_002683E8();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Owner_002683E8::~Owner_002683E8()
{
    Clear();
}
