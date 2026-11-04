extern "C" int func_00103F28(const char* fmt, ...);
extern char D_0035A900[];
extern char D_0035A918[];

extern "C" void func_00100588(float* m)
{
    func_00103F28(D_0035A900);
    func_00103F28(D_0035A918, m[0], m[1], m[2], m[3]);
    func_00103F28(D_0035A918, m[4], m[5], m[6], m[7]);
    func_00103F28(D_0035A918, m[8], m[9], m[10], m[11]);
    func_00103F28(D_0035A918, m[12], m[13], m[14], m[15]);
    func_00103F28(D_0035A900);
}
