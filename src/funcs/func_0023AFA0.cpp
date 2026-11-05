extern void* D_00388A70;
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" void func_0010BEB8(void* p);

struct Array_0023AFA0 {
    int m0;
    int* m_data;
    ~Array_0023AFA0();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Array_0023AFA0::~Array_0023AFA0()
{
    func_0010BEB8(m_data);
}
