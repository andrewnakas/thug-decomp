struct Obj_002CCE40;
struct Color_002CCE40 {
    unsigned char m[6];
};

struct Buf_002CCE40 {
    int m[4];
};

extern "C" void func_002BAA28(Color_002CCE40* c, int a, int b, int d, int e, int f, int g);
extern "C" void* func_002C0368();
extern "C" void func_002CC970(Obj_002CCE40* o, Color_002CCE40* c, int a, int b, int d);
extern "C" int func_002BFC50(void* p, Color_002CCE40* c, Buf_002CCE40* b);

struct Obj_002CCE40 {
    void Get_(Color_002CCE40* c, int a, int b, int d);
    int Run(unsigned char a, unsigned char b, int d);
};

int Obj_002CCE40::Run(unsigned char a, unsigned char b, int d)
{
    Color_002CCE40 c;
    func_002BAA28(&c, 0, 0, 0, 0, 0, 0);
    func_002CC970(this, &c, a, b, d);
    Color_002CCE40 c2 = c;
    Buf_002CCE40 buf;
    return func_002BFC50(func_002C0368(), &c2, &buf);
}
