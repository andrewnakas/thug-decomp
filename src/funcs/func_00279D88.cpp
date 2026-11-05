typedef int qword __attribute__((mode(TI)));
struct Vec_00279D88 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Body_00279D88 {
    char pad[0x50];
    Vec_00279D88 m50;
};

struct Obj_00279D88 {
    char pad[0xC];
    Body_00279D88* mC;
    Vec_00279D88 GetPos();
};

Vec_00279D88 Obj_00279D88::GetPos()
{
    return mC->m50;
}
