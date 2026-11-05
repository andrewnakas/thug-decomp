typedef int qword __attribute__((mode(TI)));

struct Vec_00294A68 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Slot_00294A68 {
    char pad0[0x10];
    Vec_00294A68 pos;
    float m20;
    float m24;
    char pad28[8];
};

struct Obj_00294A68 {
    char pad0[0x120];
    Slot_00294A68 slots[8];
    char pad2A0[2];
    unsigned char m2A2;
    bool GetCur(Vec_00294A68* pos, float* a, float* b);
};

bool Obj_00294A68::GetCur(Vec_00294A68* pos, float* a, float* b)
{
    *pos = slots[m2A2].pos;
    *a = slots[m2A2].m20;
    *b = slots[m2A2].m24;
    return true;
}
