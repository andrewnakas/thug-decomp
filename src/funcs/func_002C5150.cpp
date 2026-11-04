struct Struct_002C5150 { char pad[0x10]; };
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_001E73C8(void* p, char* s, int v);
extern "C" void func_001F0370(char*, void*, int, int);
extern char D_00392810[];
extern char D_0037A820[];
extern void* D_0039274C;
extern "C" void func_002C7488(void* p);
extern "C" void func_002BCE40(void* p, int a, int b);
extern "C" void* func_002C0368();
extern "C" int func_002BD248(void* p);
extern "C" void func_002BD628(void* p, int v);
extern "C" void func_002C9000(void* p, int v);
extern "C" void func_002C0E60(void* p, int a, int b);

struct Obj_002C5150 {
    char pad[0x80];
    void* m80;
    char pad84[0xA0 - 0x84];
    void* mA0;
    char padA4[0xAC - 0xA4];
    unsigned int mAC;
    void Select(int a, int b);
};

void Obj_002C5150::Select(int a, int b)
{
    bool on = false;
    if (mAC == 0x7ECA21E5 || mAC == 0xA40F0B8A) on = true;
    if (on) func_002C7488(mA0);
    func_002BCE40(D_0039274C, a, 0);
    if (!on) return;
    if (func_002BD248(func_002C0368()) != b) {
        Struct_002C5150 s;
        func_001E6978(&s);
        func_001E73C8(&s, D_00392810, 0xE8B4B836);
        func_001F0370(D_0037A820, &s, 0, 0);
        func_001E6AE8(&s, 2);
    } else {
        func_002BD628(func_002C0368(), 0);
        func_002C9000(mA0, 0);
        func_002C0E60(m80, 0, 0);
    }
}
