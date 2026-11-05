/* sym: __13Parm_0024EE78 = 0x001E6978 */
/* sym: _vt$13Node_0024EE78 = 0x00374978 */
/* sym: _vt$12Obj_0024EE78 = 0x00374960 */
struct Obj_0024EE78;
extern "C" int func_0024FA38(Obj_0024EE78* self);

struct Parm_0024EE78 {
    int m0;
    int m4;
    Parm_0024EE78();
};

struct Link_0024EE78 {
    int m0;
    unsigned int m4;
    int m8;
    Link_0024EE78* mC;
    Link_0024EE78* m10;
    Link_0024EE78()
    {
        m8 = 0;
        mC = this;
        m10 = this;
    }
};

struct Node_0024EE78 : Link_0024EE78 {
    virtual void V0();
    Node_0024EE78()
    {
        m4 = 0xFFFFFFFF;
    }
};

struct Obj_0024EE78 {
    int m0;
    Parm_0024EE78 m4;
    Node_0024EE78 mC;
    Obj_0024EE78();
    virtual void V0();
};

Obj_0024EE78::Obj_0024EE78()
{
    func_0024FA38(this);
}
