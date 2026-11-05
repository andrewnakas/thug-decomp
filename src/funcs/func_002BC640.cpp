extern void* D_00388A70;
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void func_002BC5A8(void* p);

struct List_002BC640 {
    void* m0;
    ~List_002BC640();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

List_002BC640::~List_002BC640()
{
    if (m0)
        func_002BC5A8(m0);
}
