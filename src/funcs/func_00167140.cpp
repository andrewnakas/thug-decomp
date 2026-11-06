typedef int qword __attribute__((mode(TI)));

struct Big_00167140 {
    qword q[23];
};

struct Small_00167140 {
    qword q[12];
};

struct Obj_00167140 {
    union {
        Big_00167140 big;
        Small_00167140 small;
        struct {
            char pad0[0x50];
            int m50;
        };
    };
};

Obj_00167140* func_00167140(Obj_00167140* dst, const Obj_00167140* src)
{
    if (src->m50 & 1)
        dst->big = src->big;
    else
        dst->small = src->small;
    return dst;
}
