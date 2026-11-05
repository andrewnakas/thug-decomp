/* sym: _vt$12Obj_002C9F00 = 0x0037AE48 */
struct Mgr_002C9F00;
extern "C" Mgr_002C9F00* func_002BA990(int create);

struct Base_002C9F00 {
    int m0;
    int m4;
    Mgr_002C9F00* m8;
    virtual void Update();
    virtual void Draw();
};

struct Obj_002C9F00 : Base_002C9F00 {
    int m10;
    int m14;
    int m18;
    Obj_002C9F00();
    virtual void Update();
};

Obj_002C9F00::Obj_002C9F00()
{
    m8 = func_002BA990(0);
    m10 = 0;
    m18 = 0;
    m14 = 0;
}
