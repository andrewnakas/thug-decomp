typedef int qword_00255A28 __attribute__((mode(TI)));

struct Vec_00255A28 {
    union {
        qword_00255A28 q;
        struct {
            float x, y, z, w;
        } f;
    };
};

struct Mat_00255A28 {
    Vec_00255A28 row[4];
    void Identity()
    {
        row[0].f.x = 1.0f;
        row[0].f.y = 0.0f;
        row[0].f.z = 0.0f;
        row[0].f.w = 0.0f;
        row[1].f.x = 0.0f;
        row[1].f.y = 1.0f;
        row[1].f.z = 0.0f;
        row[1].f.w = 0.0f;
        row[2].f.x = 0.0f;
        row[2].f.y = 0.0f;
        row[2].f.z = 1.0f;
        row[2].f.w = 0.0f;
        row[3].f.x = 0.0f;
        row[3].f.y = 0.0f;
        row[3].f.z = 0.0f;
        row[3].f.w = 1.0f;
    }
};

extern "C" Mat_00255A28* func_001009C0(Mat_00255A28* m, float a);
extern "C" Mat_00255A28* func_00100890(Mat_00255A28* m, float a);
extern "C" void func_00323318(Mat_00255A28* d, const Mat_00255A28* a, Mat_00255A28* b);

struct Obj_00255A28 {
    char pad0[0x70];
    Mat_00255A28 m_mat;

    void SetRotation(float pitch, float yaw);
};

void Obj_00255A28::SetRotation(float pitch, float yaw)
{
    Mat_00255A28 tmp;
    m_mat.Identity();
    func_00323318(&m_mat, func_001009C0(&tmp, pitch), &m_mat);
    func_00323318(&m_mat, func_00100890(&tmp, yaw), &m_mat);
}
