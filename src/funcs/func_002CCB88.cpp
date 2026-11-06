struct Box_002CCB88 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
    void Set(unsigned char a, signed char b, unsigned char c) { x = a; y = b; z = c; }
    unsigned char GetX() const { return x; }
    unsigned char GetZ() const { return z; }
};

struct Info_002CCB88;

struct Obj_002CCB88 {
    bool Run(unsigned char a, unsigned char b, Info_002CCB88* info);
};

extern "C" void func_002BAA28(Box_002CCB88* c, int a, int b, int d, int e, int f, int g);
extern "C" void func_002CC970(Obj_002CCB88* o, Box_002CCB88* c, int a, int b, Info_002CCB88* d);
extern "C" void* func_002C0368();
extern "C" bool func_002C0458(void* g, Box_002CCB88* b, int f);

bool Obj_002CCB88::Run(unsigned char a, unsigned char b, Info_002CCB88* info)
{
    Box_002CCB88 c;
    func_002BAA28(&c, 0, 0, 0, 0, 0, 0);
    func_002CC970(this, &c, a, b, info);
    c.Set(c.GetX(), 0, c.GetZ());
    void* g = func_002C0368();
    Box_002CCB88 t = c;
    return func_002C0458(g, &t, 1);
}
