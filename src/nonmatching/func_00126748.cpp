/* fuzzy: 93.8 */
struct Color_00126748 {
    unsigned char r, g, b, a;
    Color_00126748(const Color_00126748& o) { *this = o; }
};

struct Sprite_00126748;

struct Glyph_00126748 {
    float m0;
    char pad4[0x1C];
    float m20;
    float m24;
    char pad28[0xC];
    float m34;
    float m38;
};

struct Font_00126748 {
    char pad[0x538];
    Color_00126748 m538;
};

struct Placement_00126748 {
    float m0;
    char pad4[0x24];
    int m28;
    float m2C;
    float m30;
    float m34;
    float m38;
};

struct Obj_00126748 {
    char pad0[0xC];
    unsigned int mC;
    char pad10[0xB8];
    Color_00126748 mC8;
    char padCC[0x64];
    Placement_00126748 m130;
    char pad16C[0x1C];
    float m188;
    float m18C;
    char pad190[4];
    float m194;
    char pad198[8];
    int m1A0;
    char pad1A4[4];
    int m1A8;
    Sprite_00126748** m1AC;
    Sprite_00126748** m1B0;
    int m1B4;
    Font_00126748* m1B8;
    int m1BC;
    float m1C0;
    float m1C4;
    Color_00126748 m1C8;
    int m1CC;
};

extern "C" void func_00135AC8(Sprite_00126748* s, int v);
extern "C" void func_00135BB0(Sprite_00126748* s, float x, float y);
extern "C" void func_00135C78(Sprite_00126748* s, Color_00126748 c, int v);
extern "C" void func_00135BE0(Sprite_00126748* s, float x, float y);
extern "C" void func_00135AF8(Sprite_00126748* s, int v);
extern "C" void func_00135C40(Sprite_00126748* s, int v);
extern "C" void func_00135C10(Sprite_00126748* s, float z);
extern "C" void func_00135A98(Sprite_00126748* s, int v);
extern "C" int func_00125E10(Obj_00126748* self);
extern "C" void func_00130510(Font_00126748* f);
extern "C" Glyph_00126748* func_00130720(Font_00126748* f, int i);

static inline Placement_00126748* Place_00126748(Obj_00126748* o)
{
    return &o->m130;
}

extern "C" void func_00126748(Obj_00126748* self)
{
    if (!self->m1A0)
        return;
    float y0 = Place_00126748(self)->m30;
    Placement_00126748* p = Place_00126748(self);
    int offscreen = 0;
    if (y0 < -200.0f || y0 > 648.0f)
        offscreen = 1;
    if (self->m1B4) {
        Color_00126748 c = self->mC8;
        if (self->m130.m0 >= 0.0001f) {
            Color_00126748 t = self->mC8;
            c.a = t.a * self->m130.m0;
        } else {
            c.a = 0;
        }
        func_00135AC8(self->m1AC[0], self->m1A8);
        func_00135BB0(self->m1AC[0], p->m2C, p->m30);
        func_00135C78(self->m1AC[0], c, self->m1CC);
        func_00135BE0(self->m1AC[0], p->m34, p->m38);
        func_00135AF8(self->m1AC[0], self->m1A0);
        if (self->mC & 0x80000) {
            func_00135C40(self->m1AC[0], p->m28);
            func_00135A98(self->m1AC[0], (self->mC & 0x100000) || func_00125E10(self));
        } else {
            func_00135C10(self->m1AC[0], self->m194);
            func_00135A98(self->m1AC[0], offscreen || func_00125E10(self));
        }
        if (self->m1BC) {
            Color_00126748 c2 = self->m1C8;
            if (self->m130.m0 >= 0.0001f)
                c2.a = self->m1C8.a * self->m130.m0;
            else
                c2.a = 0;
            func_00135AC8(self->m1B0[0], self->m1A8);
            func_00135BB0(self->m1B0[0], p->m2C + self->m1C0, p->m30 + self->m1C4);
            func_00135C78(self->m1B0[0], c2, self->m1CC);
            func_00135BE0(self->m1B0[0], p->m34, p->m38);
            func_00135AF8(self->m1B0[0], self->m1A0);
            if (self->mC & 0x80000) {
                func_00135C40(self->m1B0[0], p->m28);
                func_00135A98(self->m1B0[0], (self->mC & 0x100000) || func_00125E10(self));
            } else {
                func_00135C10(self->m1B0[0], self->m194 - 0.005f);
                func_00135A98(self->m1B0[0], offscreen || func_00125E10(self));
            }
        }
    }
    if (!self->m1B8)
        return;
    func_00130510(self->m1B8);
    float cx = p->m2C + p->m34 * self->m188 * 0.5f;
    float cy = p->m30 + p->m38 * self->m18C * 0.5f;
    for (int i = 1; i < self->m1B4; i++) {
        Glyph_00126748* g = func_00130720(self->m1B8, i - 1);
        Color_00126748 c = self->m1B8->m538;
        c.a = c.a * g->m0;
        float sx, sy, x, y;
        sx = Place_00126748(self)->m34 * g->m34;
        sy = Place_00126748(self)->m38 * g->m38;
        y = cy - (g->m24 + self->m18C * g->m38 * 0.5f) * Place_00126748(self)->m38;
        x = cx - (g->m20 + self->m188 * g->m34 * 0.5f) * Place_00126748(self)->m34;
        func_00135BB0(self->m1AC[i], x, y);
        func_00135C78(self->m1AC[i], c, self->m1CC);
        func_00135BE0(self->m1AC[i], sx, sy);
        func_00135C10(self->m1AC[i], self->m194 - i * 0.01f);
        func_00135AC8(self->m1AC[i], self->m1A8);
        func_00135AF8(self->m1AC[i], self->m1A0);
        func_00135A98(self->m1AC[i], offscreen || func_00125E10(self));
        if (self->m1BC) {
            Color_00126748 c2 = self->m1C8;
            if (Place_00126748(self)->m0 >= 0.0001f)
                c2.a = self->m1C8.a * Place_00126748(self)->m0;
            else
                c2.a = 0;
            func_00135BB0(self->m1B0[i], x + self->m1C0 * sx, y + self->m1C4 * sy);
            func_00135C78(self->m1B0[i], c2, self->m1CC);
            func_00135BE0(self->m1B0[i], sx, sy);
            func_00135C10(self->m1B0[i], self->m194 - i * 0.01f - 0.005f);
            func_00135AC8(self->m1B0[i], self->m1A8);
            func_00135AF8(self->m1B0[i], self->m1A0);
            func_00135A98(self->m1B0[i], offscreen || func_00125E10(self));
        }
    }
}
