struct Color_002CE120 {
    unsigned char m0;
    unsigned char m1;
    unsigned char m2;
    unsigned char m3;
    unsigned char m4;
    unsigned char m5;
};

struct Def_002CE120 {
    char pad0[0x10];
    Color_002CE120 m10;
    char pad16[0x44 - 0x16];
    int m44;
};

static inline void SetDims(Color_002CE120* o, unsigned char w, unsigned char d)
{
    o->m3 = w;
    o->m4 = 1;
    o->m5 = d;
}

struct Obj_002CE120 {
    unsigned char m0;
    Color_002CE120 m1;
    unsigned char m7;
    unsigned char m8;
    unsigned char m9;
    unsigned char mA;
    Color_002CE120* Dims() { return &m1; }
    void Place(Def_002CE120* def, Color_002CE120* out);
};

void Obj_002CE120::Place(Def_002CE120* def, Color_002CE120* out)
{
    int dx = m7 - ((unsigned)(m7 + m9) >> 1);
    int dz = m8 - ((unsigned)(m8 + mA) >> 1);
    int ox = 0;
    int oz = 0;
    switch (def->m44) {
    case 0: {
        Color_002CE120* c = Dims();
        ox = dx;
        oz = dz;
        SetDims(out, c->m3, c->m5);
        break;
    }
    case 3: {
        Color_002CE120* c = Dims();
        ox = -dz;
        oz = dx;
        SetDims(out, c->m5, c->m3);
        ox = ox - c->m5 + 1;
        break;
    }
    case 2: {
        Color_002CE120* c = Dims();
        ox = -dx;
        oz = -dz;
        SetDims(out, c->m3, c->m5);
        ox = ox - c->m3 + 1;
        oz = oz - c->m5 + 1;
        break;
    }
    case 1: {
        Color_002CE120* c = Dims();
        oz = -dx;
        ox = dz;
        SetDims(out, c->m5, c->m3);
        oz = oz - c->m3 + 1;
        break;
    }
    }
    Color_002CE120 base = def->m10;
    out->m1 = 0;
    out->m0 = base.m0 + ox;
    out->m2 = base.m2 + oz;
}
