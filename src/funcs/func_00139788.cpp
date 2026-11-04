extern int D_00388A70;
extern "C" void func_0010A8D8(int pool, void* p);

struct HashTable_00139788 {
    int m0;
    void* m4;
    ~HashTable_00139788();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

extern "C" void func_001396D0(HashTable_00139788* self);

HashTable_00139788::~HashTable_00139788()
{
    if (m4) {
        func_001396D0(this);
        if (m4) {
            func_0010A8D8(D_00388A70, m4);
        }
        m4 = 0;
    }
}
