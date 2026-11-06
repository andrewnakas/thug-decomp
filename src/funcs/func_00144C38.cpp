/* sym: __12Tab_00144C38 = 0x00144E10 */
/* sym: _vt$12Obj_00144C38 = 0x0035EE08 */
struct Tab_00144C38 {
    char data[0xA00];
    Tab_00144C38();
};

class Obj_00144C38 {
public:
    int m0;
    void* m4;
    void* m8;
    Tab_00144C38 mC;
    int mA0C;
    char padA10[0x8];
    Obj_00144C38();
    virtual void Update();
};

Obj_00144C38::Obj_00144C38()
{
    m4 = 0;
    mA0C = 0;
}
