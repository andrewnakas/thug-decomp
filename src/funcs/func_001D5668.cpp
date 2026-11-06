struct V8_001D5668 {
    unsigned short m0;
    unsigned short m2[3];
};
struct V10_001D5668 {
    unsigned short m0;
    unsigned short m2[4];
};
struct Desc_001D5668 {
    char pad[0xA];
    unsigned char mA;
    char padB;
    void* mC;
    unsigned short Get(int i)
    {
        if (mA)
            return ((V8_001D5668*)mC)[i].m0;
        else
            return ((V10_001D5668*)mC)[i].m0;
    }
};
struct Obj_001D5668 {
    int m0;
    int m4;
    Desc_001D5668* m8;
    int Get(int i);
};

int Obj_001D5668::Get(int i)
{
    return m8->Get(i);
}
