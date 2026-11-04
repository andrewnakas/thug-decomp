extern int D_00388A70;
extern "C" void func_0010A8D8(int pool, void* p);

struct HashTable_001D0D70 {
    int m0;
    ~HashTable_001D0D70();
};

struct Registry_001CFF40 {
    int m0;
    int m4;
    int m8;
    HashTable_001D0D70* mC;
    ~Registry_001CFF40();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

extern "C" void func_001D0A08(Registry_001CFF40* self, int all);

Registry_001CFF40::~Registry_001CFF40()
{
    func_001D0A08(this, 1);
    delete mC;
}
