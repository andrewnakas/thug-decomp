extern char D_0037CB00[];

struct Obj_002DA5C8 {
    int m0;
    Obj_002DA5C8* m4;
    int m8;
    Obj_002DA5C8* mC;
    Obj_002DA5C8* m10;
    void* m14;
    Obj_002DA5C8* Init();
};

Obj_002DA5C8* Obj_002DA5C8::Init() {
    m4 = this;
    m14 = D_0037CB00;
    m8 = 0;
    mC = this;
    m10 = this;
    return this;
}
