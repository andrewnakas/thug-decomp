typedef int qword_001DFA78 __attribute__((mode(TI)));

struct Vec_001DFA78 {
    union {
        struct {
            float x, y, z, w;
        };
        qword_001DFA78 q;
    };
};

struct Ctx_001DFA78 {
    float m0;
    float m4;
    char pad8[0x18];
};

struct Entry_001DFA78 {
    int m0;
    int m_id;
    float m_volume;
    float mC;
    int m10;
    char pad14[8];
    int m1C;
    int m20;
    int pad24;
};

struct Body_001DFA78 {
    char pad[0x50];
    Vec_001DFA78 m_pos;
};

struct Slot_001DFA78 {
    char pad0[0xC];
    Body_001DFA78* m_body;
    char pad10[0xC];
    int m_ids[3];
};

extern Slot_001DFA78* D_003F2220[];
extern Entry_001DFA78 D_003EE8E0[];
extern void* D_0038E0A0;

extern "C" bool func_001DED40();
extern "C" int func_001E3C58(int);
extern "C" void func_001DC540(Ctx_001DFA78*);
extern "C" void* func_0013B108(Vec_001DFA78*, int);
extern "C" int func_001A3D00(Slot_001DFA78*, void*, Vec_001DFA78*);
extern "C" void func_001A3C90(Vec_001DFA78*, Slot_001DFA78*, void*);
extern "C" int func_001DDB00(void*, Ctx_001DFA78*, Vec_001DFA78*, float, int, void*, Vec_001DFA78*);
extern "C" void func_001DC6D0(Ctx_001DFA78*);
extern "C" void func_001DC5A8(Ctx_001DFA78*, float);
extern "C" void func_001E3548(int, float, float);
extern "C" void func_001DC578(Ctx_001DFA78*, int);

bool func_001DFA78(int idx)
{
    if (func_001DED40())
        return false;
    Slot_001DFA78* slot = D_003F2220[idx];
    for (int i = 0; i < 3; i++) {
        if (D_003EE8E0[i].m_id != slot->m_ids[idx])
            continue;
        if (func_001E3C58(D_003EE8E0[idx].m10) == 1)
            return false;
        Entry_001DFA78* e = &D_003EE8E0[i];
        Ctx_001DFA78 ctx;
        func_001DC540(&ctx);
        void* mgr = D_0038E0A0;
        if (e->m1C) {
            void* near = func_0013B108(&slot->m_body->m_pos, 0);
            if (near) {
                Vec_001DFA78 tmp;
                Vec_001DFA78* pp = func_001A3D00(slot, near, &tmp) ? &tmp : 0;
                Vec_001DFA78 dir;
                func_001A3C90(&dir, slot, near);
                func_001DDB00(mgr, &ctx, &dir, e->mC, e->m20, near, pp);
            } else {
                func_001DC6D0(&ctx);
            }
        } else {
            ctx.m0 = e->m_volume;
            ctx.m4 = e->m_volume;
        }
        if (e->m_volume != 100.0f)
            func_001DC5A8(&ctx, e->m_volume);
        float right = ctx.m4;
        func_001E3548(e->m10, ctx.m0, right);
        func_001DC578(&ctx, 2);
        return true;
    }
    return false;
}
