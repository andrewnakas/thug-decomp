/* sym: _vt$12Obj_0027A180 = 0x00376C58 */
/* sym: _$_13Base_0027A180 = 0x00184DD8 */
struct Ref_0027A180;
struct Handle_0027A180;

extern "C" void func_00183CB8(Ref_0027A180* o, Handle_0027A180* h);
extern "C" void func_001DADB0(void* p);

struct Handle_0027A180 {
    Ref_0027A180* m_obj;
    Handle_0027A180* m_prev;
    Handle_0027A180* m_next;
    ~Handle_0027A180()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
};

struct Base_0027A180 {
    int m_pad[6];
    virtual ~Base_0027A180();
};

struct Obj_0027A180 : Base_0027A180 {
    char pad1C[0x170 - 0x1C];
    Handle_0027A180 m170;
    char pad17C[0x250 - 0x17C];
    Handle_0027A180 m250;
    char pad25C[0x3C8 - 0x25C];
    Handle_0027A180 m3C8;
    char pad3D4[0x590 - 0x3D4];
    void* m590;
    virtual void Update();
    virtual ~Obj_0027A180();
};

Obj_0027A180::~Obj_0027A180()
{
    func_001DADB0(m590);
}
