extern "C" void func_001E7D18(void* self, void* a, void* b, bool flag);

struct Obj_001E8890 {
    void SetFlagged(void* a, void* b, int flag);
};

void Obj_001E8890::SetFlagged(void* a, void* b, int flag)
{
    func_001E7D18(this, a, b, flag != 0);
}
