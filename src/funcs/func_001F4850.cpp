struct Obj_001F4850;
struct Entry_001F4850 {
    unsigned int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    char pad[0x24 - 0x14];
};
extern void* D_0038FC78;
extern char D_003661D0[];
extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F908(void* p, unsigned int name);
extern "C" void func_001F4EA8(Obj_001F4850* self, int i);
extern "C" void* func_001F0D78(char* name);
extern "C" void func_001F0210(void* p, int a, int b, int c, int d);

struct Obj_001F4850 {
    char pad[0x20];
    Entry_001F4850 m20[70];
    char pad2[0x9F8 - 0x20 - 70 * 0x24];
    int m9F8;
    void Run(unsigned int name, float t);
};

void Obj_001F4850::Run(unsigned int name, float t)
{
    if (!func_0024F908(func_0022E358(D_0038FC78), 0x1DED1EA4)) return;
    if (!m9F8) return;
    bool any = false;
    for (int i = 0; i < 70; i++) {
        if (m20[i].m10) continue;
        if (m20[i].mC) continue;
        int v = m20[i].m8;
        switch (name) {
        case 0x0AC90769:
        case 0xEF24413B:
            if (m20[i].m0 == 0xD9FFC141 && (float)v <= t) {
                func_001F4EA8(this, i);
                any = true;
            }
            break;
        case 0x8D10119D:
        case 0x255ED86F:
            if (m20[i].m0 == 0xC1336019 && (float)v <= t) {
                func_001F4EA8(this, i);
                any = true;
            }
            break;
        case 0xA549B57B:
            if (m20[i].m0 == 0xB67CFF14 && (float)v <= t) {
                func_001F4EA8(this, i);
                any = true;
            }
            break;
        }
    }
    if (any) {
        func_001F0210(func_001F0D78(D_003661D0), 0, 0, 0, 0);
    }
}
