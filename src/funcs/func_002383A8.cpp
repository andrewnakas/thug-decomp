struct Color_002383A8 {
    unsigned char r, g, b, a;
};

struct Bar_002383A8 {
    char m_pad[0x70];
    Color_002383A8 m_colors[3];
    char m_pad7C[0x80 - 0x7C];
    float m_rate;
};

extern char D_003735C8[];
extern char D_003735E0[];

extern "C" void* func_001E55F8(const char* name, int required);
extern "C" void* func_001E93A0(void* array, int index);
extern "C" int func_001E9270(void* array, int index);
extern "C" float func_001E5370(const char* name, int required);

void func_002383A8(Bar_002383A8* self)
{
    void* colors = func_001E55F8(D_003735C8, 1);
    for (int i = 0; i < 3; i++) {
        void* color = func_001E93A0(colors, i);
        self->m_colors[i].r = func_001E9270(color, 0);
        self->m_colors[i].g = func_001E9270(color, 1);
        self->m_colors[i].b = func_001E9270(color, 2);
        self->m_colors[i].a = func_001E9270(color, 3);
    }
    self->m_rate = func_001E5370(D_003735E0, 1);
}
