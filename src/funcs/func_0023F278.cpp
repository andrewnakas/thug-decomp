struct Mgr_0023F278 {
    void Call(int id, int a, int b);
};

extern "C" void* func_0023BAD8(Mgr_0023F278* self, int id, int create);
extern "C" void func_00248270(void* item, int a, int b);

void Mgr_0023F278::Call(int id, int a, int b)
{
    func_00248270(func_0023BAD8(this, id, 1), a, b);
}
