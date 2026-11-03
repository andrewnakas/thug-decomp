extern int D_00388A70;
extern "C" void func_0010A8D8(int pool, void* p);

struct HashTable_00266848 {
    int m0;
    void* m4;
    ~HashTable_00266848();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

extern "C" void func_00266790(HashTable_00266848* self);

HashTable_00266848::~HashTable_00266848()
{
    if (m4) {
        func_00266790(this);
        if (m4) {
            func_0010A8D8(D_00388A70, m4);
        }
        m4 = 0;
    }
}
