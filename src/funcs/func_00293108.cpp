struct Struct_00293108 { char pad[0x10]; };
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_001E73C8(void* p, char* s, int v);
extern "C" void func_001F0370(char*, void*, int, int);
extern char D_00391DD0[];
extern char D_003773A0[];

struct Obj_00293108;
extern "C" int func_00292E88(Obj_00293108*, int);

struct Obj_00293108 {
    void Fire(int i);
};

void Obj_00293108::Fire(int i)
{
    Struct_00293108 s;
    func_001E6978(&s);
    func_001E73C8(&s, D_00391DD0, func_00292E88(this, i));
    func_001F0370(D_003773A0, &s, 0, 0);
    func_001E6AE8(&s, 2);
}
