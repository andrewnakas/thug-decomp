struct Sub_002B6208 {
    int m0;
    int m4;
    int m8;
    int mC;
    Sub_002B6208() { m0 = 0; m4 = 0; m8 = 0; mC = 0; }
};

struct Obj_002B6208 {
    char pad0[0x10];
    Sub_002B6208 m10;
    char pad20[0x8];
    int m28;
    Obj_002B6208();
};

Obj_002B6208::Obj_002B6208() {
    m28 = 0;
}
