extern void* D_0038FC78;
extern char D_00366228[];
extern char D_00366240[];
extern char D_00366250[];
extern char D_00366260[];
extern char D_00366270[];
extern char D_00366280[];
extern char D_00366298[];
extern char D_003662B0[];
extern char D_003662C8[];
extern char D_0038E920[];
extern char D_0038E938[];
extern char D_0038E940[];
extern char D_0038E948[];
extern char D_0038E950[];
extern char D_0038E958[];
extern char D_0038E960[];
extern char D_0038E968[];
extern "C" void* func_0022E358(void*);
extern "C" int func_0024F908(void*, unsigned int);
extern "C" void* func_001190D0(unsigned int);
extern "C" void* func_001E6978(void*);
extern "C" void* func_0022E3C8(void*, int);
extern "C" void* func_001F0D78(const char*);
extern "C" void func_001F0210(void*, void*, int, int, int);
extern "C" void func_001E7138(void*, const char*, const char*);
extern "C" void func_001E7268(void*, const char*, int);
extern "C" int func_00261E18(void*, unsigned int);
extern "C" void func_00261E40(void*, unsigned int, int);
extern "C" void func_00103F28(const char*, ...);
extern "C" void func_00205290(int, void*);
extern "C" void* func_00240850();
extern "C" int func_0023D158(void*);
extern "C" void func_001E6AE8(void*, int);

struct Entry_001F4A90 {
    int f0;
    unsigned int f1;
    int f2;
    int f3;
    int f4;
    int f5;
    int f6;
    int f7;
    int f8;
};

struct Obj_001F4A90 {
    char pad0[0x20];
    Entry_001F4A90 m_entries[70];
    char pad[0x9F8 - 0x20 - 70 * 0x24];
    int m9F8;
    int m9FC;
    int mA00;
    int padA04[36];
    int mA94;
    int mA98;
    int mA9C;
    int mAA0;
    void Update();
};

void Obj_001F4A90::Update()
{
    if (!func_0024F908(func_0022E358(D_0038FC78), 0x1DED1EA4))
        return;
    if (!m9F8)
        return;
    int sent = 0;
    void* s = func_001E6978(func_001190D0(8));
    void* t = func_0022E3C8(D_0038FC78, 0);
    for (int i = 0; i < 70; i++) {
        if (m_entries[i].f4)
            continue;
        if (!m_entries[i].f3)
            continue;
        if (!sent) {
            sent = 1;
            func_001F0210(func_001F0D78(D_00366228), 0, 0, 0, 0);
        }
        m_entries[i].f4 = 1;
        unsigned int id = m_entries[i].f1;
        switch (id) {
        case 0xB1FC0722:
            func_001E7138(s, D_0038E920, D_00366240);
            break;
        case 0xF73A13E3:
            func_001E7138(s, D_0038E920, D_0038E938);
            break;
        case 0xAE798769:
            func_001E7138(s, D_0038E920, D_0038E940);
            break;
        case 0xF0D90109:
            func_001E7138(s, D_0038E920, D_00366250);
            break;
        case 0x9B65D7B8:
            func_001E7138(s, D_0038E920, D_00366260);
            break;
        case 0x439F4704:
            func_001E7138(s, D_0038E920, D_0038E948);
            break;
        case 0x6DCB497C:
            func_001E7138(s, D_0038E920, D_0038E950);
            break;
        case 0x9016B4E7:
            func_001E7138(s, D_0038E920, D_00366270);
            break;
        case 0xEDF5DB70:
            func_001E7138(s, D_0038E920, D_0038E958);
            break;
        case 0xAF895B3F:
            func_001E7138(s, D_0038E920, D_0038E960);
            break;
        }
        func_001E7268(s, D_0038E968, 1);
        func_001F0210(func_001F0D78(D_00366280), s, 0, 0, 0);
        if (m9FC)
            func_00261E40(t, id, func_00261E18(t, id) + 1);
    }
    if (sent) {
        func_00103F28(D_00366298);
        func_00205290(mAA0, t);
        if (!mA00 && func_0023D158(func_00240850())) {
            func_001F0210(func_001F0D78(D_003662B0), 0, 0, 0, 0);
            mA00 = 1;
        }
        func_001F0210(func_001F0D78(D_003662C8), 0, 0, 0, 0);
    }
    if (s)
        func_001E6AE8(s, 3);
    mA94 = 0;
    mA98 = 0;
}
