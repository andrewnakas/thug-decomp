/* cflags: -fno-rerun-loop-opt */
/* fuzzy: 82.1 */


struct Slot_00292630 {
    int m0;
    char pad4[0x20 - 0x4];
    int m20;
    char pad24[0x30 - 0x24];
};

struct Obj_00292630 {
    int m0;
    char m4;
    char pad5[0x36 - 0x5];
    char m36;
    char pad37[0x4B - 0x37];
    char m4B;
    char pad4C[0xAF - 0x4C];
    char mAF;
    char padB0[0x114 - 0xB0];
    int m114;
    char pad118[0x120 - 0x118];
    Slot_00292630 m120[8];
    char m2A0;
    char m2A1;
    char m2A2;
    char m2A3;
    char m2A4;
    char m2A5;
    char pad2A6[2];
    int m2A8;
    int m2AC;
    int m2B0;
    int m2B4;
    int m2B8;
    float m2BC;
    int m2C0;
    int m2C4;
    int m2C8;
    int m2CC;
    int m2D0;
    int m2D4;
    int m2D8;
    int m2DC;
    char pad2E0[0x308 - 0x2E0];
    int m308;
    char pad30C[0x316 - 0x30C];
    char m316;
    char m317;
};

extern "C" void func_00292630(Obj_00292630* self)
{
    int i;
    self->m2B4 = 100;
    self->m2AC = 120;
    self->m2BC = 0.1f;
    self->m2C0 = 3000;
    self->m2C4 = 5;
    self->m2C8 = 11;
    self->m2CC = 360;
    self->m2D4 = 2;
    self->m2D8 = 3;
    self->m2DC = 8;
    self->m2B0 = 0x54166ACD;
    self->m2A5 = 0;
    self->m0 = 0;
    self->m4 = 0;
    self->m4B = 0;
    self->mAF = 0;
    self->m36 = 0;
    self->m114 = 0;
    self->m2A1 = 0;
    self->m2A0 = 0;
    self->m2A2 = 0;
    self->m2A3 = 0;
    self->m2A4 = 0;
    self->m2B8 = 5;
    self->m2D0 = 0;
    self->m308 = 0;
    self->m316 = 0;
    self->m317 = 0;
    for (i = 0; i < 8; i++) {
        self->m120[i].m0 = 0;
        self->m120[i].m20 = 0;
    }
    self->m2A8 = 0;
}
