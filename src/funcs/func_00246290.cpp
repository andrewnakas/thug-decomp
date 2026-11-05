extern "C" int func_001E8708(void* p, unsigned int name);

struct Obj_00246290 {
    char pad0[0x20];
    void* m20;
    int Get();
};

int Obj_00246290::Get()
{
    return func_001E8708(m20, 0x981D3AD0);
}
