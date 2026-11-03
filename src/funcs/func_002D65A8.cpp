extern char D_0037C238[];

struct Obj_002D65A8 {
    int m0;
    Obj_002D65A8* m4;
    int m8;
    Obj_002D65A8* mC;
    Obj_002D65A8* m10;
    char* m14;
    char m18;
    char pad19[0x98 - 0x19];
    char m98;
    char pad99[0xB0 - 0x99];
    char mB0;
    char padB1[0xC0 - 0xB1];
    char mC0;
    char padC1[0xD0 - 0xC1];
    char mD0;
    char padD1[0xF1 - 0xD1];
    char mF1;
    char padF2[0x1F4 - 0xF2];
    int m1F4;
    int m1F8;
    int m1FC;
    int m200;
    int m204;
    int m208;
    int m20C;
    int m210;
    int m214;
    Obj_002D65A8* Init();
};

Obj_002D65A8* Obj_002D65A8::Init()
{
    m4 = this;
    m14 = D_0037C238;
    m8 = 0;
    mC = this;
    m10 = this;
    m18 = 0;
    m98 = 0;
    mB0 = 0;
    mC0 = 0;
    mD0 = 0;
    mF1 = 0;
    m1F4 = 0;
    m200 = 0;
    m204 = 0;
    m208 = 0;
    m20C = 0;
    m210 = 0;
    m214 = 0;
    m1F8 = 0;
    m1FC = 0;
    return this;
}
