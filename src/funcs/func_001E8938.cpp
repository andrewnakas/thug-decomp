extern "C" void func_001E7F50(void* self, void* a, void* b, bool flag);

struct Obj_001E8938 {
    void SetFlagged(void* a, void* b, int flag);
};

void Obj_001E8938::SetFlagged(void* a, void* b, int flag)
{
    func_001E7F50(this, a, b, flag != 0);
}
