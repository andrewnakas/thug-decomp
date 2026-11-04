extern "C" void func_00104C70(void* list);
extern "C" void func_001052C0(void* self);

struct Obj105288 {
    char pad[0x40];
    void* m40;
    int m44;
    void Process();
};

void Obj105288::Process()
{
    if (m44) {
        func_001052C0(this);
    } else {
        func_00104C70(m40);
    }
}
