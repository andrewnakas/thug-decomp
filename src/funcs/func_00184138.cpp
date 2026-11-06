/* sym: _$_14Sound_00184138 = 0x001E6AE8 */

struct Set_00184138 {
    char pad0[0xC];
    unsigned int m_count;
};

class Sound_00184138 {
public:
    ~Sound_00184138();
};

extern "C" int func_001E9300(Set_00184138* set, unsigned int i);
extern "C" void func_001E6B90(Sound_00184138* s, int id);
extern "C" void func_001E6D18(Sound_00184138* s, int id);
extern "C" int func_001E6DC0(Sound_00184138* s);

class Obj_00184138 {
public:
    char pad0[0x24];
    Sound_00184138* m_sound;

    void Remove(Set_00184138* set);
};

void Obj_00184138::Remove(Set_00184138* set)
{
    if (!m_sound) {
        return;
    }
    for (unsigned int i = 0; i < set->m_count; i++) {
        int id = func_001E9300(set, i);
        func_001E6B90(m_sound, id);
        func_001E6D18(m_sound, id);
    }
    if (func_001E6DC0(m_sound)) {
        delete m_sound;
        m_sound = 0;
    }
}
