extern "C" bool func_001E8708(void* p, unsigned int name);

struct Obj_00246718 {
    char pad0[0x20];
    void* m20;
    bool Get();
};

bool Obj_00246718::Get()
{
    return !func_001E8708(m20, 0xA612F12C);
}
