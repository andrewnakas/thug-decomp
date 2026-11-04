extern char D_00372640[];
extern char D_00372658[];
extern char D_00372670[];
extern char D_00351FE0[];
extern char D_00354350[];

extern "C" void func_0010BFC0(const char* name);
extern "C" void func_0010BFC8();
extern "C" void func_001E5778();
extern "C" void func_00229518();
extern "C" int func_0020AAD0();
extern "C" int func_0020AAD8();
extern "C" void func_001E5910(void* table, int n);
extern "C" void func_001E59A0(void* table, int n);

void func_0022A7F0()
{
    func_0010BFC0(D_00372640);
    func_001E5778();
    func_0010BFC8();
    func_0010BFC0(D_00372658);
    func_00229518();
    func_0010BFC8();
    func_0010BFC0(D_00372670);
    func_001E5910(D_00351FE0, func_0020AAD0());
    func_001E59A0(D_00354350, func_0020AAD8());
    func_0010BFC8();
}
