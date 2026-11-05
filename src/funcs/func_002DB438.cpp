/* sym: _vt$12Obj_002DB438 = 0x0037CA48 */
struct Base_002DB438 {
    int m0;
    Base_002DB438* m4;
    int m8;
    Base_002DB438* mC;
    Base_002DB438* m10;
    virtual void Run();
};

struct Obj_002DB438 : Base_002DB438 {
    char pad18[0x38 - 0x18];
    int m38;
    int m3C;
    Obj_002DB438();
    virtual void Run();
};

Obj_002DB438::Obj_002DB438()
{
    m4 = this;
    m8 = 0;
    mC = this;
    m10 = this;
    m3C = 0;
    m38 = 0;
}
