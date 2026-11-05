extern char D_0038FA00[];
extern "C" void func_002242C8(char* buf, int b, int a);
extern "C" int func_00106810();
extern "C" int func_003331D0(char* buf, char* fmt, ...);

void Format_00226478(int a, int b, char* out)
{
    char buf[0x20];
    func_002242C8(buf, b, a);
    int n = func_00106810();
    func_003331D0(out, D_0038FA00, n, buf);
}
