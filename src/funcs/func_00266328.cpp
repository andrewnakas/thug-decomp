extern "C" void func_001E6B30(void* s);
extern "C" void func_001E6A50(void* s, void* src);

struct Obj_00266328 {
    char pad[0x38];
    void* m38;
    void SetParams(void* src);
};

void Obj_00266328::SetParams(void* src)
{
    func_001E6B30(m38);
    if (src)
        func_001E6A50(m38, src);
}
