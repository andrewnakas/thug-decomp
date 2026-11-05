struct Sk_002B2F40 {
    char pad0[0x68];
    int m68;
};


static inline void ClearMask_002B2F40(Sk_002B2F40* s, const unsigned int& m) { s->m68 &= ~m; }
static inline void SetMask_002B2F40(Sk_002B2F40* s, const unsigned int& m) { s->m68 |= m; }
static inline void Clear_002B2F40(Sk_002B2F40* s, int f) { ClearMask_002B2F40(s, f); }
static inline void Set_002B2F40(Sk_002B2F40* s, int f) { SetMask_002B2F40(s, f); }

extern "C" int func_00202778(Sk_002B2F40* s);

struct Obj_002B2F40 {
    char pad0[0x1C];
    Sk_002B2F40* m1C;
    char pad20[0x150 - 0x20];
    int m150;
    void Update(int x);
};

void Obj_002B2F40::Update(int x)
{
    if (m1C && func_00202778(m1C)) {
        if (x)
            m150 = x;
        Clear_002B2F40(m1C, 1);
        Set_002B2F40(m1C, 2);
    }
}
