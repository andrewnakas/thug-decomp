extern "C" void* func_00131E48();
extern "C" void* func_00131E88();
extern "C" void* func_001190D0(int n);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_00134698(void* src, void* dst);
extern "C" void func_001E78A8(void* s, unsigned int id, void* sub);
extern "C" void func_001E7200(void* s, unsigned int id, int v);
extern "C" void func_00146610(void* s);
extern int D_0038BC88;
extern int D_0038BC8C;
extern int D_0038BC90;
extern int D_0038BC94;
extern int D_0038BC98;
extern int D_0038BC9C;
extern int D_0038BCA0;
extern int D_0038BCA4;
extern int D_0038BCA8;
extern int D_0038BCAC;
extern int D_0038BCB0;
extern int D_0038BCB4;
extern int D_0038BCB8;
extern int D_0038BCBC;
extern int D_0038BCC0;
extern int D_0038BCC4;
extern int D_0038BCC8;
extern int D_0038BCCC;
extern int D_0038BCD0;

void func_001326F8(void* out)
{
    void* s;
    if (func_00131E48()) {
        s = func_001E6978(func_001190D0(8));
        func_00134698(func_00131E48(), s);
        func_001E78A8(out, 0x9B10525C, s);
    }
    if (func_00131E88()) {
        s = func_001E6978(func_001190D0(8));
        func_00134698(func_00131E88(), s);
        func_001E78A8(out, 0x02C5EA34, s);
    }
    s = func_001E6978(func_001190D0(8));
    func_001E7200(s, 0x3DD01EA1, D_0038BC88);
    func_001E7200(s, 0x742CF11F, D_0038BC8C);
    func_001E7200(s, 0xF9D98B10, D_0038BC90);
    func_001E7200(s, 0x6D65D103, D_0038BC94);
    func_001E7200(s, 0x52AA1A77, D_0038BC98);
    func_001E7200(s, 0xAF792E8D, D_0038BC9C);
    func_001E7200(s, 0xA863E48C, D_0038BCA0);
    func_001E7200(s, 0x93070C4B, D_0038BCA4);
    func_001E7200(s, 0xAC43724A, D_0038BCA8);
    func_001E7200(s, 0x68306FFE, D_0038BCAC);
    func_001E7200(s, 0xAE81C5F6, D_0038BCB0);
    func_001E7200(s, 0xBA802AB0, D_0038BCB4);
    func_001E7200(s, 0x1BC830F2, D_0038BCB8);
    func_001E7200(s, 0x3960FF18, D_0038BCBC);
    func_001E7200(s, 0x506A239F, D_0038BCC0);
    func_001E7200(s, 0x169A94B7, D_0038BCC4);
    func_001E7200(s, 0x7B471BA2, D_0038BCC8);
    func_001E7200(s, 0x18725397, D_0038BCCC);
    func_001E7200(s, 0x8A897DD2, D_0038BCD0);
    func_001E78A8(out, 0xF2316B47, s);
    func_00146610(out);
}
