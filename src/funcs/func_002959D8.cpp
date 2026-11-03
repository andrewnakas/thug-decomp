struct Board_002959D8 {
    char pad[0x114];
    unsigned int m114;
};
struct Struct_002959D8 { char pad[0x10]; };
struct Obj_002959D8;
extern "C" int func_00294AE0(Board_002959D8* b);
extern "C" int func_00294C48(Board_002959D8* b);
extern "C" char* func_00291EE0(unsigned int type, int v);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7360(void* s, unsigned int name, unsigned int v);
extern "C" void func_001E70C0(void* s, unsigned int name, char* v);
extern "C" void func_001F0210(unsigned int, void*, int, int, int);
extern "C" void func_00295B20(Obj_002959D8* self);
extern "C" void func_001E6AE8(void* p, int v);
extern char D_00377350[];
extern char D_00377458[];

struct Obj_002959D8 {
    char pad0[0xC];
    int mC;
    char pad1[0xA5C0 - 0x10];
    Board_002959D8* mA5C0;
    void Refresh();
};

void Obj_002959D8::Refresh()
{
    char* name;
    switch (func_00294AE0(mA5C0)) {
    case 2:
        name = D_00377350;
        break;
    case 3:
        {
            Board_002959D8* b = mA5C0;
            unsigned int type = b->m114;
            name = func_00291EE0(type, func_00294C48(b));
        }
        break;
    default:
        name = D_00377458;
        break;
    }
    Struct_002959D8 s;
    func_001E6978(&s);
    if (func_00294AE0(mA5C0) == 1) {
        func_001E7360(&s, 0x7321A8D6, 0x061A741E);
    } else {
        func_001E7360(&s, 0x7321A8D6, 0);
        func_001E70C0(&s, 0x286A8D26, name);
    }
    func_001F0210(0x36791E3C, &s, mC, 0, 0);
    func_00295B20(this);
    func_001E6AE8(&s, 2);
}
