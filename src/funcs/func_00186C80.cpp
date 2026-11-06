/* sym: _vt$12Mgr_00186C80 = 0x00361AB8 */
/* sym: _$_13Base_00186C80 = 0x00187800 */

extern "C" void func_001048F0(void* task);

class Task_00186C80 {
public:
    char pad[0x18];
    virtual void V1();
    virtual void V2();
    virtual ~Task_00186C80();
};

class Base_00186C80 {
public:
    char pad0[0x2C];
    virtual ~Base_00186C80();
};

class Mgr_00186C80 : public Base_00186C80 {
public:
    char pad30[0x1C];
    Task_00186C80* m_task;

    virtual void Key();
    virtual ~Mgr_00186C80();
};

Mgr_00186C80::~Mgr_00186C80()
{
    if (m_task) {
        func_001048F0(m_task);
        delete m_task;
    }
}
