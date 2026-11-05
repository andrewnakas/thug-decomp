extern "C" void func_002660C8(void* p);
extern "C" void func_002668B0(void* list, void (*fn)(void*), int a);
extern "C" void func_00266790(void* list);

struct Obj_00266100 {
    int m0;
    int m4;
    int m8[6];
    int m20[6];
    bool Clear();
};

bool Obj_00266100::Clear()
{
    func_002668B0(m8, func_002660C8, 0);
    func_00266790(m8);
    m4 = 0;
    func_00266790(m20);
    return true;
}
