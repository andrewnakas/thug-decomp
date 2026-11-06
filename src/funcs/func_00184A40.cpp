struct Heap_00184A40 {
    char pad[0xEC];
    int mEC;
};

extern Heap_00184A40* D_00388A70;
extern "C" void func_0010A950(void* heap, int v);
extern "C" void func_0010A9B0(void* heap);
extern "C" void* func_00121960(int size);
extern "C" void* func_001EE428(void* p);
extern "C" void func_001EE8C8(void* track, unsigned int key, int a, void* owner);

class Obj_00184A40 {
public:
    char pad0[0x14];
    void* m_track;

    void CreateTrack();
};

void Obj_00184A40::CreateTrack()
{
    if (m_track) {
        return;
    }
    func_0010A950(D_00388A70, D_00388A70->mEC);
    m_track = func_001EE428(func_00121960(0xF4));
    func_001EE8C8(m_track, 0x3F5CDB8A, 0, this);
    func_0010A9B0(D_00388A70);
}
