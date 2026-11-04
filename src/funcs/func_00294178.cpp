extern "C" int func_001E7DE8(void* p, unsigned int key, int* out, int req);
extern "C" int func_001E7EB0(void* p, unsigned int key, float* out, int req);

struct Obj_00294178;
extern "C" void func_00293F50(Obj_00294178*, void*);

struct Obj_00294178 {
    char pad0[0x2B8];
    int m2B8;
    float m2BC;
    int m2C0;
    int m2C4;
    int m2C8;
    int m2CC;
    void Read(void* s);
};

void Obj_00294178::Read(void* s)
{
    func_001E7DE8(s, 0x01181B29, &m2B8, 0);
    func_001E7EB0(s, 0x076F65C8, &m2BC, 0);
    func_001E7DE8(s, 0xDED8540A, &m2C0, 0);
    func_001E7DE8(s, 0xA6D96603, &m2C4, 0);
    func_001E7DE8(s, 0x89473DB7, &m2C8, 0);
    func_001E7DE8(s, 0xEDF5DB70, &m2CC, 0);
    func_00293F50(this, s);
}
