/* sym: _vt$12Obj_0014C910 = 0x0035F548 */
/* sym: __13Base_0014C910 = 0x0013CB68 */
struct Base_0014C910 {
    char m_data[0x1B8];
    Base_0014C910();
    virtual ~Base_0014C910();
};

struct Obj_0014C910 : Base_0014C910 {
    int m_1BC;
    int m_1C0;
    Obj_0014C910();
    virtual void Update();
    virtual ~Obj_0014C910();
};

Obj_0014C910::Obj_0014C910()
{
    m_1C0 = 0;
}
