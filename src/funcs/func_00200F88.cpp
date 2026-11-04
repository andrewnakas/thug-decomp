/* sym: _vt$13Iter_00200F88 = 0x00366B58 */
class Iter_00200F88 {
public:
    void* m_node;
    int m_index;
    Iter_00200F88() : m_index(0) {}
    virtual void Run();
    virtual ~Iter_00200F88() {}
};

struct Entry_00200F88;

class Mgr_00200F88 {
public:
    char pad0[0x429C];
    int m_sema;
    char pad42A0[0xB8];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void Visit(Entry_00200F88* e);

    void VisitAll();
};

extern "C" int func_0031BCE0(int sema);
extern "C" int func_0031BCC0(int sema);
extern "C" Entry_00200F88* func_00200EC0(Mgr_00200F88* self, Iter_00200F88* it);
extern "C" Entry_00200F88* func_00200EF8(Mgr_00200F88* self, Iter_00200F88* it);

void Mgr_00200F88::VisitAll()
{
    Iter_00200F88 it;
    func_0031BCE0(m_sema);
    for (Entry_00200F88* e = func_00200EC0(this, &it); e; e = func_00200EF8(this, &it))
        Visit(e);
    func_0031BCC0(m_sema);
}
