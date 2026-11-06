/* fuzzy: 71.7 */
typedef int qword_001C66D0 __attribute__((mode(TI)));

union Vec_001C66D0 {
    qword_001C66D0 q;
    struct {
        float x, y, z, w;
    } f;
};

struct Cam_001C66D0 {
    char m_pad[0x84];
    int m_active;
    char m_pad88[0x90 - 0x88];
    Vec_001C66D0 m_dir;
    float m_speed;
    void Set(float speed, const Vec_001C66D0& dir)
    {
        m_active = 1;
        m_speed = speed;
        m_dir = dir;
    }
};

extern "C" float func_00341068(float a);
extern "C" float func_00340F60(float a);

static inline void Rotate_001C66D0(Vec_001C66D0& v, float a)
{
    float s = func_00341068(a);
    float c = func_00340F60(a);
    float x = v.f.x;
    float z = v.f.z;
    v.f.x = c * x + s * z;
    v.f.z = -s * x + c * z;
}

struct Skater_001C66D0 {
    char m_pad[0x60];
    Vec_001C66D0 m60;
    char m_pad70[0x90 - 0x70];
    unsigned int m_mode;
    char m_pad94[0xA18 - 0x94];
    Cam_001C66D0* m_cam;
    char m_padA1C[0xC50 - 0xA1C];
    Vec_001C66D0 mC50;
    char m_padC60[0xC80 - 0xC60];
    int mC80;
    void UpdateCam();
};

void Skater_001C66D0::UpdateCam()
{
    switch (m_mode) {
    case 0x2D9815C3: {
        Vec_001C66D0 v = m60;
        Rotate_001C66D0(v, -0.95f);
        m_cam->Set(0.05f, v);
        break;
    }
    case 0x279B1F0B: {
        Vec_001C66D0 v = m60;
        Rotate_001C66D0(v, 0.95f);
        m_cam->Set(0.05f, v);
        break;
    }
    case 0x4194ECCA:
        m_cam->Set(0.05f, m60);
        break;
    case 0xC84243DA:
    case 0xAF5ABC82:
    case 0xFEC9DDED:
        m_cam->Set(0.05f, m60);
        break;
    case 0x4FE6069C:
        if (!mC80) {
            m_cam->Set(0.05f, m60);
        } else {
            m_cam->Set(0.05f, mC50);
        }
        break;
    default:
        m_cam->m_active = 0;
        break;
    }
}
