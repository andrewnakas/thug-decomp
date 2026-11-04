struct Pad_002C6DB0 {
    unsigned char m0;
    unsigned char m1;
    unsigned char m2;
    unsigned char m3;
    unsigned char m4;
    char pad5[0x1C - 5];
    int m1C;
    int m20;
};

struct Out_002C6DB0 {
    char pad[0x50];
    float m50;
    float m54;
    float m58;
    float m5C;
    int m60;
};

struct Ctl_002C6DB0 {
    char pad[0x1C];
    Pad_002C6DB0* m1C;
    char pad20[0x2C - 0x20];
    Out_002C6DB0* m2C;
    void Update();
};

void Ctl_002C6DB0::Update()
{
    Out_002C6DB0* o = m2C;
    o->m60 = 0;
    o->m50 = m1C->m1 - 128;
    o->m54 = m1C->m2 - 128;
    o->m58 = m1C->m3 - 128;
    o->m5C = m1C->m4 - 128;
    if (m1C->m20 & 0x80) o->m60 |= 4;
    if (m1C->m20 & 0x20) o->m60 |= 2;
    if (m1C->m20 & 0x40) o->m60 |= 0x20;
    if (m1C->m20 & 0x10) o->m60 |= 0x40;
    if (m1C->m20 & 0x4) o->m60 |= 0x80;
    if (m1C->m20 & 0x1) o->m60 |= 0x100;
    if (m1C->m20 & 0x8) o->m60 |= 0x800;
    if (m1C->m20 & 0x2) o->m60 |= 0x1000;
    if (m1C->m20 & 0x4) o->m60 |= 0x8000;
    if (m1C->m20 & 0x1) o->m60 |= 0x10000;
    if (m1C->m1C & 0x8) o->m60 |= 0x2000;
    if (m1C->m1C & 0x2) o->m60 |= 0x4000;
}
