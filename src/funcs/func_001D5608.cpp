extern char D_00363F90[];

struct C_001D5608 {
    char m_pad[0xC];
    char* mC;
};

extern "C" void func_001D5018(C_001D5608* self);

extern "C" C_001D5608* func_001D5608(C_001D5608* self)
{
    func_001D5018(self);
    self->mC = D_00363F90;
    return self;
}
