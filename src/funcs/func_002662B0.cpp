extern "C" char func_00266238(void* p, int a);

struct Pkt_002662B0 {
    unsigned char counts[8];
    unsigned char data[1];
};

struct Buf_002662B0 {
    int m0;
    int m4;
    Pkt_002662B0* m8;
    void* mC;
};

struct Obj_002662B0 {
    char pad[0x18];
    int m18;
    char pad2[0x20 - 0x1C];
    int m20;
    int m24;
    void Write(Buf_002662B0* b);
};

void Obj_002662B0::Write(Buf_002662B0* b)
{
    if (m24 && m20 == b->m0) {
        b->m8->data[b->m4] = func_00266238(b->mC, m18);
        b->m4++;
        b->m8->counts[b->m0]++;
    }
}
