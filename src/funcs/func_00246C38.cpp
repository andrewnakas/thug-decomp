extern "C" int func_001E8618(void* p, unsigned int name);

struct Obj_00246C38 {
    char pad0[0x20];
    void* m20;
    int Get();
};

int Obj_00246C38::Get()
{
    return func_001E8618(m20, 0xD303A1A3);
}
