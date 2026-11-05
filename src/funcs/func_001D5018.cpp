extern char D_00364180[];

struct C_001D5018 {
    char m_pad[0xC];
    char* mC;
};

extern "C" void func_001D33B8(C_001D5018* self);

extern "C" C_001D5018* func_001D5018(C_001D5018* self)
{
    func_001D33B8(self);
    self->mC = D_00364180;
    return self;
}
