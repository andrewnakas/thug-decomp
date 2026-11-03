extern char D_00373678[];
extern char D_00373690[];
extern char D_0038FE78[];
extern char D_003736A0[];
extern char D_003736B0[];
extern char D_003736C8[];
extern char D_003736E0[];

struct Vec_00238920 {
    float x;
    float y;
    float z;
};

struct Array_00238920 {
    int m0;
    int m4;
    int m8;
    int m_size;
};

struct Score_00238920 {
    char m_pad[0x88];
    int m_numArrows;
    Vec_00238920 m_arrows[20];
    float m_arrowStep;
    char m_pad180[0x190 - 0x180];
    Vec_00238920 m_bars[2];
};

extern void* D_0038FC78;

extern "C" void* func_001E5588(const char* name, int a);
extern "C" bool func_001E82B8(void* params, const char* name, Array_00238920** out, int assert_);
extern "C" Vec_00238920* func_001E9350(Array_00238920* self, int index);
extern "C" bool func_00215EE0(int a, int b);
extern "C" void* func_0022E358(void* self);
extern "C" unsigned int func_0024F938(void* self);
extern "C" unsigned int func_001F0D78(const char* name);
extern "C" int func_0013B0E0();

void func_00238920(Score_00238920* self)
{
    void* mgr = D_0038FC78;
    void* info = func_001E5588(D_00373678, 0);
    Array_00238920* arrows = 0;
    func_001E82B8(info, D_00373690, &arrows, 0);
    self->m_numArrows = arrows->m_size;
    for (int i = 0; i < self->m_numArrows; i++) {
        self->m_arrows[i] = *func_001E9350(arrows, i);
    }
    self->m_arrows[self->m_numArrows] = self->m_arrows[self->m_numArrows - 1];
    Array_00238920* bars = 0;
    self->m_arrowStep = 1.0f / (float)self->m_numArrows;
    if (func_00215EE0(0, 0) && func_0024F938(func_0022E358(mgr)) != func_001F0D78(D_0038FE78) && func_0024F938(func_0022E358(mgr)) != func_001F0D78(D_003736A0)) {
        if (func_0013B0E0() == 1) {
            func_001E82B8(info, D_003736B0, &bars, 0);
        } else {
            func_001E82B8(info, D_003736C8, &bars, 0);
        }
    } else {
        func_001E82B8(info, D_003736E0, &bars, 0);
    }
    for (int i = 0; i < 2; i++) {
        self->m_bars[i] = *func_001E9350(bars, i);
    }
}
