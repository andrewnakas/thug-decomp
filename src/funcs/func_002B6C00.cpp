extern char D_0037A400[];

struct Obj_002B6C00 {
    int m0;
    int m4;
    int m8;
    void* mC;
    Obj_002B6C00* Init();
};

Obj_002B6C00* Obj_002B6C00::Init() {
    m4 = 0;
    mC = D_0037A400;
    m0 = 0;
    m8 = 0;
    return this;
}
