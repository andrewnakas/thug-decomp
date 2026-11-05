extern char D_0037BF08[];
extern "C" int func_003331D0(char* buf, const char* fmt, ...);

struct Obj_002D4DC0;
extern "C" void func_002D4CF8(Obj_002D4DC0* o, char* s);

struct Src_002D4DC0 {
    char pad[0x1C];
    char name[1];
};

struct Obj_002D4DC0 {
    int m0;
    int m4;
    int m8;
    int mC;
    char pad10[0x37C - 0x10];
    char m37C[1];
    void Start(Src_002D4DC0* s);
};

void Obj_002D4DC0::Start(Src_002D4DC0* s)
{
    char buf[0x80];
    func_003331D0(buf, D_0037BF08, m37C, s->name);
    mC = 0;
    m4 = 2;
    func_002D4CF8(this, buf);
}
