struct Obj_002BAA28 {
    unsigned char m0;
    unsigned char m1;
    unsigned char m2;
    unsigned char m3;
    unsigned char m4;
    unsigned char m5;
    Obj_002BAA28* Set(unsigned char a, unsigned char b, unsigned char c, unsigned char d,
                      unsigned char e, unsigned char f);
};

Obj_002BAA28* Obj_002BAA28::Set(unsigned char a, unsigned char b, unsigned char c, unsigned char d,
                                unsigned char e, unsigned char f) {
    m0 = a;
    m1 = b;
    m2 = c;
    m3 = d;
    m4 = e;
    m5 = f;
    return this;
}
