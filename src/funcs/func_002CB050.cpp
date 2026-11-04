typedef int qword __attribute__((mode(TI)));

union Vec_002CB050 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct Color_002CB050 {
    unsigned char m[6];
};

extern void* D_0039274C;
extern void* D_00392808;
extern "C" void* func_002C0368();
extern "C" void func_002BDDA8(void* p, Color_002CB050* c);
extern "C" void func_002BD7D8(void* p, int v);
extern "C" Vec_002CB050 func_002C02B0(void* a, Color_002CB050* c, Vec_002CB050* out);
extern "C" void* func_0029C320();
extern "C" void func_0029A8C8(void* p, int v, float a, float b, float c, float d);
extern "C" void* func_002977B0();
extern "C" void func_002968A0(void* p, float a, float b, float c, float d);
extern "C" void func_002C70A0(void* p);

void Draw_002CB050(Color_002CB050* col)
{
    Color_002CB050 c = *col;
    func_002BDDA8(func_002C0368(), &c);
    func_002BD7D8(func_002C0368(), 0);
    Vec_002CB050 pos;
    Vec_002CB050 size;
    pos = func_002C02B0(D_0039274C, col, &size);
    func_0029A8C8(func_0029C320(), 0, pos.f.x + 10.0f, pos.f.z + 10.0f,
                  pos.f.x + size.f.x - 10.0f, pos.f.z + size.f.z - 10.0f);
    func_002968A0(func_002977B0(), pos.f.x, pos.f.z, pos.f.x + size.f.x, pos.f.z + size.f.z);
    func_002C70A0(D_00392808);
}
