extern "C" void func_00104C70(void* list);

struct Obj1052C0 {
    char pad[0x3C];
    void* m3C;
    void Process();
};

void Obj1052C0::Process()
{
    func_00104C70(m3C);
}
