extern "C" void func_001E8248(void* self, void* a, void* b, bool flag);

struct Obj_001E8A80 {
    void SetFlagged(void* a, void* b, int flag);
};

void Obj_001E8A80::SetFlagged(void* a, void* b, int flag)
{
    func_001E8248(this, a, b, flag != 0);
}
