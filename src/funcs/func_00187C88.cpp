/* sym: _$_14Sound_00187C88 = 0x001E6AE8 */

extern void* D_00388A70;
extern "C" void func_0010A8D8(void* heap, void* p);

class Sound_00187C88 {
public:
    ~Sound_00187C88();
};

class Ref_00187C88 {
public:
    int m0;
    int m4;
    int m8;
    unsigned int m_flags;
    Sound_00187C88* m_sound;

    ~Ref_00187C88();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Ref_00187C88::~Ref_00187C88()
{
    if (m_flags & 4) {
        delete m_sound;
    }
}
