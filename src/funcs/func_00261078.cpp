struct C_00261078 {
    int m0;
    char m4[0x58];
    char m5C[4];
};

extern "C" void func_0011F880(void* p);
extern "C" void func_001E6978(void* p);
extern "C" void func_00261118(C_00261078* self, int a);

extern "C" C_00261078* func_00261078(C_00261078* self)
{
    func_0011F880(self->m4);
    func_001E6978(self->m5C);
    func_00261118(self, 0);
    return self;
}
