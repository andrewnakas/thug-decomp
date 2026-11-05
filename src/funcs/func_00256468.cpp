struct Pad_00256468 {
    char pad0[0x1C];
    unsigned int m1C;
    unsigned int m20;
};

struct Obj_00256468 {
    char pad0[0x168];
    unsigned int m168;
};

struct Self_00256468 {
    char pad0[0x1C];
    Pad_00256468* m1C;
    char pad20[0xC];
    Obj_00256468* m2C;
    void Update();
};

extern int D_0039414C;
extern int D_00394150;
extern "C" int func_001E53A0(unsigned int id, int def);
extern "C" int func_00185578(Obj_00256468* o, unsigned int id);

void Self_00256468::Update()
{
    Obj_00256468* o = m2C;
    int first = func_001E53A0(0xE60442D5, 0);
    int repeat = func_001E53A0(0x2DA212E5, 0);
    if (D_00394150 == 0) {
        D_0039414C = first;
        D_00394150 = 1;
    }
    if (m1C->m20 & 0x10) o->m168 |= 0x1000;
    Pad_00256468* p = m1C;
    if (p->m20 & 0x8000) {
        o->m168 |= 0x200;
        D_0039414C = first;
    } else if (p->m20 & 0x2000) {
        o->m168 |= 0x100;
        D_0039414C = first;
    } else if (p->m1C & 0x8000) {
        if (--D_0039414C <= 0) {
            o->m168 |= 0x200;
            D_0039414C = repeat;
        }
    } else if (p->m1C & 0x2000) {
        if (--D_0039414C <= 0) {
            o->m168 |= 0x100;
            D_0039414C = repeat;
        }
    } else {
        D_0039414C = first;
    }
    if (m1C->m20 & 0x200) o->m168 |= 0x20000;
    unsigned int b = m1C->m1C;
    if (b & 8) {
        if (!(b & 2)) o->m168 |= 0x2000;
    } else if (b & 2) {
        o->m168 |= 0x4000;
    }
    b = m1C->m20;
    if (b & 4) o->m168 |= 0x40;
    else if (b & 1) o->m168 |= 0x80;
    if (func_00185578(o, 0x72AD7B23) == 0) {
        b = m1C->m1C;
        if (b & 0x20) o->m168 |= 0x8000;
        else if (b & 0x80) o->m168 |= 0x10000;
    }
}
