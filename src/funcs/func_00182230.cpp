extern char D_00361550[];
extern char D_00361568[];
extern char D_0038C1F0[];
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" int func_00110DC8(char* name);
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" void* func_00110E38(char* name, char* mode);
extern "C" int func_00111038(void* buf, int size, int n, void* f);
extern "C" int func_00110EF8(void* f);

extern "C" void func_00182230(const char* name, void* data)
{
    char buf[0x90];
    for (int i = 0;; i++) {
        func_003331D0(buf, D_00361550, name, i);
        if (!func_00110DC8(buf)) {
            break;
        }
    }
    func_00103F28(D_00361568, buf);
    void* f = func_00110E38(buf, D_0038C1F0);
    func_00111038(data, 1, 0xD2036, f);
    func_00110EF8(f);
}
