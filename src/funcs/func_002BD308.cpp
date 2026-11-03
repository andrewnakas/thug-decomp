extern char D_0037A540[];
extern char D_00392770[];
extern char D_00392778[];

extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" int func_001E9CF8(void* s, int max);
extern "C" void* func_0010BDE0(int size);
extern "C" void func_001E9B08(void* s, void* buf, int size, int a);
extern "C" void* func_00110E38(char* path, char* mode);
extern "C" int func_00111038(void* buf, int size, int n, void* f);
extern "C" int func_00110EF8(void* f);
extern "C" void func_0010BEB8(void* p);
extern "C" long func_00110980(void* f);
extern "C" int func_00110F68(void* buf, int size, int n, void* f);
extern "C" void func_001E9D70(void* s, void* buf);

struct Obj_002BD308;
extern "C" void func_002BCF50(Obj_002BD308* o, void* s);
extern "C" void func_002BD080(Obj_002BD308* o, void* s, int v);

struct Obj_002BD308 {
    char pad[0x6A64];
    int m6A64;
    void SaveLoad(int save);
};

void Obj_002BD308::SaveLoad(int save)
{
    char path[0x40];
    func_003331D0(path, D_0037A540);
    if (save) {
        void* s = func_001E6978(func_001190D0(8));
        func_002BCF50(this, s);
        int size = func_001E9CF8(s, 100000);
        void* buf = func_0010BDE0(size);
        func_001E9B08(s, buf, size, 1);
        void* f = func_00110E38(path, D_00392770);
        func_00111038(buf, size, 1, f);
        func_00110EF8(f);
        func_0010BEB8(buf);
        if (s)
            func_001E6AE8(s, 3);
    } else {
        void* f = func_00110E38(path, D_00392778);
        int size = func_00110980(f);
        void* buf = func_0010BDE0(size);
        func_00110F68(buf, size, 1, f);
        func_00110EF8(f);
        void* s = func_001E6978(func_001190D0(8));
        func_001E9D70(s, buf);
        func_0010BEB8(buf);
        func_002BD080(this, s, 0);
        if (s)
            func_001E6AE8(s, 3);
        m6A64 |= 6;
        m6A64 &= ~1;
        m6A64 &= ~8;
    }
}
