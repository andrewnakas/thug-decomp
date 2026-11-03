struct Data_0011F930 {
    int d[0x44A0 / 4];
};

struct Sub_0011F930 {
    int m0;
};

extern void* D_00388A70;
extern "C" void func_001E6A00(Sub_0011F930* d, Sub_0011F930* s);
extern "C" void func_0010A8D8(void* heap, void* p);

struct C_0011F930 {
    char pad[0x48];
    Sub_0011F930 m48;
    int m4C;
    Data_0011F930* m50;
    int m54;
    C_0011F930& operator=(C_0011F930& o);
};

extern "C" void func_001200E8(C_0011F930* self);

C_0011F930& C_0011F930::operator=(C_0011F930& o)
{
    if (&o == this)
        return *this;
    func_001E6A00(&m48, &o.m48);
    if (m50) {
        func_0010A8D8(D_00388A70, m50);
        m50 = 0;
    }
    if (o.m50) {
        func_001200E8(this);
        *m50 = *o.m50;
    }
    m54 = o.m54;
    return *this;
}
