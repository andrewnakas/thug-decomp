extern char D_003914D0[];
extern char D_003914D8[];
extern char D_003914E0[];
extern char D_003914E8[];
extern char D_003914F0[];
extern char D_003914F8[];
extern char D_003764B0[];
extern char D_00391500[];
extern char D_00391508[];
extern char D_00391510[];
extern char D_00391518[];
extern char D_00391520[];
extern char D_00391528[];
extern char D_00391530[];
extern char D_00391538[];
extern char D_00391540[];

struct Rec_0026F090 {
    char m[0x24];
};

extern "C" void func_0026FDD8(Rec_0026F090* r, char* name);

struct Stats_0026F090 {
    int m0;
    Rec_0026F090 m4;
    Rec_0026F090 m28;
    Rec_0026F090 m4C;
    Rec_0026F090 m70;
    Rec_0026F090 m94;
    Rec_0026F090 mB8;
    Rec_0026F090 mDC;
    Rec_0026F090 m100;
    Rec_0026F090 m124;
    Rec_0026F090 m148;
    Rec_0026F090 m16C;
    Rec_0026F090 m190;
    Rec_0026F090 m1B4;
    Rec_0026F090 m1D8;
    Rec_0026F090 m1FC;
    Rec_0026F090 m220;
    int m244[12];
    int m274;
    int m278;
    Stats_0026F090* Construct();
};

Stats_0026F090* Stats_0026F090::Construct()
{
    func_0026FDD8(&m4, D_003914D0);
    func_0026FDD8(&m28, D_003914D8);
    func_0026FDD8(&m4C, D_003914E0);
    func_0026FDD8(&m70, D_003914E8);
    func_0026FDD8(&m190, D_003914F0);
    func_0026FDD8(&m16C, D_003914F8);
    func_0026FDD8(&m1B4, D_003764B0);
    func_0026FDD8(&m1D8, D_00391500);
    func_0026FDD8(&m94, D_00391508);
    func_0026FDD8(&mB8, D_00391510);
    func_0026FDD8(&mDC, D_00391518);
    func_0026FDD8(&m100, D_00391520);
    func_0026FDD8(&m124, D_00391528);
    func_0026FDD8(&m148, D_00391530);
    func_0026FDD8(&m1FC, D_00391538);
    func_0026FDD8(&m220, D_00391540);
    m274 = 0;
    m278 = 0;
    return this;
}
