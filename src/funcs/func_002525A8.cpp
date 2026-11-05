extern char D_00374DE8[];
extern "C" char* func_001041B8(void* s);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" void func_00103F28(const char* fmt, char* s);
extern "C" void func_001040A8(void* s, int flags);

struct Obj_002525A8 {
    char pad[0x10];
    char m10[0x20];
    void Fn(void* s);
};

void Obj_002525A8::Fn(void* s)
{
    func_00331A9C(m10, func_001041B8(s));
    func_00103F28(D_00374DE8, m10);
    func_001040A8(s, 2);
}
