/* fuzzy: 94.6 */
/* blocked: the second extent's w is a float copy of the first's (lwc1 0x3C): `Vec(width, up, width, ext[3])` with
   a named ext gives the game's code shape (10 words) but ext and the operator- result swap stack slots (0x20/0x30),
   and fuzzy drops; temp/ref/union-TI forms and the directed search do not reorder the slots. */
struct Vec_001C5330 {
    float x, y, z, w;
    Vec_001C5330() {}
    Vec_001C5330(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    const float& operator[](int i) const { return (&x)[i]; }
};

static inline Vec_001C5330 operator-(const Vec_001C5330& a, const Vec_001C5330& b)
{
    return Vec_001C5330(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3]);
}

static inline Vec_001C5330 operator+(const Vec_001C5330& a, const Vec_001C5330& b)
{
    return Vec_001C5330(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3]);
}

struct Box_001C5330 {
    Vec_001C5330 mn;
    Vec_001C5330 mx;
};

struct Node_001C5330 {
    char m_pad[0x50];
    Vec_001C5330 m_50;
};

extern "C" void* func_001E5548(unsigned int key, int a);
extern "C" int func_001E7EB0(void* s, unsigned int key, float* out, int flag);
extern "C" Box_001C5330* func_00102340(Box_001C5330* b, const Vec_001C5330* mn, const Vec_001C5330* mx);
extern "C" void func_001DA948(void* p, Box_001C5330* b);
extern void* D_0038EE60;

static inline float Param_001C5330(unsigned int key)
{
    float f;
    func_001E7EB0(func_001E5548(0x6775E538, 0), key, &f, 1);
    return f;
}

static inline void InitBox_001C5330(Box_001C5330* b, const Vec_001C5330& mn, const Vec_001C5330& mx)
{
    func_00102340(b, &mn, &mx);
}

struct Obj_001C5330 {
    char m_pad0[0xC];
    Node_001C5330* m_C;
    char m_pad1[0xA10 - 0x10];
    void* m_A10;
    void Update();
};

void Obj_001C5330::Update()
{
    float width = Param_001C5330(0x99978D2B) + 1.0f;
    float up = Param_001C5330(0x9EA1974A) + 1.0f;
    float down = Param_001C5330(0xAF3E4251) + 1.0f;
    Box_001C5330 box;
    InitBox_001C5330(&box, m_C->m_50 - Vec_001C5330(width, down, width, 0.0f), m_C->m_50 + Vec_001C5330(width, up, width, 0.0f));
    func_001DA948(m_A10, &box);
    D_0038EE60 = m_A10;
}
