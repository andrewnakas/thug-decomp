/* force: {"kind": "fr", "reg": 118, "hard": 20} */
/* force: {"kind": "reorg", "uid": 39, "pred": 1} */
/* force: {"kind": "reorg", "uid": 110, "pred": 1} */
/* force: {"kind": "sched", "pass": 2, "block": 1, "clock": 1, "first": [46, 44]} */
/* force: {"kind": "sched", "pass": 2, "block": 6, "clock": 1, "first": [117, 115]} */
/* sym: __14Sound_0018C0A8ii = 0x00120168 */
/* sym: _$_14Sound_0018C0A8 = 0x00183D80 */

typedef int qword_0018C0A8 __attribute__((mode(TI)));

struct Vec_0018C0A8 {
    union {
        struct {
            float x, y, z, w;
        };
        qword_0018C0A8 q;
    };
};

struct Owner_0018C0A8 {
    char pad0[0x104];
    unsigned int m_flags;
};

class Sound_0018C0A8 {
public:
    char m[0x50];
    Sound_0018C0A8(int a, int b);
    ~Sound_0018C0A8();
};

extern "C" void* func_00185578(Owner_0018C0A8* o, unsigned int key);
extern "C" void* func_0019EBD0(void* p, int a);
extern "C" void func_001201C0(Sound_0018C0A8* s, int a, void* scene, void* x, unsigned int key);
extern "C" void func_0018DC18(void* comp, void* scene);
extern "C" Vec_0018C0A8 func_0013EF90(void* scene);

class Comp_0018C0A8 {
public:
    char pad0[0xC];
    Owner_0018C0A8* m_owner;
    char pad10[0x10];
    Vec_0018C0A8 m20;
    char pad30[0x230];
    void* m_scene;

    void Play(int a, int b, int c, unsigned int key);
};

void Comp_0018C0A8::Play(int a, int b, int c, unsigned int key)
{
    void* scene = m_scene;
    void* x = 0;
    void* r = func_00185578(m_owner, 0x222756D5);
    if (r) {
        x = func_0019EBD0(r, b);
    }
    Sound_0018C0A8 snd(b, c);
    if (key) {
        func_001201C0(&snd, a, scene, x, key);
    } else {
        func_001201C0(&snd, a, scene, x, 0x91C1EC93);
    }
    if (m_owner->m_flags & 0x20) {
        func_0018DC18(this, scene);
    }
    m20 = func_0013EF90(scene);
}
