extern "C" void func_00103F28(const char*, ...);
extern "C" void func_001742A8();
extern "C" void func_001DC9E8(void*);
extern "C" void func_003288E0(int);
extern "C" void func_003291C0(int);
extern "C" void func_00328DB8(int);
extern "C" void func_001DEF18(int);
extern "C" void func_001DEEE0();
extern "C" void func_00329400();
extern "C" void func_00328FC0();
extern "C" void func_00328660(int);
extern "C" void func_0031A0E8();

extern void* D_0038E0A0;
extern int D_0038881C;
extern char D_0035AA70[], D_0035AA98[], D_0035AAC0[];

void func_001061A0()
{
    func_00103F28(D_0035AA70);
    func_001742A8();
    func_001DC9E8(D_0038E0A0);
    if (D_0038881C == 0) {
        func_00103F28(D_0035AA98);
        func_003288E0(0);
        func_003291C0(2);
        func_00328DB8(0);
    } else {
        func_00103F28(D_0035AAC0);
        func_001DEF18(-1);
        func_001DEEE0();
        func_00329400();
        func_00328FC0();
        func_00328660(0);
        func_00328DB8(0);
    }
    func_0031A0E8();
}
