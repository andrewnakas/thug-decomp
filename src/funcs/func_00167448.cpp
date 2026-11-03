struct B170_00167448 {
    char m_data[0x170];
};

struct B0C0_00167448 {
    char m_data[0xC0];
};

extern int D_0039427C;
extern char* D_00394274;
extern "C" void func_001617A0(int a);

class C_00167448 {
public:
    char m_pad0[0x50];
    int m_flags;
    char* Emit();
};

char* C_00167448::Emit()
{
    if (D_0039427C) {
        func_001617A0(0);
    }
    char* p = D_00394274;
    if (m_flags & 1) {
        *(B170_00167448*)p = *(B170_00167448*)this;
        D_00394274 += 0x170;
    } else {
        *(B0C0_00167448*)p = *(B0C0_00167448*)this;
        D_00394274 += 0xC0;
    }
    return p;
}
