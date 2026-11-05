extern "C" void* func_00229DF0(void* node);
extern "C" void func_00229FF8(void* params, void* pos);
extern "C" int func_00229EB0(void* list);

struct Obj_00259428 {
    char pad[0x74];
    void* m74;
    char pad78[0x18];
    char m90[0x34];
    int mC4;
    void Fn();
};

void Obj_00259428::Fn()
{
    func_00229FF8(func_00229DF0(m74), m90);
    if (!func_00229EB0(m74)) mC4 |= 2;
    else mC4 &= ~2;
}
