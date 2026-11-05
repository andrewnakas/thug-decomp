struct Mgr_0023D160 {
    void Call(int id);
};

extern "C" void* func_0023BAD8(Mgr_0023D160* self, int id, int create);
extern "C" void func_0024BC40(void* item, int id);

void Mgr_0023D160::Call(int id)
{
    func_0024BC40(func_0023BAD8(this, id, 1), id);
}
