typedef int qword __attribute__((mode(TI)));

struct Vec_00172870 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
};

struct Owner_00172870 {
    Vec_00172870 m0;
};

struct Inst_00172870 {
    char pad0[0x50];
    Vec_00172870 m50;
    int m60;
    char pad64[0x70 - 0x64];
    Owner_00172870* m70;
    Vec_00172870 Fn() const;
};

Vec_00172870 Inst_00172870::Fn() const
{
    if (m60 & 4)
        return m50;
    Vec_00172870 v = m70->m0;
    v.w += 24.0f;
    return v;
}
