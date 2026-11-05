struct Sk_002B2FC8 {
    char pad0[0x68];
    int m68;
};


static inline void ClearMask_002B2FC8(Sk_002B2FC8* s, const unsigned int& m) { s->m68 &= ~m; }
static inline void SetMask_002B2FC8(Sk_002B2FC8* s, const unsigned int& m) { s->m68 |= m; }
static inline void Clear_002B2FC8(Sk_002B2FC8* s, int f) { ClearMask_002B2FC8(s, f); }
static inline void Set_002B2FC8(Sk_002B2FC8* s, int f) { SetMask_002B2FC8(s, f); }

extern "C" void func_00202A00(Sk_002B2FC8* s);

struct Obj_002B2FC8 {
    char pad0[0x1C];
    Sk_002B2FC8* m1C;
    char pad20[0x150 - 0x20];
    int m150;
    void Release(int id);
};

void Obj_002B2FC8::Release(int id)
{
    if (m150 == id) {
        if (m1C) {
            Clear_002B2FC8(m1C, 2);
            Set_002B2FC8(m1C, 1);
            func_00202A00(m1C);
        }
        m150 = 0;
    }
}
