extern char* D_0038E320;
extern "C" int func_001F5C08(char* p);
extern "C" void func_001F5098(char* p);
extern "C" void func_001F5618(char* p);
extern "C" void func_001F53D8(char* p, int n);

extern "C" void func_001F5578()
{
    func_001F5C08(D_0038E320 + 0x673608);
    func_001F5098(D_0038E320 + 0x673700);
    func_001F5618(D_0038E320 + 0x6735C0);
    while (*(volatile int*)(D_0038E320 + 0x67370C)) {
    }
    func_001F53D8(D_0038E320 + 0x6735C0, 3);
}
