struct Ctrl_001CDE28 {
    int CallMember(unsigned int id);
};

extern "C" void func_001CDF30(Ctrl_001CDE28* self);
extern "C" void func_001CDF70(Ctrl_001CDE28* self);

int Ctrl_001CDE28::CallMember(unsigned int id)
{
    switch (id) {
    case 0x73FEBD0F:
        func_001CDF30(this);
        return 1;
    case 0xD1A485D1:
        func_001CDF70(this);
        return 1;
    }
    return 2;
}
