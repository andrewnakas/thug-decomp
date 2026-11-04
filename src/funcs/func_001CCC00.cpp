/* sym: __13Coll_001CCC00 = 0x00209240 */
typedef int qword __attribute__((mode(TI)));

struct Vec_001CCC00 {
    union {
        float col[4];
        qword q;
    };
    Vec_001CCC00() {}
    Vec_001CCC00(float ax, float ay, float az, float aw)
    {
        col[0] = ax;
        col[1] = ay;
        col[2] = az;
        col[3] = aw;
    }
    float& operator[](int i) { return col[i]; }
    const float& operator[](int i) const { return col[i]; }
};

static inline Vec_001CCC00 operator+(const Vec_001CCC00& a, const Vec_001CCC00& b)
{
    return Vec_001CCC00(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}

static inline Vec_001CCC00 operator*(const Vec_001CCC00& a, float s)
{
    return Vec_001CCC00(a[0] * s, a[1] * s, a[2] * s, a[3] * s);
}

struct Link_001CCC00;
extern "C" void func_00183CB8(void* list, Link_001CCC00* node);

struct Link_001CCC00 {
    void* m_list;
    ~Link_001CCC00()
    {
        if (m_list) {
            func_00183CB8(m_list, this);
            m_list = 0;
        }
    }
};

class Coll_001CCC00 {
public:
    char pad0[0xC0];
    Link_001CCC00 m_link;
    char padC4[0xE0 - 0xC4];
    Coll_001CCC00();
};

struct Pmf_001CCC00 {
    short delta;
    short index;
    void* func;
};

extern Pmf_001CCC00 D_0038D828[];
extern Pmf_001CCC00 D_0038D830[];

extern "C" void* func_001E5548(unsigned int crc, int a);
extern "C" int func_001E7EB0(void* s, unsigned int crc, float* out, int a);

struct Self_001CCC00;
extern "C" bool func_001C6458(Self_001CCC00* self, Vec_001CCC00* a, Vec_001CCC00* b, Coll_001CCC00* c);
extern "C" void func_0019C9D8(void* p, Coll_001CCC00* c);
extern "C" void func_001C4210(Self_001CCC00* self, Vec_001CCC00* v, float f);
extern "C" void func_001BF130(Self_001CCC00* self, int a);

struct Self_001CCC00 {
    char pad0[0x30];
    Vec_001CCC00 m_pos;
    char pad40[0x60 - 0x40];
    Vec_001CCC00 m_vel;
    char pad70[0x90 - 0x70];
    unsigned int m_state;
    char pad94[0xC4 - 0x94];
    float mC4;
    char padC8[0xA50 - 0xC8];
    Vec_001CCC00 mA50;
    char padA60[0xA70 - 0xA60];
    char mA70[0xB20 - 0xA70];
    Vec_001CCC00 mB20;
    char padB30[0xB50 - 0xB30];
    int mB50;
    char padB54[0xBD0 - 0xB54];
    Vec_001CCC00 mBD0;
    char padBE0[0xBE4 - 0xBE0];
    float mBE4;
    char padBE8[0xC10 - 0xBE8];
    Vec_001CCC00 mC10;
    char padC20[0xC30 - 0xC20];
    Vec_001CCC00 mC30;
    float mC40;
    int mC44;
    char padC48[0xC80 - 0xC48];
    int mC80;
    Pmf_001CCC00 mC84;

    void Start();
};

void Self_001CCC00::Start()
{
    float scale;
    func_001E7EB0(func_001E5548(0x6775E538, 0), 0xB620B580, &scale, 1);
    Vec_001CCC00 pos = m_pos + m_vel * scale;
    float lift;
    func_001E7EB0(func_001E5548(0x6775E538, 0), 0x76BF49E0, &lift, 1);
    pos[1] += lift;
    Coll_001CCC00 coll;
    bool hit = func_001C6458(this, &pos, &pos, &coll);
    mC10.q = m_pos.q;
    mC30.q = pos.q;
    if (hit) {
        mC84 = D_0038D828[0];
        func_0019C9D8(mA70, &coll);
        mB50 = 1;
        mA50 = mB20;
    } else {
        mC84 = D_0038D830[0];
    }
    mC44 = 0;
    mC40 = mC4;
    func_001C4210(this, &m_vel, 1.0f);
    mC80 = 1;
    mBD0 = m_vel;
    mBE4 = pos[1];
    func_001BF130(this, 4);
    m_state = 0x12521BFB;
}
