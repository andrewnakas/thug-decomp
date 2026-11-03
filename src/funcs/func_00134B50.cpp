extern int D_00388A70;
extern "C" void func_0010A8D8(int pool, void* p);

struct HashTable_00134B50 {
    int m0;
    void* m4;
    ~HashTable_00134B50();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

extern "C" void func_00134A98(HashTable_00134B50* self);

HashTable_00134B50::~HashTable_00134B50()
{
    if (m4) {
        func_00134A98(this);
        if (m4) {
            func_0010A8D8(D_00388A70, m4);
        }
        m4 = 0;
    }
}
