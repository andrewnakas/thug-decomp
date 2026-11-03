extern char D_00379E88[];

struct Obj_002B60E8 {
    int m0;
    Obj_002B60E8* m4;
    int m8;
    Obj_002B60E8* mC;
    Obj_002B60E8* m10;
    void* m14;
    char pad18[0x54];
    int m6C;
    int m70;
    int m74;
    Obj_002B60E8* Init();
};

Obj_002B60E8* Obj_002B60E8::Init() {
    m4 = this;
    m14 = D_00379E88;
    m8 = 0;
    mC = this;
    m10 = this;
    m6C = 0;
    m74 = 0;
    m70 = 0;
    return this;
}
