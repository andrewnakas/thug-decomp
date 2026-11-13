/* fuzzy: 85.7 */
// nm: 4 words: addu operand/reg order idx vs base in both arms (lane 2 best)
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
};
struct Obj_001D56A0 {
    int m0;
    int m4;
    Data_001D56A0* m8;
};

extern "C" unsigned short func_001D56A0(Obj_001D56A0* o, int i)
{
    Data_001D56A0* d = o->m8;
    if (d->mA == 0) {
        E10_001D56A0* e = (E10_001D56A0*)d->mC;
        e += i;
        return e->m2;
    } else {
        E8_001D56A0* e = (E8_001D56A0*)d->mC;
        e += i;
        return e->m2;
    }
}
