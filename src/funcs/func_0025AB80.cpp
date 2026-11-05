extern char D_00375630[];

struct C_0025AB80 {
    char m_pad[0x14];
    char* m14;
    char m18[0x24];
    int m3C;
    char m40[4];
};

extern "C" C_0025AB80* func_0025A878(C_0025AB80* self);
extern "C" void func_00119690(void* p);

extern "C" C_0025AB80* func_0025AB80(C_0025AB80* self)
{
    func_0025A878(self);
    self->m14 = D_00375630;
    func_00119690(self->m40);
    self->m3C = 0;
    return self;
}
