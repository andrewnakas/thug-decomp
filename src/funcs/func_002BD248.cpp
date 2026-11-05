struct Hdr_002BD248 {
    char pad0[8];
    unsigned short m8;
};

struct Park_002BD248 {
    char pad0[0x6A60];
    Hdr_002BD248* m6A60;
    int m6A64;
    int Count();
};

int Park_002BD248::Count()
{
    if (m6A64 & 2)
        return m6A60->m8;
    return 0;
}
