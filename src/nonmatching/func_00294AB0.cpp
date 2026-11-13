/* fuzzy: 90.9 */
typedef int qword __attribute__((mode(TI)));

struct Vec_00294AB0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Slot_00294AB0 {
    char pad0[0x10];
    Vec_00294AB0 pos;
    float m20;
    float m24;
    char pad28[8];
};

struct Obj_00294AB0 {
    char pad0[0x120];
    Slot_00294AB0 slots[8];
    Slot_00294AB0* GetSlot(int i) { return &slots[i]; }
    void GetPos(Vec_00294AB0* out, int i);
};

void Obj_00294AB0::GetPos(Vec_00294AB0* out, int i)
{
    *out = slots[i].pos;
    out->y += GetSlot(i)->m20;
}
