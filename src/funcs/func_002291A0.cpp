extern char D_00372528[];
extern char D_0038FAE8[];
extern char D_0038FAF0[];

struct MemMgr_002291A0 {
    char m_pad[0xD8];
    void* mD8;
};

extern MemMgr_002291A0* D_00388A70;

extern "C" void func_0010A950(MemMgr_002291A0* self, void* context);
extern "C" void func_0010A9B0(MemMgr_002291A0* self);
extern "C" void func_0010D518(const char* name);
extern "C" char* func_0010DAB0(const char* name);
extern "C" int func_0010DD60(const char* name);
extern "C" void func_001E4DA0();
extern "C" char* func_003364D8(const char* s, const char* find);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" unsigned int func_00105520(const char* name);
extern "C" void func_002294C0(unsigned int crc);
extern "C" void func_00229340(const char* name, int a);
extern "C" void func_001E4DB0();
extern "C" void func_0010DCD0(const char* name);
extern "C" void func_0010D970(const char* name);
extern "C" void* func_001E4FC8(unsigned int name);
extern "C" void func_001ED8D0(void* script);

void func_002291A0()
{
    MemMgr_002291A0* mem = D_00388A70;
    func_0010A950(mem, mem->mD8);
    func_0010D518(D_0038FAE8);
    func_0010A9B0(D_00388A70);
    char* buf = func_0010DAB0(D_00372528);
    int size = func_0010DD60(D_00372528);
    func_001E4DA0();
    char* p = buf;
    while (p < buf + size) {
        char line[200];
        int i = 0;
        while (p < buf + size && *p != '\r' && *p != '\n') {
            line[i++] = *p++;
        }
        line[i] = 0;
        p++;
        if (line[0]) {
            char* s = func_003364D8(line, D_0038FAF0);
            if (s) {
                func_00331A9C(line, s + 5);
            }
            func_002294C0(func_00105520(line));
            func_00229340(line, 1);
        }
    }
    func_001E4DB0();
    func_0010DCD0(D_00372528);
    func_0010D970(D_0038FAE8);
    void* script = func_001E4FC8(0xC2F97BA7);
    if (script) {
        func_001ED8D0(script);
    }
}
