/* sym: _vt$13Iter_001FE018 = 0x00366B58 */
class Iter_001FE018 {
public:
    void* m_node;
    int m_index;
    Iter_001FE018() : m_index(0) {}
    virtual void Run();
    virtual ~Iter_001FE018() {}
};

struct Entry_001FE018 {
    char pad0[0x20EC];
    char m_inQueue[0x1410];
    char m_outQueue[4];
};

struct Mgr_001FE018 {
    int m_time;
};

extern "C" Entry_001FE018* func_00200EC0(Mgr_001FE018* self, Iter_001FE018* it);
extern "C" Entry_001FE018* func_00200EF8(Mgr_001FE018* self, Iter_001FE018* it);
extern "C" void func_001F94D0(void* q, int time);

struct Obj_001FE018 {
    char pad0[0x20];
    Mgr_001FE018* m_mgr;

    void Update();
};

void Obj_001FE018::Update()
{
    Iter_001FE018 it;
    Mgr_001FE018* mgr = m_mgr;
    for (Entry_001FE018* e = func_00200EC0(mgr, &it); e; e = func_00200EF8(mgr, &it)) {
        func_001F94D0(e->m_inQueue, mgr->m_time);
        func_001F94D0(e->m_outQueue, mgr->m_time);
    }
}
