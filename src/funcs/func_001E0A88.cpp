struct Stream_001E0A88 {
    char m_pad[0x1C];
    int m_done[3];
};

struct Chan_001E0A88 {
    char m_pad0[0x10];
    int m_voice;
    char m_pad14[0x10];
    void* m_sound;
};

extern Stream_001E0A88* D_003F2220[3];
extern Chan_001E0A88 D_003EE8E0[3];
extern int D_0038E144;
extern float D_0038E134;
extern int D_0038E130;
extern int D_0038E160;
extern int D_0038E13C;

extern "C" bool func_001DED20();
extern "C" bool func_001DED40();
extern "C" int func_001E3370();
extern "C" void func_001DEF18(int a);
extern "C" void func_001DEEE0();
extern "C" bool func_001DFA78(int i);
extern "C" int func_001E3C58(int voice);
extern "C" void func_001E1428(void* sound);
extern "C" void func_001E04D8();
extern "C" void func_001E0880();

void Audio_001E0A88_Update()
{
    if (func_001DED20() && func_001DED40()) {
        return;
    }
    int r = func_001E3370();
    if (r) {
        if (r < 0) {
            func_001DEF18(-1);
            func_001DEEE0();
        } else {
            func_001DEF18(-1);
        }
    }
    D_0038E144++;
    for (int i = 0; i < 3; i++) {
        if (D_003F2220[i]) {
            if (!func_001DFA78(i)) {
                D_003F2220[i]->m_done[i] = 0;
                D_003F2220[i] = 0;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        if (D_003EE8E0[i].m_sound) {
            if (func_001E3C58(D_003EE8E0[i].m_voice) == 1) {
                func_001E1428(D_003EE8E0[i].m_sound);
                D_003EE8E0[i].m_sound = 0;
            }
        }
    }
    if (D_0038E144 & 0x3F) {
        return;
    }
    if (D_0038E134 == 0.0f && D_0038E130 != 1) {
        return;
    }
    if (D_0038E160) {
        return;
    }
    if (D_0038E13C || D_0038E130 == 1) {
        func_001E04D8();
    } else {
        func_001E0880();
    }
}
