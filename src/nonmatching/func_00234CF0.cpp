/* fuzzy: 85.7 */
typedef int qword __attribute__((mode(TI)));
union Vec_00234CF0 {
    qword q;
    struct {
        float x, y, z, w;
    };
    float c[4];
    Vec_00234CF0() {}
    Vec_00234CF0(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    Vec_00234CF0& operator=(const Vec_00234CF0& o)
    {
        q = o.q;
        return *this;
    }
    Vec_00234CF0 operator-(const Vec_00234CF0& b) const
    {
        return Vec_00234CF0(x - b.x, y - b.y, z - b.z, w - b.w);
    }
};


struct Mat_00234CF0 {
    qword row[4];
    Mat_00234CF0& operator=(const Mat_00234CF0& o)
    {
        row[0] = o.row[0];
        row[1] = o.row[1];
        row[2] = o.row[2];
        row[3] = o.row[3];
        return *this;
    }
};

struct Bits_00234CF0 {
    int m[12];
};

// One received network snapshot of a remote skater.
struct Frame_00234CF0 {
    short m_pos[3];
    char pad6[0x10 - 0x6];
    Mat_00234CF0 m_mat;
    Vec_00234CF0 m_posF;
    float m_rot[3];
    char pad6C[0x70 - 0x6C];
    int m_70;
    int m_74;
    int m_78;
    char m_7C;
    char m_7D;
    char m_7E;
    char pad7F;
    unsigned short m_time;
    unsigned short m_wrap;
    int m_84;
    short m_88;
    char pad8A[0x90 - 0x8A];
};

struct History_00234CF0 {
    char pad0[0x1C];
    int m_count;
    Frame_00234CF0 m_frame[20];
};

struct Skater_00234CF0 {
    char pad0[0x50];
    Vec_00234CF0 m_pos;
    char pad60[0x70 - 0x60];
    Mat_00234CF0 m_mat;
    char padB0[0x2DC - 0xB0];
    History_00234CF0* m_history;
};

struct Msg_00234CF0 {
    void* m_data;
    char pad4[0x18 - 0x4];
    unsigned int m_flags;
    void* m_game;
};

extern "C" void func_001FAA08(Bits_00234CF0* b);
extern "C" void func_001FAA28(Bits_00234CF0* b, void* data, int size);
extern "C" unsigned int func_001FAB88(Bits_00234CF0* b, int bits);
extern "C" int func_001FAC80(Bits_00234CF0* b, int bits);
extern "C" void* func_0022E040(void* game);
extern "C" Skater_00234CF0* func_00187B48(void* mgr, unsigned int id);
extern "C" Mat_00234CF0* func_00100200(Mat_00234CF0* m, float x, float y, float z);
extern "C" void func_00100498(Mat_00234CF0* m, Vec_00234CF0* out);

extern "C" int func_00234CF0(Msg_00234CF0* msg)
{
    Bits_00234CF0 bits;
    Vec_00234CF0 posF;
    Mat_00234CF0 m;
    float rot[3];
    short pos[3];
    Mat_00234CF0 mat;
    Vec_00234CF0 ang;
    unsigned char i = 0;

    func_001FAA08(&bits);
    void* game = msg->m_game;
    func_001FAA28(&bits, msg->m_data, 0x400);
    unsigned char mask = func_001FAB88(&bits, 8);
    do {
        if ((mask >> i) & 1) {
            char f7C;
            char f78;
            signed char f84;
            char f7D;
            char f7E;
            int f70;
            int f74;
            short f88;
            unsigned short time = func_001FAB88(&bits, 16);
            f7C = 0;
            f78 = 0;
            unsigned int flags = func_001FAB88(&bits, 9);
            f84 = 0;
            f70 = f7C;
            f74 = f7C;
            f7D = 0;
            f7E = 0;
            f88 = -1;
            if (flags & 1)
                pos[0] = func_001FAC80(&bits, 16);
            if (flags & 2)
                pos[1] = func_001FAC80(&bits, 16);
            if (flags & 4)
                pos[2] = func_001FAC80(&bits, 16);
            if (flags & 8)
                rot[0] = (short)func_001FAC80(&bits, 16) * (1.0f / 4096.0f);
            if (flags & 0x10)
                rot[1] = (short)func_001FAC80(&bits, 16) * (1.0f / 4096.0f);
            if (flags & 0x20)
                rot[2] = (short)func_001FAC80(&bits, 16) * (1.0f / 4096.0f);
            if (flags & 0x40) {
                unsigned int v = func_001FAB88(&bits, 4);
                f78 = v & 7;
                f7C = (signed char)v < 0;
                f84 = (signed char)func_001FAB88(&bits, 6);
                f7D = (signed char)func_001FAB88(&bits, 1);
                f7E = (signed char)func_001FAB88(&bits, 1);
            }
            if (flags & 0x80) {
                f70 = func_001FAB88(&bits, 5);
                f74 = func_001FAB88(&bits, 3);
            }
            if (flags & 0x100)
                f88 = (short)func_001FAC80(&bits, 16);

            Skater_00234CF0* sk = func_00187B48(func_0022E040(game), i);
            if (sk && !(msg->m_flags & 3)) {
                History_00234CF0* h = sk->m_history;
                Frame_00234CF0* frames = h->m_frame;
                int prev;
                if (h->m_count > 0) {
                    prev = (h->m_count - 1) % 20;
                } else {
                    // First snapshot: seed frame 0 from the skater's current state.
                    prev = 0;
                    mat = sk->m_mat;
                    func_00100498(&mat, &ang);
                    for (int k = 0; k < 3; k++) {
                        if (k == 1)
                            frames->m_pos[1] = (short)(sk->m_pos.y * 4.0f);
                        else
                            frames->m_pos[k] = (short)(sk->m_pos.c[k] * 2.0f);
                        frames->m_rot[k] = ang.c[k];
                    }
                }
                int cur = sk->m_history->m_count % 20;

                if (!(flags & 1))
                    pos[0] = frames[prev].m_pos[0];
                if (!(flags & 2))
                    pos[1] = frames[prev].m_pos[1];
                if (!(flags & 4))
                    pos[2] = frames[prev].m_pos[2];
                for (int k = 0; k < 3; k++)
                    frames[cur].m_pos[k] = pos[k];
                posF.w = 0.0f;
                posF.x = pos[0] * 0.5f;
                posF.y = pos[1] * 0.25f;
                posF.z = pos[2] * 0.5f;

                if (!(flags & 8))
                    rot[0] = frames[prev].m_rot[0];
                if (!(flags & 0x10))
                    rot[1] = frames[prev].m_rot[1];
                if (!(flags & 0x20))
                    rot[2] = frames[prev].m_rot[2];
                for (int k = 0; k < 3; k++)
                    frames[cur].m_rot[k] = rot[k];

                func_00100200(&mat, rot[0], rot[1], rot[2]);
                m = mat;
                frames[cur].m_mat = m;
                frames[cur].m_posF = posF;
                ang = frames[cur].m_posF - frames[prev].m_posF;

                if (!(flags & 0x40)) {
                    f7E = frames[prev].m_7E;
                    f78 = frames[prev].m_78;
                    f7C = frames[prev].m_7C;
                    f84 = frames[prev].m_84;
                    f7D = frames[prev].m_7D;
                }
                if (!(flags & 0x80)) {
                    f70 = frames[prev].m_70;
                    f74 = frames[prev].m_74;
                }
                if (!(flags & 0x100))
                    f88 = frames[prev].m_88;
                frames[cur].m_70 = f70;
                frames[cur].m_74 = f74;
                frames[cur].m_88 = f88;
                frames[cur].m_78 = f78;
                frames[cur].m_7C = f7C;
                frames[cur].m_84 = f84;
                frames[cur].m_7D = f7D;
                frames[cur].m_7E = f7E;
                unsigned short wrap = frames[prev].m_wrap;
                frames[cur].m_wrap = wrap;
                if (time < frames[prev].m_time)
                    frames[cur].m_wrap = wrap + 1;
                frames[cur].m_time = time;
                sk->m_history->m_count++;
            }
        }
        i++;
    } while (i < 8);
    return 1;
}
