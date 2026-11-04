struct B170_00167600 {
    char m_data[0x170];
};

struct B0C0_00167600 {
    char m_data[0xC0];
};

extern int D_0039427C;
extern char* D_00394274;
extern "C" void func_001617A0(int a);
extern "C" void func_00167068(char* p);

class C_00167600 {
public:
    char m_pad0[0x50];
    int m_flags;
    char* Emit();
};

char* C_00167600::Emit()
{
    if (D_0039427C) {
        func_001617A0(0);
    }
    char* p = D_00394274;
    if (m_flags & 1) {
        *(B170_00167600*)p = *(B170_00167600*)this;
    } else {
        *(B0C0_00167600*)p = *(B0C0_00167600*)this;
        func_00167068(p);
    }
    D_00394274 += 0x170;
    return p;
}
