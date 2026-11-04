extern "C" void func_001E7200(void* p, unsigned int key, int v);
extern "C" void func_001E72B0(void* p, unsigned int key, float v);

struct Obj_002940A0;
extern "C" void func_00293B68(Obj_002940A0*, void*);
extern "C" void func_00293E08(Obj_002940A0*, void*);

struct Obj_002940A0 {
    char pad0[0x2B8];
    int m2B8;
    float m2BC;
    int m2C0;
    int m2C4;
    int m2C8;
    int m2CC;
    void Write(void* s, int mode);
};

void Obj_002940A0::Write(void* s, int mode)
{
    func_001E7200(s, 0x01181B29, m2B8);
    func_001E72B0(s, 0x076F65C8, m2BC);
    func_001E7200(s, 0xDED8540A, m2C0);
    func_001E7200(s, 0xA6D96603, m2C4);
    func_001E7200(s, 0x89473DB7, m2C8);
    if (mode == 1) {
        func_00293B68(this, s);
    } else {
        func_001E7200(s, 0xEDF5DB70, m2CC);
        func_00293E08(this, s);
    }
}
