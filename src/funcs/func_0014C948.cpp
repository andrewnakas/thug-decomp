/* sym: _$_13Mesh_0014C948 = 0x0013CC18 */
/* sym: _vt$13Sprt_0014C948 = 0x0035F548 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

class Mesh_0014C948 {
public:
    char pad0[0x1B8];
    virtual ~Mesh_0014C948();
    virtual void V1();
};

class Sprt_0014C948 : public Mesh_0014C948 {
public:
    int m1BC;
    void* m1C0;
    virtual void V1();
    virtual ~Sprt_0014C948();
};

Sprt_0014C948::~Sprt_0014C948()
{
    if (m1C0) {
        func_0010A8D8(D_00388A70, m1C0);
        m1C0 = 0;
    }
}
