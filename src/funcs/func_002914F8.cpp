struct Params_002914F8;

extern "C" void* func_001190D0(int size);
extern "C" Params_002914F8* func_001E6978(void* mem);
extern "C" void func_001E6B30(Params_002914F8* p);
extern "C" void func_001E6AC8(Params_002914F8* p, void* src);

struct Obj_002914F8 {
    char pad[0x24];
    Params_002914F8* m24;
    void SetParams(void* src);
};

void Obj_002914F8::SetParams(void* src)
{
    if (!m24)
        m24 = func_001E6978(func_001190D0(8));
    func_001E6B30(m24);
    func_001E6AC8(m24, src);
}
