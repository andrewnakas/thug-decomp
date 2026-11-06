/* Static-init (priority 0xFFFF) of the render-state globals: the current state D_003BEB00 is cleared and given
   its defaults, the 4-deep state stack D_003BEB50 and a 0x100-entry table get their (empty) element constructors,
   and the 0x96 entries at D_003C1C90 are constructed with func_00136D98. */
struct Rgba_00137848 {
    unsigned char r, g, b, a;
    Rgba_00137848() {}
    void Set(unsigned char nr, unsigned char ng, unsigned char nb, unsigned char na)
    {
        r = nr;
        g = ng;
        b = nb;
        a = na;
    }
};

struct Vec_00137848 {
    float x, y, z, w;
    Vec_00137848() {}
    void Set(float nx, float ny, float nz, float nw)
    {
        x = nx;
        y = ny;
        z = nz;
        w = nw;
    }
};

struct State_00137848 {
    Rgba_00137848 m0;
    int m4[3];
    Vec_00137848 m10[2];
    Rgba_00137848 m30[2];
    float m38;
    float m3C;
    float m40;
    int m44[3];
};

struct Entry_00137848 {
    int m[4];
    Entry_00137848() {}
};

struct Item_00137848 {
    char pad[0x30];
};

extern State_00137848 D_003BEB00;
extern State_00137848 D_003BEB50[4];
extern Entry_00137848 D_003BEC90[0x100];
extern Item_00137848 D_003C1C90[0x96];

extern "C" void* func_003315B8(void* dst, int c, int n);
extern "C" Item_00137848* func_00136D98(Item_00137848* self);

inline void* operator new(unsigned int, void* p) { return p; }

void func_00137848(int initialize, int priority)
{
    if (priority == 0xFFFF && initialize) {
        State_00137848* s = &D_003BEB00;
        func_003315B8(s, 0, sizeof(State_00137848));
        s->m0.Set(0x48, 0x48, 0x48, 0x80);
        s->m10[0].Set(0.5f, 0.8660254f, 0.0f, 0.0f);
        s->m10[1].Set(0.0f, 1.0f, 0.0f, 0.0f);
        s->m30[0].Set(0x4B, 0x4B, 0x4B, 0x80);
        s->m30[1].Set(0, 0, 0, 0x80);
        s->m38 = 0.5f;
        s->m3C = 0.7f;
        s->m40 = 1.0f;

        State_00137848* st = D_003BEB50;
        for (int i = 3; i != -1; i--) {
            new (st) State_00137848;
            st++;
        }

        Entry_00137848* e = D_003BEC90;
        for (int i = 0xFF; i != -1; i--) {
            new (e) Entry_00137848;
            e++;
        }

        Item_00137848* it = D_003C1C90;
        for (int i = 0x95; i != -1; i--) {
            func_00136D98(it);
            it++;
        }
    }
}
