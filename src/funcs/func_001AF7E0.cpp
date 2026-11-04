extern "C" int func_00103F28(const char* fmt, ...);
extern char D_003629B8[];
extern char D_003629C8[];
extern char D_0038CF88[];
extern char D_0038CF90[];
extern char D_0038CF98[];
extern char D_0038CFA0[];
extern char D_0038CFA8[];
extern char D_0038CFB0[];
extern char D_0038CFB8[];
extern char D_003629E8[];
extern char D_003629F8[];
extern char D_0038CFC0[];
extern char D_0038CFC8[];
extern char D_0038CFD0[];
extern char D_00362A08[];
extern char D_0038CFD8[];
extern char D_0038CFE0[];
extern char D_0038CFE8[];
extern char D_0038CFF0[];
extern char D_0038CFF8[];
extern char D_0038D000[];
extern char D_0038D008[];
extern char D_0038D010[];
extern char D_0038D018[];
extern char D_00362A18[];
extern char D_0038D020[];

struct Entry_001AF7E0 {
    int m_name;
    int m_state;
    unsigned int m_type;
    int mC;
    int m10;
    int m_time;
};

struct C_001AF7E0 {
    char pad0[0x3C];
    Entry_001AF7E0 m_log[100];
    unsigned short m_count;
    unsigned short m_head;
    void Dump();
};

void C_001AF7E0::Dump()
{
    func_00103F28(D_003629B8);
    int n = m_count;
    if (n > 10)
        n = 10;
    int idx = m_head;
    for (int i = 0; i < n; i++) {
        func_00103F28(D_003629C8, m_log[idx].m_name, m_log[idx].m_time);
        switch (m_log[idx].m_type) {
        case 0:
            func_00103F28(D_0038CF88);
            break;
        case 0xBC6B118F:
            func_00103F28(D_0038CF90);
            break;
        case 0xE3006FC4:
            func_00103F28(D_0038CF98);
            break;
        case 0x85981897:
            func_00103F28(D_0038CFA0);
            break;
        case 0x4B358AEB:
            func_00103F28(D_0038CFA8);
            break;
        case 0xB7231A95:
            func_00103F28(D_0038CFB0);
            break;
        case 0xA50950C5:
            func_00103F28(D_0038CFB8);
            break;
        case 0xD8847EFA:
            func_00103F28(D_003629E8);
            break;
        case 0x786B8B68:
            func_00103F28(D_003629F8);
            break;
        case 0x2B489A86:
            func_00103F28(D_0038CFC0);
            break;
        case 0x321C9756:
            func_00103F28(D_0038CFC8);
            break;
        case 0x7323E97C:
            func_00103F28(D_0038CFD0);
            break;
        case 0x20689278:
            func_00103F28(D_00362A08);
            break;
        case 0x26B0C991:
            func_00103F28(D_0038CFD8);
            break;
        case 0xBFB9982B:
            func_00103F28(D_0038CFE0);
            break;
        case 0xF2F1F64E:
            func_00103F28(D_0038CFE8);
            break;
        case 0x6BF8A7F4:
            func_00103F28(D_0038CFF0);
            break;
        case 0x767A45D7:
            func_00103F28(D_0038CFF8);
            break;
        case 0xBD30325B:
            func_00103F28(D_0038D000);
            break;
        }
        func_00103F28(D_0038D008);
        switch (m_log[idx].m_state) {
        case 0:
            func_00103F28(D_0038D010);
            break;
        case 1:
            func_00103F28(D_0038D018);
            break;
        case 2:
            func_00103F28(D_00362A18);
            break;
        }
        func_00103F28(D_0038D020);
        idx--;
        if (idx < 0)
            idx += 100;
    }
}
