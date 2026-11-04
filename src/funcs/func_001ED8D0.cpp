struct Comp_001ED8D0 {
    char pad0[2];
    unsigned char m_type;
    char pad3[9];
    void* m_data;
};

extern "C" void func_001E4E58(void* p);
extern "C" void func_001E8AC0(void* p);
extern "C" void func_001E8B70(void* p);
extern "C" void func_0010BEB8(void* p);
extern "C" void func_001E6AE8(void* p, int in_chrg);
extern "C" void func_001E6518(void* p);
extern "C" void func_001E8DE8(void* p, int in_chrg);
extern "C" void func_001E50C0(Comp_001ED8D0* c);

void func_001ED8D0(Comp_001ED8D0* c)
{
    switch (c->m_type) {
    case 1:
    case 2:
        break;
    case 3:
    case 4:
        func_001E4E58(c->m_data);
        break;
    case 5:
        func_001E8AC0(c->m_data);
        break;
    case 6:
        func_001E8B70(c->m_data);
        break;
    case 7:
        func_0010BEB8(c->m_data);
        break;
    case 8:
    case 9:
        break;
    case 10:
        if (c->m_data) func_001E6AE8(c->m_data, 3);
        break;
    case 11:
        break;
    case 12:
        func_001E6518(c->m_data);
        if (c->m_data) func_001E8DE8(c->m_data, 3);
        break;
    case 13:
        break;
    }
    c->m_data = 0;
    func_001E50C0(c);
}
