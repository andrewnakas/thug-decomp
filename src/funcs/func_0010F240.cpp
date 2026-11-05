/* sym: _$_13Base_0010F240 = 0x00182A10 */
/* sym: _vt$12Obj_0010F240 = 0x0035BAC8 */
class Base_0010F240 {
public:
    char pad[0x14];
    virtual ~Base_0010F240();
};

class Task_0010F240 {
public:
    int m0;
    int m4;
    void* m8;
    int mC;
    int m10;
    int m14;
    virtual void Func1() = 0;
    virtual void Func2() = 0;
    virtual ~Task_0010F240();
};

class Obj_0010F240 : public Base_0010F240 {
public:
    Task_0010F240* m_task;
    virtual void Run();
    virtual ~Obj_0010F240();
};

Obj_0010F240::~Obj_0010F240()
{
    if (m_task) {
        delete m_task;
    }
}
