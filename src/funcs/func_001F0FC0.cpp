struct Heap_001F0FC0 {
    char pad0[0xE4];
    void* m_E4;
};

struct Anim_001F0FC0;

extern Heap_001F0FC0* D_00388A70;

extern "C" void func_0010A950(Heap_001F0FC0* mgr, void* heap);
extern "C" void func_0010A9B0(Heap_001F0FC0* mgr);
extern "C" void* func_0010A638(Heap_001F0FC0* heap, int size, int a, int b);
extern "C" Anim_001F0FC0* func_00187EC0(void* mem);

struct Obj_001F0FC0 {
    char pad0[0xDC];
    Anim_001F0FC0* m_anim;

    void Play(int anim, int loop);
};

extern "C" void func_00188BA8(Anim_001F0FC0* a, Obj_001F0FC0* o);
extern "C" void func_001881B8(Anim_001F0FC0* a, int anim, bool loop);
extern "C" void func_00188620(Anim_001F0FC0* a);
extern "C" void func_00188B08(Anim_001F0FC0* a, Obj_001F0FC0* o);

void Obj_001F0FC0::Play(int anim, int loop)
{
    func_0010A950(D_00388A70, D_00388A70->m_E4);
    if (!m_anim)
        m_anim = func_00187EC0(func_0010A638(D_00388A70, 0x14, 1, 0));
    else
        func_00188BA8(m_anim, this);
    func_001881B8(m_anim, anim, loop != 0);
    func_00188620(m_anim);
    func_00188B08(m_anim, this);
    func_0010A9B0(D_00388A70);
}
