struct Vec_002BBDD8 {
    float x, y, z, w;
    Vec_002BBDD8() {}
    Vec_002BBDD8(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Box_002BBDD8 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Elem_002BBDD8 {
    char pad0[0xC];
    virtual Vec_002BBDD8 Extent();
};

struct Slot_002BBDD8 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char rot;
    unsigned char flag;
    char pad5[3];
    Elem_002BBDD8* e;
};

extern float D_00392610;
extern float D_00392614;
extern float D_00392618;

struct Obj_002BBDD8;
extern "C" Elem_002BBDD8* func_002B6CF8(void* key);
extern "C" Slot_002BBDD8* func_002BB3B0(Obj_002BBDD8* o, int idx);
extern "C" void func_002B6EE8(Elem_002BBDD8* e, Vec_002BBDD8* p, int a);

struct Obj_002BBDD8 {
    char pad0[0x30];
    int m30;
    void Add(void* key, Box_002BBDD8* b, int rot, int flag);
};

void Obj_002BBDD8::Add(void* key, Box_002BBDD8* b, int rot, int flag)
{
    Elem_002BBDD8* e = func_002B6CF8(key);
    Slot_002BBDD8* s = func_002BB3B0(this, m30++);
    Vec_002BBDD8 ext = e->Extent();
    Vec_002BBDD8 p(b->x * D_00392610 + ext.x * 0.5f, b->y * D_00392614, b->z * D_00392618 + ext.z * 0.5f, 1.0f);
    func_002B6EE8(e, &p, 0);
    s->e = e;
    s->x = b->x;
    s->y = b->y;
    s->z = b->z;
    s->rot = rot;
    if (flag)
        s->flag = 1;
    else
        s->flag = 0;
}
