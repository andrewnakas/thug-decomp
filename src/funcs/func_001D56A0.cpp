struct E8_001D56A0 {
    unsigned short m0;
    unsigned short m2;
    int m4;
};
struct E10_001D56A0 {
    unsigned short m0;
    unsigned short m2;
    unsigned short m4;
    unsigned short m6;
    unsigned short m8;
};
struct Data_001D56A0 {
    char pad[0xA];
    unsigned char mA;
    void* mC;
    unsigned short Get(int i)
    {
        if (mA != 0)
            return ((E8_001D56A0*)mC)[i].m2;
        return ((E10_001D56A0*)mC)[i].m2;
    }
};
struct Obj_001D56A0 {
    int m0;
    int m4;
    Data_001D56A0* m8;
};

extern "C" unsigned short func_001D56A0(Obj_001D56A0* o, int i)
{
    return o->m8->Get(i);
}
