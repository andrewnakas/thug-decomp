extern "C" int func_00103F28(char* fmt, ...);
extern "C" int func_001E4710(void* a);
extern "C" void func_001E4428(char* a, char* b, char* c);
extern "C" void func_001E4AD0();
extern int D_0038E324;
extern char* D_0038E320;
extern int D_0039411C;
extern char D_003646C8[];
extern char D_00364710[];

int Decode_001E4398(void* data)
{
    func_00103F28(D_003646C8, D_0038E324++);
    if (func_001E4710(data)) {
        func_00103F28(D_00364710);
        char* base = D_0038E320;
        func_001E4428(base + 0x6735C0, base + 0x623540, base + 0x673580);
    }
    func_001E4AD0();
    return D_0039411C;
}
