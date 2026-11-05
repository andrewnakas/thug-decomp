extern "C" void* func_00292108(unsigned int v);
extern "C" int func_001E7DE8(void* p, unsigned int key, int* out, int req);
extern "C" int func_001E7C80(void* p, unsigned int key, char** out, int req);
extern "C" char* func_00331A9C(char* d, const char* s);
extern char D_00391E10[];

struct Slot_00294C80 {
    int m0;
    char pad[0x1C];
    float m20;
    char pad2[0xC];
};

struct Obj_00294C80 {
    char pad0[0x4];
    char m4[0x110];
    unsigned int m114;
    char pad1[0x8];
    Slot_00294C80 m120[8];
    unsigned char m2A0;
    char pad2[0xB];
    int m2AC;
    char pad3[0x4];
    int m2B4;
    void Init(unsigned int type);
};

void Obj_00294C80::Init(unsigned int type)
{
    m120[0].m0 = 1;
    m120[0].m20 = 0.0f;
    m120[1].m0 = 2;
    m120[1].m20 = 0.0f;
    m114 = type;
    void* s = func_00292108(type);
    switch (m114) {
    case 0x54166ACD:
        m2A0 = 7;
        for (int i = 2; i < 8; i++) {
            (m120 + i)->m0 = 3;
            (m120 + i)->m20 = 0.0f;
        }
        break;
    case 0x4EC3CFB5:
        m2A0 = 7;
        for (int i = 2; i < 8; i++) {
            (m120 + i)->m0 = 3;
            (m120 + i)->m20 = 0.0f;
        }
        break;
    case 0x61C5D092:
    case 0x7FE2238A:
    case 0x0FC6F698:
    case 0x6FE44C6D:
    case 0xEA7BA666:
    case 0xEC414B76:
        m2A0 = 2;
        break;
    }
    if (s) {
        func_001E7DE8(s, 0xC51BF6E3, &m2AC, 0);
        func_001E7DE8(s, 0xCD66C8AE, &m2B4, 0);
        char* str = D_00391E10;
        func_001E7C80(s, 0x4BC5229D, &str, 0);
        func_00331A9C(m4, str);
    }
}
