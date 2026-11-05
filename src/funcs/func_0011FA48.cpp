extern "C" void func_001E6B30(void* sub);
extern "C" void func_00123428(void* p, int a);
extern "C" void* func_001E5548(unsigned int id, int a);
extern "C" void func_001E6AC8(void* sub, void* obj);

struct Obj_0011FA48 {
    char pad[0x48];
    int m48[2];
    void* m50;
    int m54;
    int Reset();
};

int Obj_0011FA48::Reset()
{
    func_001E6B30(m48);
    if (m50) {
        func_00123428(m50, 0);
    }
    void* obj = func_001E5548(0xFE54486D, 0);
    if (obj) {
        func_001E6AC8(m48, obj);
    }
    m54 = 0;
    return 1;
}
