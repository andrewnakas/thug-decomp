extern int D_00388A70;
extern "C" void func_0010A8D8(int pool, void* p);

struct HashTable_001D0D70 {
    int m0;
    void* m4;
    ~HashTable_001D0D70();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

extern "C" void func_001D0CB8(HashTable_001D0D70* self);

HashTable_001D0D70::~HashTable_001D0D70()
{
    if (m4) {
        func_001D0CB8(this);
        if (m4) {
            func_0010A8D8(D_00388A70, m4);
        }
        m4 = 0;
    }
}
