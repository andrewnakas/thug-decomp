struct Park_002CB8F8;
struct Obj_002CB8F8 {
    char pad0[0x18];
    void* m18;
};
extern "C" Park_002CB8F8* func_002C0368();
extern "C" int func_002BD248(Park_002CB8F8* p);
extern "C" void func_001E7200(void* params, unsigned int name, int value);

bool func_002CB8F8(void* params, Obj_002CB8F8* o)
{
    void* p = o->m18;
    func_001E7200(p, 0x688A18F7, func_002BD248(func_002C0368()));
    return true;
}
