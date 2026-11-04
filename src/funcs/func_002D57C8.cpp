struct Heap_002D57C8 {
    char pad[0x108];
    int m108;
};

struct Obj_002D57C8;

extern Heap_002D57C8* D_00388A70;
extern void* D_00392068;
extern char* (*D_00392FE0)();
extern char D_0037C030[];
extern char D_0037C040[];
extern char D_00392C90[];
extern char D_00392BC8[];
extern char D_00392C98[];
extern char D_00392CA0[];
extern char D_0037C050[];
extern char D_0037C060[];
extern char D_0037C070[];
extern char D_0037C080[];
extern char D_00392CA8[];
extern char D_00392CB0[];
extern char D_0037C090[];
extern char D_0037C0A0[];
extern char D_00392CB8[];
extern char D_00392CC0[];
extern char D_00392CC8[];
extern char D_00392CD0[];
extern char D_00392CD8[];
extern char D_0037C0B0[];
extern char D_00392CE0[];
extern char D_0037C0C0[];
extern char D_0037C0D0[];
extern char D_00392CE8[];
extern char D_00392CF0[];
extern char D_00392CF8[];
extern char D_0037C0E0[];
extern "C" void* func_002A6070(void* m);
extern "C" int func_001F0D78(const char* s);
extern "C" void* func_00202EF8(void* p, int crc);
extern "C" int func_001E8890(void* s, char* name, int* out, int a);
extern "C" void func_0031BCE0(void* p);
extern "C" void func_003267F8();
extern "C" void func_0010A950(Heap_002D57C8* p, int v);
extern "C" void func_0010A9B0(Heap_002D57C8* p);
extern "C" void* func_002E4A60();
extern "C" int func_001E9CF8(void* p, int max);
extern "C" void* func_0010A638(Heap_002D57C8* pool, unsigned int size, int a, int b);
extern "C" void func_001E9B08(void* p, void* buf, int size, int a);
extern "C" int func_00105488(void* buf, int size);
extern "C" char* func_00331A9C(char* d, const char* s);
extern "C" int func_002E4A80(void* f, char* name, char* value);
extern "C" void func_003331D0(char* buf, char* fmt, ...);
extern "C" void func_002E4B40(void* f, char* name, void* data, int size, char* fname, int a);
extern "C" void* func_002E4840(char* url, int a, void* f, int b, int c, void* cb1, void* cb2, Obj_002D57C8* o);
extern "C" void func_00326938();
extern "C" void func_0031BCC0(void* p);
extern "C" int func_002D3FD0(void*);
extern "C" int func_002D41C0(void*);

struct Obj_002D57C8 {
    char pad0[0x14];
    int m14;
    void* m18;
    char pad1C[0xA0 - 0x1C];
    char mA0[0x120 - 0xA0];
    char m120[0x320 - 0x120];
    void* m320;
    void* m324;
    void* m328;
    int m32C;
    int m330;
    int m334;
    int m338;
    int m33C;
    int m340;
    int m344;
    int m348;
    int m34C;
    char pad350[0x378 - 0x350];
    unsigned int m378;
    void Upload();
};

void Obj_002D57C8::Upload()
{
    char name[0x40];
    char url[0x400];
    char num[0x40];
    int val;
    func_001E8890(func_00202EF8(func_002A6070(D_00392068), func_001F0D78(D_0037C030)), D_0037C040, &val, 1);
    func_0031BCE0(m320);
    func_003267F8();
    func_0010A950(D_00388A70, D_00388A70->m108);
    void* f = func_002E4A60();
    void* data;
    int size;
    int crc;
    switch (m378) {
    case 0x5BE5569F: {
        size = func_001E9CF8(m328, 100000);
        data = func_0010A638(D_00388A70, size, 1, 0);
        func_001E9B08(m328, data, size, 1);
        crc = func_00105488(data, size);
        func_00331A9C(name, mA0);
        func_002E4A80(f, D_00392C90, (char*)val);
        func_003331D0(num, D_00392BC8, m330);
        func_002E4A80(f, D_00392C98, num);
        func_003331D0(num, D_00392BC8, m334);
        func_002E4A80(f, D_00392CA0, num);
        func_003331D0(num, D_00392BC8, crc);
        func_002E4A80(f, D_0037C050, num);
        func_003331D0(num, D_00392BC8, m338);
        func_002E4A80(f, D_0037C060, num);
        func_003331D0(num, D_00392BC8, m33C);
        func_002E4A80(f, D_0037C070, num);
        func_003331D0(num, D_00392BC8, m340);
        func_002E4A80(f, D_0037C080, num);
        func_003331D0(num, D_00392BC8, m344);
        func_002E4A80(f, D_00392CA8, num);
        func_003331D0(num, D_00392CB0, m348);
        func_002E4A80(f, D_0037C090, num);
        break;
    }
    case 0x07364EA1: {
        func_002E4A80(f, D_0037C0A0, D_00392CB8);
        func_003331D0(num, D_00392BC8, m34C);
        func_002E4A80(f, D_00392CC0, num);
        size = func_001E9CF8(m328, 100000);
        data = func_0010A638(D_00388A70, size, 1, 0);
        func_001E9B08(m328, data, size, 1);
        crc = func_00105488(data, size);
        func_00331A9C(name, mA0);
        func_002E4A80(f, D_00392C90, (char*)val);
        func_003331D0(num, D_00392BC8, crc);
        func_002E4A80(f, D_0037C050, num);
        break;
    }
    case 0x38DBE1D0: {
        func_002E4A80(f, D_0037C0A0, D_00392CC8);
        func_003331D0(num, D_00392BC8, m340);
        func_002E4A80(f, D_0037C080, num);
        size = func_001E9CF8(m328, 100000);
        data = func_0010A638(D_00388A70, size, 1, 0);
        func_001E9B08(m328, data, size, 1);
        crc = func_00105488(data, size);
        func_00331A9C(name, mA0);
        func_002E4A80(f, D_00392C90, (char*)val);
        func_003331D0(num, D_00392BC8, crc);
        func_002E4A80(f, D_0037C050, num);
        break;
    }
    case 0x1E26FD3E: {
        func_002E4A80(f, D_0037C0A0, D_00392CD0);
        func_003331D0(num, D_00392BC8, m32C);
        func_002E4A80(f, D_00392CD8, num);
        size = func_001E9CF8(m328, 100000);
        data = func_0010A638(D_00388A70, size, 1, 0);
        func_001E9B08(m328, data, size, 1);
        crc = func_00105488(data, size);
        func_00331A9C(name, mA0);
        func_002E4A80(f, D_00392C90, (char*)val);
        func_003331D0(num, D_00392BC8, crc);
        func_002E4A80(f, D_0037C050, num);
        break;
    }
    default:
        data = 0;
        size = 0;
        break;
    }
    m18 = data;
    m14 = size;
    func_002E4B40(f, D_0037C0B0, data, size, name, 0);
    func_003331D0(url, D_00392CE0, m120);
    func_002E4A80(f, D_0037C0C0, url);
    func_002E4A80(f, D_0037C0D0, D_00392FE0());
    switch (m378) {
    case 0x5BE5569F:
        func_002E4A80(f, D_0037C0A0, D_00392CE8);
        break;
    case 0x07364EA1:
        func_002E4A80(f, D_0037C0A0, D_00392CB8);
        break;
    case 0x38DBE1D0:
        func_002E4A80(f, D_0037C0A0, D_00392CC8);
        break;
    case 0x1E26FD3E:
        func_002E4A80(f, D_0037C0A0, D_00392CD0);
        break;
    }
    func_002E4A80(f, D_00392CF0, D_00392CF8);
    m324 = func_002E4840(D_0037C0E0, 0, f, 0, 0, (void*)func_002D3FD0, (void*)func_002D41C0, this);
    func_00326938();
    func_0010A9B0(D_00388A70);
    func_0031BCC0(m320);
}
