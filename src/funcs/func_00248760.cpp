extern "C" int func_001E8708(void* p, unsigned int name);

struct Obj_00248760 {
    char pad0[0x20];
    void* m20;
    int Get();
};

int Obj_00248760::Get()
{
    return func_001E8708(m20, 0xF8E31760);
}
