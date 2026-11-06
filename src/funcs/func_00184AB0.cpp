extern "C" void* func_00121960(int size);
extern "C" void* func_001EE428(void* p);
extern "C" void func_001EE8C8(void* track, unsigned int key, int a, void* owner);
extern "C" void func_001EE620(void* track);

class Obj_00184AB0 {
public:
    char pad0[0x14];
    void* m_track;

    void PlayTrack(unsigned int key, int a);
};

void Obj_00184AB0::PlayTrack(unsigned int key, int a)
{
    if (m_track) {
        func_001EE8C8(m_track, key, a, this);
    } else {
        m_track = func_001EE428(func_00121960(0xF4));
        func_001EE8C8(m_track, key, a, this);
    }
    func_001EE620(m_track);
}
