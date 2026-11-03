extern int D_00388A70;
extern "C" void func_0010A8D8(int pool, void* p);

struct HashTable_0018ADD0 {
    int m0;
    void* m4;
    ~HashTable_0018ADD0();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

extern "C" void func_0018AD18(HashTable_0018ADD0* self);

HashTable_0018ADD0::~HashTable_0018ADD0()
{
    if (m4) {
        func_0018AD18(this);
        if (m4) {
            func_0010A8D8(D_00388A70, m4);
        }
        m4 = 0;
    }
}
