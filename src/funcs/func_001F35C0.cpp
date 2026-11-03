extern int D_00388A70;
extern "C" void func_0010A8D8(int pool, void* p);

struct HashTable_001F35C0 {
    int m0;
    void* m4;
    ~HashTable_001F35C0();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

extern "C" void func_001F3508(HashTable_001F35C0* self);

HashTable_001F35C0::~HashTable_001F35C0()
{
    if (m4) {
        func_001F3508(this);
        if (m4) {
            func_0010A8D8(D_00388A70, m4);
        }
        m4 = 0;
    }
}
