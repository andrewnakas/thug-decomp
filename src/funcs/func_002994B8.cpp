struct Out_002994B8 {
    short x, y, z;
    short t;
    unsigned short id;
};

struct Obj_002994B8 {
    char pad[0x10];
    float x, y, z;
    char pad2[0x20 - 0x1C];
    unsigned short id;
    char pad3[0x28 - 0x22];
    float t;
    void Pack(Out_002994B8* o);
};

void Obj_002994B8::Pack(Out_002994B8* o)
{
    o->id = id;
    if (t < 0.0f)
        o->t = 0;
    else
        o->t = (short)(int)(t * 16.0f);
    o->x = (short)(int)(x * 8.0f);
    o->y = (short)(int)(y * 8.0f);
    o->z = (short)(int)(z * 8.0f);
}
