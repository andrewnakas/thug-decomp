struct Slot_001DFDD0 {
    char m_text[0x28];
};

struct Lobby_001DFDD0 {
    Slot_001DFDD0 m_slots[80];
    int m_count;
    char m_padC84[0xCB0 - 0xC84];
};

extern int D_0038E130;
extern float D_0038E134;
extern int D_0038E150;
extern int D_0038881C;
extern void* D_0038E0A0;
extern void* D_0038FC78;
extern char D_003F21F8[];
extern Lobby_001DFDD0 D_003F0898[];

extern "C" int func_001DED20();
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" float func_001DD618(void* p);
extern "C" void* func_0022E358(void* game);
extern "C" int func_0024F860(void* mode);
extern "C" void func_001E04A0(int a);
extern "C" int func_001DF118(const char* text, float time);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void func_001E0CA8(int index, int a, int lobby);

void func_001DFDD0(const char* text, int arg)
{
    if (func_001DED20() || D_0038E150) {
        return;
    }
    func_00331A9C(D_003F21F8, text);
    int which = D_0038E130;
    float time;
    if (!which) {
        time = D_0038E134;
    } else {
        time = func_001DD618(D_0038E0A0);
    }
    if (func_0024F860(func_0022E358(D_0038FC78))) {
        time = D_0038E134;
        which = 1;
    }
    func_001E04A0(arg);
    if (func_001DF118(D_003F21F8, time)) {
        return;
    }
    if (D_0038881C) {
        return;
    }
    Lobby_001DFDD0* lobby = &D_003F0898[which];
    for (int i = 0; i < lobby->m_count; i++) {
        if (func_001F0D78(text) == func_001F0D78(lobby->m_slots[i].m_text)) {
            func_001E0CA8(i, 1, which);
            return;
        }
    }
}
