/* fuzzy: 90.3 */
/* NEAR MISS func_00231FE8 (101/379 words, size 0x5F4 want 0x5EC): net skater-history decode (bitstream into 20-entry ring of 0x90-byte records). Remaining: game keeps lh pos[0] in $a2 across the m50 float stores (mine reloads it for the func_00279F60 arg), so the blez skip and the f12 reload are one insn off; sk should be in $fp and c7D/c7E in $s7/$s6 (declaration-order search got close); stack slot 0x40 = 1 store modelled as bs.m20 = 1; bit 7 of the 4-bit read written as (b << 24) >> 31 (needs a better form). */
typedef int qword_00231FE8 __attribute__((mode(TI)));

union Row_00231FE8 {
    qword_00231FE8 q;
    float f[4];
};

struct Mat_00231FE8 {
    Row_00231FE8 r[4];
    Mat_00231FE8& operator=(const Mat_00231FE8& o)
    {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
        return *this;
    }
};

struct Vec4_00231FE8 {
    float x, y, z, w;
    void Set(float a, float b, float c, float d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
};

struct Rec_00231FE8 {
    short pos[3];
    char pad6[0xA];
    Mat_00231FE8 m10;
    Vec4_00231FE8 m50;
    float m60[3];
    char pad6C[4];
    int m70;
    int m74;
    int m78;
    char m7C;
    char m7D;
    char m7E;
    char pad7F[5];
    int m84;
    short m88;
    char pad8A[6];
};

struct Hist_00231FE8 {
    char pad[0x1C];
    int m_count;
    Rec_00231FE8 m_recs[20];
};

struct Skater_00231FE8 {
    char pad[0x2DC];
    Hist_00231FE8* m2DC;
};

struct Owner_00231FE8 {
    char pad[0x68];
    int m68;
};

struct Conn_00231FE8 {
    char pad[0x18];
    Skater_00231FE8* m18;
    Owner_00231FE8* m1C;
};

struct Bits_00231FE8 {
    int m[8];
    int m20;
};

union Flags_00231FE8 {
    unsigned int v;
    struct {
        unsigned int a : 3;
        unsigned int pad : 4;
        unsigned int b : 1;
    } f;
};

struct Net_00231FE8;
extern Net_00231FE8* D_00392068;

extern "C" void func_001FAA08(Bits_00231FE8* b);
extern "C" void func_001FAA28(Bits_00231FE8* b, void* data, int size);
extern "C" int func_001FAB88(Bits_00231FE8* b, int n);
extern "C" int func_001FAC80(Bits_00231FE8* b, int n);
extern "C" long func_001FAA60(Bits_00231FE8* b);
extern "C" Conn_00231FE8* func_002A5248(Net_00231FE8* net, int id);
extern "C" Mat_00231FE8 func_00100200(float x, float y, float z);
extern "C" unsigned int func_00279F48(Rec_00231FE8* r, float v);
extern "C" void func_00279F60(Rec_00231FE8* r, unsigned int t, int p, Vec4_00231FE8* v);

struct Cmd_00231FE8 {
    void* m0;
    int m4;
    long m8;
    int m10;
    int m14;
    int m18;
    int Run();
};

int Cmd_00231FE8::Run()
{
    Net_00231FE8* net = D_00392068;
    short pos[3];
    float vel[3];
    Bits_00231FE8 bs;
    int f;
    func_001FAA08(&bs);
    Conn_00231FE8* c = func_002A5248(net, m14);
    if (c) {
        bs.m20 = 1;
        if ((c->m1C->m68 & 1) && !(m18 & 3))
            goto decode;
    }
    {
        func_001FAA28(&bs, m0, 0x400);
        func_001FAC80(&bs, 0x20);
        f = func_001FAB88(&bs, 9);
        int bits = (f & 1) ? 0x39 : 0x29;
        if (f & 2)
            bits += 0x10;
        if (f & 4)
            bits += 0x10;
        if (f & 8)
            bits += 0x10;
        if (f & 0x10)
            bits += 0x10;
        if (f & 0x20)
            bits += 0x10;
        if (f & 0x40)
            bits += 0xC;
        if (f & 0x80) {
            bits += 5;
            bits += 3;
        }
        if (f & 0x100)
            bits += 0x10;
        m8 = (bits + 7) >> 3;
        return 1;
    }
decode:
    Skater_00231FE8* sk = c->m18;
    if (!sk)
        return 3;
    Hist_00231FE8* h = sk->m2DC;
    int n = h->m_count;
    Rec_00231FE8* prev = 0;
    Rec_00231FE8* recs = h->m_recs;
    Rec_00231FE8* cur = recs + n % 20;
    char c7D;
    unsigned int t;
    char c78;
    char c84;
    char c7C;
    int c70;
    char c7E;
    int c74;
    short c88;
    int i;
    if (n > 0) {
        prev = recs + (n + 19) % 20;
        c7C = prev->m7C;
        c78 = prev->m78;
        c70 = prev->m70;
        c74 = prev->m74;
        c84 = prev->m84;
        c7D = prev->m7D;
        c7E = prev->m7E;
        c88 = prev->m88;
        for (i = 0; i < 3; i++)
            pos[i] = prev->pos[i];
        for (i = 0; i < 3; i++)
            vel[i] = prev->m60[i];
    } else {
        c7C = 0;
        c88 = -1;
        c7D = 0;
        c78 = 0;
        c7E = 0;
        c70 = 0;
        c74 = 0;
        c84 = 0;
        for (i = 0; i < 3; i++)
            pos[i] = 0;
        for (i = 0; i < 3; i++)
            vel[i] = 0.0f;
    }
    func_001FAA28(&bs, m0, 0x400);
    t = func_001FAB88(&bs, 0x20);
    f = func_001FAB88(&bs, 9);
    if (f & 1)
        pos[0] = func_001FAC80(&bs, 0x10);
    if (f & 2)
        pos[1] = func_001FAC80(&bs, 0x10);
    if (f & 4)
        pos[2] = func_001FAC80(&bs, 0x10);
    if (f & 8)
        vel[0] = (short)func_001FAC80(&bs, 0x10) * (1.0f / 4096.0f);
    if (f & 0x10)
        vel[1] = (short)func_001FAC80(&bs, 0x10) * (1.0f / 4096.0f);
    if (f & 0x20)
        vel[2] = (short)func_001FAC80(&bs, 0x10) * (1.0f / 4096.0f);
    if (f & 0x40) {
        unsigned int b = func_001FAB88(&bs, 4);
        c78 = b & 7;
        c7C = (b << 24) >> 31;
        c84 = func_001FAB88(&bs, 6);
        c7D = func_001FAB88(&bs, 1);
        c7E = func_001FAB88(&bs, 1);
    }
    if (f & 0x80) {
        c70 = func_001FAB88(&bs, 5);
        c74 = func_001FAB88(&bs, 3);
    }
    if (f & 0x100)
        c88 = func_001FAC80(&bs, 0x10);
    m8 = func_001FAA60(&bs);
    if (sk->m2DC->m_count > 0 && t < func_00279F48(prev, vel[0]))
        return 3;
    cur->m10 = func_00100200(vel[0], vel[1], vel[2]);
    cur->m50.Set(pos[0] * 0.5f, pos[1] * 0.25f, pos[2] * 0.5f, 0.0f);
    func_00279F60(cur, t, pos[0], &cur->m50);
    for (i = 0; i < 3; i++) {
        cur->pos[i] = pos[i];
        cur->m60[i] = vel[i];
    }
    cur->m7C = c7C;
    cur->m70 = c70;
    cur->m74 = c74;
    cur->m78 = c78;
    cur->m84 = c84;
    cur->m7D = c7D;
    cur->m88 = c88;
    cur->m7E = c7E;
    sk->m2DC->m_count++;
    return 1;
}
