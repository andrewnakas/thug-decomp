struct Hdr_002BD288 {
    char pad0[6];
    unsigned short m6;
    char pad8[0x1C - 8];
    char m1C[4];
};

struct Obj_002BD288 {
    char pad0[0x6A60];
    Hdr_002BD288* m6A60;
    char* Data();
};

char* Obj_002BD288::Data()
{
    Hdr_002BD288* h = m6A60;
    if (h && h->m6 == 0x4E24)
        return h->m1C;
    return 0;
}
