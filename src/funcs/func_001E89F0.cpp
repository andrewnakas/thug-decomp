extern "C" void func_001E8180(void* self, void* a, void* b, bool flag);

struct Obj_001E89F0 {
    void SetFlagged(void* a, void* b, int flag);
};

void Obj_001E89F0::SetFlagged(void* a, void* b, int flag)
{
    func_001E8180(this, a, b, flag != 0);
}
