struct Array_00245918 {
    int m0;
    int m4;
    int m8;
    unsigned int m_size;
    unsigned int GetSize() const { return m_size; }
};

struct Goal_00245918 {
    char m_pad[0x20];
    void* m_params;
    char m_pad24[0x60 - 0x24];
    int m60;
};

extern "C" bool func_001E8248(void* params, unsigned int name, Array_00245918** out, int assert_);
extern "C" void* func_001E9378(Array_00245918* self, unsigned int index);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int assert_);
extern "C" bool func_00245748(Goal_00245918* self, unsigned int flag, int a);
extern "C" void func_00245430(Goal_00245918* self);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int assert_);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void func_00244600(Goal_00245918* self, int value);
extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern "C" void func_00244530(Goal_00245918* self);
extern "C" unsigned int func_00246258(Goal_00245918* self);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" void func_001E6D18(void* params, unsigned int name);
extern "C" void* func_001F0750(unsigned int script, void* params, void* object, int a, int b, int c, int d, int e, int f, int g);

bool func_00245918(Goal_00245918* self)
{
    Array_00245918* list;
    if (!func_001E8248(self->m_params, 0x160B3220, &list, 0)) {
        func_001E8248(self->m_params, 0x92C6E839, &list, 1);
    }
    for (unsigned int i = 0; i < list->GetSize(); i++) {
        void* elem = func_001E9378(list, i);
        unsigned int flag;
        func_001E8398(elem, 0x2E0B1465, &flag, 1);
        if (!func_00245748(self, flag, 1)) {
            func_00245430(self);
            int time;
            func_001E7DE8(elem, 0x906B67BA, &time, 1);
            if (func_001E8708(self->m_params, 0xFB11CB01)) {
                func_00244600(self, time);
            } else {
                func_001E7200(self->m_params, 0x906B67BA, time);
                func_00244530(self);
            }
            func_001E7360(elem, 0x9982E501, func_00246258(self));
            if (!self->m60) {
                func_001E7360(elem, 0, 0xB13F3AB8);
            }
            if (func_001E8708(self->m_params, 0x38221DF4)) {
                func_001E7360(elem, 0, 0x38221DF4);
            } else {
                func_001E6D18(elem, 0x38221DF4);
            }
            if (func_001E8708(self->m_params, 0x9D65D0E7)) {
                func_001F0750(0x681BC776, elem, 0, 0, -1, 0, 0, 0, 0, 0);
            } else {
                func_001F0750(0x4C938553, elem, 0, 0, -1, 0, 0, 0, 0, 0);
            }
            func_001E6D18(elem, 0x38221DF4);
            return true;
        }
    }
    return true;
}
