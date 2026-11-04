struct Params_0023B4A0;

extern "C" void* func_001190D0(unsigned int size);
extern "C" Params_0023B4A0* func_001E6978(void* mem);

struct Obj_0023B4A0 {
    int m_0;
    char m_4[0x18];
    Params_0023B4A0* m_1C;
    int m_20;
    int pad24;
    int m_28;
    int m_2C;
    int m_30;
    int m_34;
    int pad38;
    int m_3C;
    int m_40;
    int m_44;
    int m_48;
    int m_4C;
    int m_50;
    Params_0023B4A0* m_54;
    int pad58;
    Params_0023B4A0* m_5C;
};

extern "C" void func_00243A58(void* list, int a);

Obj_0023B4A0* func_0023B4A0(Obj_0023B4A0* self)
{
    func_00243A58(self->m_4, 0);
    self->m_20 = 0;
    self->m_28 = 0;
    self->m_2C = 0;
    self->m_30 = 0;
    self->m_34 = 0;
    self->m_3C = 0;
    self->m_40 = 0;
    self->m_48 = 0;
    self->m_4C = 0;
    self->m_50 = 0;
    self->m_44 = 1;
    self->m_54 = func_001E6978(func_001190D0(8));
    self->m_1C = func_001E6978(func_001190D0(8));
    self->m_5C = func_001E6978(func_001190D0(8));
    return self;
}
